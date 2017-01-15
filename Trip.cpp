//
// Created by yifat on 01/12/16.
//

#include "Trip.h"

Trip::Trip(int id,int taarif, Point start, Point end, int numOfPassangers, int startTime) {
    this->id = id;
    this->tarrif = taarif;
    this->starting_point = new Point(start.getX(),start.getY());
    this->ending_point = new Point(end.getX(),end.getY());
    this->number_of_passenger = numOfPassangers;
    this->total_meters_passed = 0;
    this->trip_path = new list<pPoint>();
    this->startTime = startTime;
}

Trip::~Trip() {
    Point * p;
    delete(this->ending_point);
    delete(this->starting_point);
    if(this->trip_path != NULL) {
        while (!this->trip_path->empty()) {
            p = this->trip_path->front();
            this->trip_path->pop_front();
            delete (p);
        }
        delete (this->trip_path);
    }
}


int Trip::getTMP(){
    return this->total_meters_passed;
}

void Trip::setTMP(int x){
    this->total_meters_passed = x;
}

Point * Trip:: getSP(){
    return this->starting_point;
}

Point * Trip::getEP(){
    return this->ending_point;
}

int Trip::getNOP(){
    return this->number_of_passenger;
}

void Trip::setNOP(int x){
    this->number_of_passenger = x;
}

int Trip:: getTaarif(){
    return this->tarrif;
}

void Trip::setTaarif(int x){
    this->tarrif = x;
}

list<pPoint> * Trip::getTrip_path(){
    return this->trip_path;
}

void Trip::setTrip_path(list<pPoint> * lst){
    if(lst != this->getTrip_path()) {
        delete(this->trip_path);
        this->trip_path = lst;
    }
}

int Trip::getID() {
    return this->id;
}

Trip::Trip(int id, int taarif, Point start, Point end, int numOfPassangers, list<pPoint> * path, int startTime) {
    this->id = id;
    this->tarrif = taarif;
    this->starting_point = new Point(start.getX(),start.getY());
    this->ending_point = new Point(end.getX(),end.getY());
    this->number_of_passenger = numOfPassangers;
    this->total_meters_passed = 0;
    this->trip_path = path;
    this->startTime = startTime;
}

int Trip::getStartTime() {
    return this->startTime;
}
