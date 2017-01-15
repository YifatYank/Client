//
// Created by yifat on 31/12/16.
//

#include "Luxury.h"

void Luxury :: moveNext(){
    // If the cab is driving somewere
    if(this->getTrip() != NULL) {
        int index;
        Point * p;
        // If the cab's trip is not over.
        for(int index = 0; ((index < 2) && (!this->getTrip()->getTrip_path()->empty()));
            ++ index) {
            p = this->getTrip()->getTrip_path()->front();
            delete(p);
            this->getTrip()->getTrip_path()->pop_front();
            this->setLocation(*this->getTrip()->getTrip_path()->front());
            this->setKilometers(this->getKilometers() + 1);
        }
    }
}

void Luxury::updateTaarif(){
    // Two meters to shekels each meter.
    this->getTrip()->setTaarif(this->getTrip()->getTaarif() + 4);
}

Luxury::Luxury(int id, Manufacturer manufact, Color col) : Cab(id,manufact, col) {
    this->setTaarif(4);
    this->setSpeed(2);
}

Luxury::~Luxury() {

}

Luxury::Luxury() : Cab() {
    this->setTaarif(4);
    this->setSpeed(2);
}

BOOST_CLASS_EXPORT(Luxury);