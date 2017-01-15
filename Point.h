//
// Created by yifat on 30/12/16.
//

#ifndef CLIENT_POINT_H
#define CLIENT_POINT_H

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

using namespace std;
using namespace boost::archive;

using namespace std;
class Point{
private:
    int xCoord;
    int yCoord;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & xCoord;
        ar & yCoord;
    }

public:

    Point() : xCoord(0), yCoord(0) {}

    /* Point.
    * <p>
    * constructor.
    * @param x x's position
    * @param y y's position
    */
    Point(int x, int y);
    /* getX.
    * <p>
    * returns the x's value.
    * @return xCoord
    */
    int getX();
    /* setX.
    * <p>
    * sets the x's value.
    * @param x
    */
    void setX(int x);
    /* getY.
    * <p>
    * returns the y's value.
    * @return yCoord
    */
    int getY();
    /* setY.
    * <p>
    * sets the y's value.
    * @param yCoord
    */
    void setY(int y);
    /* getString
    * <p>
    * returns a string of points.
    * @return str a string
    */
    string * getString();
    /* operator==.
    * <p>
    * return true if the points are equal.
    * @param p a point
    * @return true\false
    */
    bool operator==(Point p);
    /* intToString.
    * <p>
    * function that does casting from int to string.
    * @param num a number to cast
    * @return str the number as a string
    */
    string * intToString(int num);
};

typedef Point * pPoint;

#endif //CLIENT_POINT_H
