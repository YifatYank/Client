//
// Created by yifat on 30/12/16.
//

#ifndef CLIENT_DRIVER_H
#define CLIENT_DRIVER_H

#include "Point.h"
#include "Cab.h"
#include "Passenger.h"
#include <list>
#include "Enums.h"
using namespace std;
class Driver {
    // The driver is not responsible to the passanger and cab it holds.
private:
    int id;
    int age;
    int years_of_experience;
    int average_satisfaction;
    int num_of_customers;
    int sum_of_satisfaction;
    Marital_Status marital_status;
    bool hasCm;
    Cab * cab;

public:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & this->id;
        ar & this->age;
        ar & this->years_of_experience;
        ar & this->average_satisfaction;
        ar & this->num_of_customers;
        ar & this->sum_of_satisfaction;
        ar & this->marital_status;
        ar & this->hasCm;
        ar & this->cab;
    }

    Driver (): id(0) , age(0), marital_status(married) , years_of_experience(0) {}
    /**
 * Driver
 *constructor
 * @param age age
 * @param exp experience
 * @param id id
 * @param status marital status
*/
    Driver (int id, int age, Marital_Status status, int exp);
    /**
 * Driver
 *destructor
*/
    virtual ~Driver();
    int getID();
    /**
 * getAge
 *returns the age
*/
    int getAge();
    /**
 * setAge
 *sets the new age
 * @param newAge new age
*/
    void setAge(int newAge);
    /**
 * addReview
 *adding review
 * @param num the review
*/
    void addReview(int num);
    /**
 * getPlace
 *returns the place
 * @return point
*/
    Point * getPlace();
    /**
 * goToCm
 *gets the costumer's place and go there
 * @param place the place of the costumer
*/
    void goToCm(Point place);
    /**
 * calculatePath
 *calculate path
 * @param x x value
 * @param y y value
 * @return point
*/
    list<pPoint> * calculatePath(Point x,Point y);
    /**
 * isAvalable
 *returns ture if is occupied
 * @return false
*/
    bool isAvalable();

/**
 * setMlStatus
 *sets the marital status
 * @param ms marital status
*/
    void setMlStatus(Marital_Status ms);
    /**
 * getMlStatus
 *returns the marital status
 * @return widowed
*/
    enum Marital_Status getMlStatus();
    /**
 * setEx
 *returns the exprience
 * @param x
*/
    void setEx(int x);
    /**
 * getExp
 *returns ecprience
 * @return ex
*/
    int getExp();
    /**
 * getAvSa
 *returns the average satisfaction
 * @return av
*/
    int getAvSa();
    /* setCab.
    * sets cab.
    * @param cab
    */
    void setCab(Cab * cab);
    /* getCab.
    * returns the cab.
    * @return cab
    */
    Cab * getCab();
    /* setTrip.
    * sets the Trip.
    * @param trip
    */
    void setTrip(Trip * trip);
    /* drive
    * drive the cab to the next location
    * @returns true if the cab got to the ending point,false otherwise
    */
    bool drive();
};

typedef Driver * pDriver;


#endif //CLIENT_DRIVER_H
