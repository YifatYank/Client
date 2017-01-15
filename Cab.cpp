//
// Created by yifat on 01/12/16.
//

#include "Cab.h"


Cab::Cab(int id,Manufacturer manufacturer, Color color) {
    this->id = id;
    this->kilometers_passed = 0;
    this->taarif = 0;
    this->speed = 0;
    this->manufacturer = manufacturer;
    this->color = color;
    this->location = new Point(0,0);
    this->trip = NULL;
}
int Cab::getId() {
    return this->id;
}
int Cab::getTaarif() {
    return this->taarif;
}
Manufacturer Cab::getManufacturer() {
    return this->manufacturer;
}

Color Cab::getColor() {
    return this->color;
}

Point *Cab::getLocation() {
    return new Point (this->location->getX(), this->location->getY());
}

void Cab::setLocation(Point location) {
    delete(this->location);
    this->location = new Point (location.getX(), location.getY());
}


int Cab::getKilometers() {
    return this->kilometers_passed;
}

void Cab::setKilometers(int num) {
    this->kilometers_passed = num;
}

int Cab::getSpeed() {
    return this->speed;
}


Trip * Cab::getTrip() {
    return this->trip;
}

void Cab::setTrip(Trip * trip) {
    this->trip = trip;
}

int Cab::getTaarifForTrip() {
    return trip->getTaarif();
}

Cab::~Cab() {
    delete(this->location);
}

void Cab::setTaarif(int i) {
    this->taarif = i;
}

void Cab::setSpeed(int speed) {
    this->speed = speed;
}


