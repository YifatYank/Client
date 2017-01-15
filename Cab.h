//
// Created by yifat on 01/12/16.
//

#ifndef CLIENT_CAB_H
#define CLIENT_CAB_H

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
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/export.hpp>
#include "Trip.h"
#include "Point.h"
#include "Enums.h"
using namespace std;
class Cab {
private:
    int id;
    int kilometers_passed;
    int speed;
    double taarif;
    Manufacturer manufacturer;
    Color color;
    Point * location;
    Trip * trip;

public:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & this->id;
        ar & this->kilometers_passed;
        ar & this->speed;
        ar & this->taarif;
        ar & this->manufacturer;
        ar & this->color;
        ar & this->location;
        ar & this->trip;
    }

    Cab() : id(0) , manufacturer(HONDA), color(RED){}
    /**
 * Cab
 *constructor
 * @param id The cab's id.
 * @param manufacturer the cab's manufacturer
 * @param color the cab's color
*/
    Cab(int id,Manufacturer manufacturer, Color color);
    virtual ~Cab();
    /**
     * getId
     * @return The cab's id.
     */
    int getId();
    /**
    * updateTaarif
     * The function updates cab's ride taarif.
    * returns the taarif
    * @return Nothing
    */
    void virtual updateTaarif(){};
/**
 * moveNext
 * move the cab to the next place
*/
    void virtual moveNext(){};
    /**
 * getKilometers
 *returns the kilometers
 * @return kil
*/
    int getKilometers();
    /**
 *setKilometers
 *sets the number of kilometers
 * @param num number of kilometers
*/
    void setKilometers(int num);
    /**
 * getSpeed
 *returns speed
 * @return speed
*/
    int getSpeed();
/**
 * getLocation
 *returns the location, the functions return a new instance of point.
 * @return location
*/
    Point * getLocation();
    /**
 * setLocation
 * sets the location of the cab
 * @param location a location on the grid
*/
    void setLocation(Point location);
    /**
    * getColor
    * @return The ca's color.
    */
    Color getColor();
    /**
    * getManufacturer
    * The function returns the manufacturer
    * @return The cab's manufacturer
    */
    Manufacturer getManufacturer();
    /**
 * getTaarif
 * returns the taarif of the cab
 * @return taarif
*/
    int getTaarif();
    /**
 * getTrip
 *returns trip pointer
 * @return ptr
*/
    Trip * getTrip();
    /**
 *setTrip
 *sets the trip
 * @param trip a trip
*/
    void setTrip(Trip * trp);
    /**
 * getTaarifForTrip
 *returns taarif for a trip
 * @return taarif
*/
    int getTaarifForTrip();

    /** setTaarif
     * Sets the cab taarif
     * @param i
     */
    void setTaarif(int i);

    /**
     * setSpeed
     * @param speed The cab's speed.
     */
    void setSpeed(int speed);
};
BOOST_SERIALIZATION_ASSUME_ABSTRACT(Cab);
typedef Cab * pCab;
#endif //CLIENT_CAB_H