//
// Created by yifat on 30/12/16.
//

#ifndef CLIENT_PASSENGER_H
#define CLIENT_PASSENGER_H

#include "Point.h"
// The passanger responsible for : source point, destination point.
class Passenger {
private:
    Point * source_point;
    Point * destination_point;
public:
    /**
 * Passenger
 *constructor
 * @param end ending point
 * @param start starting point
*/
    Passenger(Point  start, Point end);
    /**
 * Passenger
 * destructor
*/
    ~Passenger();
    /**
 * calculateSatisfaction
 *calculates satisfaction
 * @return s
*/
    int calculateSatisfaction();
    /**
 * getSP
 *returns the source point
 * @return sp
*/
    Point  * getSP();
    /**
 * getDP
 *returns the destination point
 * @return ds
*/
    Point * getDP();
};

#endif //CLIENT_PASSENGER_H
