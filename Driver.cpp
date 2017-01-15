#include "Driver.h"
using namespace std;


Driver::Driver(int id, int age, Marital_Status status, int exp) {
    this->id = id;
    this->age = age;
    this->marital_status = status;
    this->years_of_experience = exp;

    this->average_satisfaction = 0;
    this->hasCm = false;
    this->num_of_customers = 0;
    this->sum_of_satisfaction = 0;

    this->cab = NULL;
}


Driver::~Driver() {
}


int Driver::getAge() {
    return this->age;
}


void Driver::setAge(int newAge) {
    this->age = newAge;
}


Marital_Status Driver::getMlStatus() {
    return this->marital_status;
}

void Driver::setMlStatus(Marital_Status ms) {
    this->marital_status = ms;
}


int Driver::getExp() {
    return this->years_of_experience;
}


void Driver::setEx(int x) {
    this->years_of_experience = x;
}


Point * Driver::getPlace() {
    return this->cab->getLocation();
}


bool Driver::isAvalable() {
    if(this->cab == NULL) {
        return false;
    }
    if(this->cab->getTrip() != NULL) {
        return false;
    }
    return true;
}


void Driver::addReview(int num) {
    this->num_of_customers++;
    this->sum_of_satisfaction += num;
}


int Driver::getAvSa(){
    return (double)this->sum_of_satisfaction / (double)this->num_of_customers;
}


void Driver::goToCm(Point place) {

}

int Driver::getID() {
    return this->id;
}

void Driver::setCab(Cab * cab) {
    this->cab = cab;
}

Cab *Driver::getCab() {
    return this->cab;
}

void Driver::setTrip(Trip *trip) {
    if(this->isAvalable()) {
        this->cab->setTrip(trip);
    }
}

bool Driver::drive() {
    Point * p;
    if(this->cab != NULL) {
        if(this->cab->getTrip() != NULL) {
            // If its the time to move
            this->cab->moveNext();
            // If the driver reached the destination
            p = this->cab->getLocation();
            if (*p == *this->cab->getTrip()->getEP()) {
                this->cab->setTrip(NULL);
                // Returns that the driver has reached his destination.
                delete(p);
                return true;
            } else {
                // Returns that the driver has not reached his destination yet.
                delete(p);
                return false;
            }
        }
    }

    // In this case the driver is standing still, and there for there is no
    // destination he is driving to.
    return true;
}
