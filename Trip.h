//
// Created by yifat on 30/12/16.
//

#ifndef CLIENT_TRIP_H
#define CLIENT_TRIP_H

#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
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
#include <boost/serialization/list.hpp>

using namespace boost::archive;
using namespace std;
#include "Point.h"
#include <list>

class Trip {
// The trip responsible for its start point and end point.
private:
    int id;
    int total_meters_passed;
    int number_of_passenger;
    int tarrif;
    int startTime;
    Point * starting_point;
    Point * ending_point;
    list<pPoint>* trip_path;
public:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & this->id;
        ar & this->total_meters_passed;
        ar & this->number_of_passenger;
        ar & this->tarrif;
        ar & this->starting_point;
        ar & this->ending_point;
        ar & this->trip_path;
        ar & this->startTime;
    }

    Trip() : id(0) , tarrif(0), starting_point(NULL) , ending_point(NULL), number_of_passenger(0) , trip_path(NULL)
            , startTime(0){}

    /**
 * Trip
 * constructor
 * @param taarif taarif
 * @param start striting point
 * @param end ending point
 * @param numOfPassangers num of passengers
*/
    Trip(int id,int taarif, Point start, Point end, int numOfPassangers, int startTime);


    Trip(int id,int taarif, Point start, Point end, int numOfPassangers, list<pPoint> * path, int startTime);


    /**
   * Trip
   * destructor
  */
    ~Trip();
    int getID();
    /**
 * getTMP
 * returns the total meters passed
 * @return tmp
*/
    int getTMP();
    /**
 * setTMP
 * sets total meters passed
 * @param x total meters passed
*/
    void setTMP(int x);
    /**
 * getSP
 * returns the source point
 * @return sp
*/
    Point * getSP();
    /**
 * getEP
 * returns the ending point
 * @return ep
*/
    Point * getEP();
    /**
 * getNOP
 * returns the number of passengers
 * @return nop
*/
    int getNOP();
    /**
 * setNOP
 * sets the number of passengers
 * @param x num pf passengers
*/
    void setNOP(int x);
    /**
 * getTaarif
 * returns the taarif
 * @return t taarif
*/
    int getTaarif();
    /**
 * setTaarif
 * sets the taarif
 * @param x taarif
*/
    void setTaarif(int x);
    /**
 * getTrip_path
 * returns the trip path
 * @return point list of points
*/
    list<pPoint> * getTrip_path();
    /**
 * setTrip_path
 * sets the trip path
 * @param lst list of points
*/
    void setTrip_path(list<pPoint> * lst);

    int getStartTime();
};

typedef Trip * pTrip;
#endif