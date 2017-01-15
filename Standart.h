//
// Created by yifat on 31/12/16.
//

#ifndef CLIENT_STANDART_H
#define CLIENT_STANDART_H

#include "Cab.h"
#include "Enums.h"
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

using namespace std;
using namespace boost::archive;


class Standart : public ::Cab{
public:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & boost::serialization::base_object<Cab>(*this);
    }

    Standart();
    /**
 * Standart
 * constructor
 * @param col color
 * @param manufact manufacturer
*/
    Standart(int id, Manufacturer manufact, Color col);
    /**
 * Standart
 * destructor
*/
    virtual ~Standart();
    /**
 * moveNext
 * move to the next point
*/
    virtual void moveNext();
    /**
 * updateTaarif
 * updating the taarif
*/
    virtual void updateTaarif();
};


#endif //CLIENT_STANDART_H
