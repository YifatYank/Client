cmake_minimum_required(VERSION 3.6)
project(Client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(BOOST_ROOT CACHE PATH "/usr/include/boost/")
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})

set(SOURCE_FILES main.cpp Cab.cpp Cab.h Point.cpp Point.h Trip.cpp Trip.h Driver.cpp Driver.h Passenger.cpp Passenger.h Enums.h Standart.cpp Standart.cpp Standart.h Luxury.cpp Luxury.h Socket.cpp Socket.h Udp.cpp Udp.h)
add_executable(Client ${SOURCE_FILES})
target_link_libraries(Client ${Boost_LIBRARIES})
