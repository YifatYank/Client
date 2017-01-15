//
// Created by yifat on 31/12/16.
//

#include "Standart.h"

void Standart::moveNext(){
    Point * p;
    // If the cab is driving somewere
    if(this->getTrip() != NULL) {
        // If the cab's trip is not over.
        if(!this->getTrip()->getTrip_path()->empty()) {
            p = this->getTrip()->getTrip_path()->front();
            delete(p);
            this->getTrip()->getTrip_path()->pop_front();
            p = this->getTrip()->getTrip_path()->front();
            this->setLocation(*p);
            this->setKilometers(this->getKilometers() + 1);
        }
    }
}

void Standart::updateTaarif() {
    if (this->getTrip() != NULL) {
        this->getTrip()->setTaarif(this->getTrip()->getTaarif() + 1);
    }
}

Standart::Standart(int id, Manufacturer manufact, Color col) : Cab(id,manufact, col) {
    this->setTaarif(1);
    this->setSpeed(1);
}

Standart::~Standart() {
}

Standart::Standart() : Cab(){
    this->setTaarif(1);
    this->setSpeed(1);
}

BOOST_CLASS_EXPORT(Standart);