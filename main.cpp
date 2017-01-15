#include <iostream>
#include "Enums.h"
#include "Driver.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include "Socket.h"
#include "Udp.h"

using namespace std;
using namespace boost::archive;
std::stringstream ss;

int stringToInt(string str);
//void send(string str);
//char * recive();
string serialize(Driver * driver);
string serialize(Point * point);
Cab * desrializeCab(char * str);
Trip * deserializeTrip(char * str);

int main(int argc, char* argv[]) {
    int id, experience, vehicleId, age;
    //int currTime;
    char status, dummy;
    bool endOfProg = false;
    bool reachedEnd;
    int port;
    Marital_Status ms;
    string serialized;
    char emptyMassage[] = "0";
    char * messageRecived = new char[2048];
    list<pTrip> * tripList = new list<pTrip>();
    Driver *driver;
    Cab * cab;
    Trip * trp;
    Point * tempPoint;
    Udp * udp;

    if(argc != 3) {
        delete [](messageRecived);
        delete(tripList);
        return 0;
    }

    port = stringToInt(argv[2]);
    // Initieize the comunication.
    udp = new Udp(false,port);
    udp->initialize();
    // Gets the driver and creates it.
    cin >> id >> dummy >> age >> dummy >> status >> dummy >> experience >> dummy
        >> vehicleId;

    if (status == 'M') { ms = married; }
    else if (status == 'W') { ms = widowed; }
    else if (status == 'S') { ms = single; }
    else if (status == 'D') { ms = divorced; }

    driver = new Driver(id, age, ms, experience);
    serialized = serialize(driver);

    // Send the driver to the server
    udp->sendData(serialized);

    // Waite for the sever tell that it got the massage.
     udp->reciveData(messageRecived,2048);

    // Send the requested vehicleId to the server
    serialized = std::to_string(vehicleId);
    udp->sendData(serialized);

    // Recive the cab
    udp->reciveData(messageRecived, 2048);
    cab = desrializeCab(messageRecived);
    driver->setCab(cab);
    // Send the server that the client got the message
    udp->sendData(emptyMassage);

    // While this is not the end of the program.
    while(!endOfProg) {
        // Waite for the trip
        udp->reciveData(messageRecived,2048);
        if (strcmp(messageRecived, "bye") == 0) {
            endOfProg = true;
        } else if(strcmp(messageRecived, "location") == 0){
            tempPoint = driver->getPlace();
            serialized = serialize(tempPoint);
            udp->sendData(serialized);
            delete(tempPoint);
        } else if(strcmp(messageRecived, "go") == 0) {
            serialized = "no";
            // Send the server if the driver reached his destination.
            udp->sendData(serialized);
        }
        else {
            // Means that this is a trip.
            trp = deserializeTrip(messageRecived);
            driver->setTrip(trp);

            while (!driver->isAvalable()) {
                // Waite for 'go'
                udp->reciveData(messageRecived, 2048);
                if (strcmp(messageRecived, "go") == 0) {
                    reachedEnd = driver->drive();

                    if (reachedEnd) {
                        serialized = "yes";
                    } else {
                        serialized = "no";
                    }

                    // Send the server if the driver reached his destination.
                    udp->sendData(serialized);
                } else if(strcmp(messageRecived, "location") == 0){
                    tempPoint = driver->getPlace();
                    serialized = serialize(tempPoint);
                    udp->sendData(serialized);
                    delete(tempPoint);
                } else if (strcmp(messageRecived, "bye") == 0) {
                    endOfProg = true;
                    driver->setTrip(NULL);
                }
            }
            tripList->push_front(trp);
        }
    }


    while(!tripList->empty()) {
        trp = tripList->front();
        tripList->pop_front();
        delete(trp);
    }

    delete(tripList);
    delete(driver);
    delete(cab);
    delete(udp);
    delete[](messageRecived);
    return 0;
}

void send(string str) {
    const char * ip_address = "127.0.0.1";
    const int port_no = 5555;
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    int size_data = str.size();

    int sent_bytes = sendto(sock, str.c_str(), size_data, 0, (struct sockaddr *) &sin, sizeof(sin));
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }
    close(sock);
}
char * recive() {
    const char* ip_address = "127.0.0.1";
    const int port_no = 5555;
    string str;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    char * buffer = new char[4096];
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    if (bytes < 0) {
        perror("error reading from socket");
    }

    close(sock);

    return buffer;
}

string serialize(Driver * driver) {
    int index;
    int lenth;

    std::string serial_str;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);

    oa << driver;
    s.flush();

    //lenth = serial_str.length();
    //for(index = 0;index < lenth - 1; ++ index) {
    //    if(serial_str.at(index) == '\0') {
    //        serial_str.replace(index,1,"|");
    //    }
    //}

    //serial_str.replace('\0','|');
    return serial_str;
}
string serialize(Point * point) {
    std::string serial_str;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive oa(s);

    oa << point;
    s.flush();

    return serial_str;
}
Cab * desrializeCab(char * str){
    Cab * cab;
    boost::iostreams::basic_array_source<char> device(str, 2048);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> cab;

    return cab;
}
Trip * deserializeTrip(char * str){
    Trip * trp;

    boost::iostreams::basic_array_source<char> device(str, 2048);
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::binary_iarchive ia(s2);
    ia >> trp;

    return trp;
}
int stringToInt(string str){
    char ch;
    int index, num = 0, digit;

    for(index = 0; index < str.size(); ++index) {
        ch = str[index];
        digit = ch - 48;
        num = num * 10 + digit;
    }
    return num;
}