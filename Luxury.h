//
// Created by yifat on 31/12/16.
//

#ifndef CLIENT_LUXURY_H
#define CLIENT_LUXURY_H

#include "Cab.h"
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

class Luxury : public ::Cab{
public:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & boost::serialization::base_object<Cab>(*this);
    }

    Luxury();
    /**
 * Luxury
 * @param col color
 * @param manufact manufacturer
*/
    Luxury(int id, Manufacturer manufact, Color col);
    /**
 * Luxury
 * destructor
*/
    virtual ~Luxury();

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

#endif //CLIENT_LUXURY_H
