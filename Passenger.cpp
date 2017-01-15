//
// Created by yifat on 30/12/16.
//

#include "Passenger.h"

int Passenger::calculateSatisfaction(){
    int grade = random() % 6;

    return grade;

}

Point * Passenger::getSP(){
    return this->source_point;
}

Point * Passenger::getDP(){
    return this->destination_point;
}

Passenger::Passenger(Point start, Point end) {
    this->source_point = new Point(start.getX(),start.getY());
    this->destination_point = new Point(end.getX(),end.getY());
}

Passenger::~Passenger() {
    delete(this->destination_point);
    delete(this->source_point);
}