#include <string>
#include <iostream>
#include <iostream>
#include <stdio.h>
#include "Point.hpp"

using namespace std;
using namespace ariel;


// constructor - create a new Point
Point::Point(double xnum, double ynum): x_(xnum), y_(ynum) {}

// set x coordinate
void Point::setx(double newx)
{
    this->x_ = newx;
}

// set y coordinate
void Point::sety(double newy)
{
    this->y_ = newy;
}

// get x coordinate
double Point::getx()
{
    return this->x_;
}

// get y coordinate
double Point::gety()
{
    return this->y_;
}

// The closest point to the dest, within the given distance
Point Point::moveTowards(const Point &src, Point &dest, double dist)
{
    return dest;
}

// calculate the distance between the two points
double Point::distance(const Point &p) const
{
    return 0.0;
}

// prints the two coordinates
void Point::print() const
{
    cout << "(" << this->x_ << ", " << this->y_ << ")" << endl;
}

