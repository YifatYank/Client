//
// Created by yifat on 30/12/16.
//
#include "Point.h"

Point::Point(int x, int y)
{
    xCoord = x;
    yCoord = y;
}

int Point::getX()
{
    return xCoord;
}

void Point::setX(int x) {
    xCoord = x;
}

int Point::getY()
{
    return yCoord;
}

void Point::setY(int y) {
    yCoord = y;
}

string * Point::getString() {
    string *str = new string();
    int num;
    string * tempsStr;
    str->append("(");
    tempsStr = intToString(this->getX());
    str->append(*tempsStr);
    delete(tempsStr);
    str->append(",");
    tempsStr = intToString(this->getY());
    str->append(*tempsStr);
    delete(tempsStr);
    str->append(")");

    return  str;
}

bool Point::operator==(Point p) {
    if(this->getX() == p.getX() && (this->getY() == p.getY())) {
        return true;
    }
    return false;
}

string * Point::intToString(int num){
    char ch;
    string * str = new string();

    if(num == 0) {
        str->push_back('0');
    }


    while(num != 0) {
        ch = num % 10 + 48;
        str->push_back(ch);
        num = num / 10;
    }
    return str;
}