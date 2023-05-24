#include <string>
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
Point Point::moveTowards(Point &src, Point &dest, double dist)
{
    if (dist < 0) throw invalid_argument("minus");

    if(src.distance(dest) <= dist)
        return dest;
    
    // calculate the שיפוע
    double m = (src.gety() - dest.gety())/(src.getx() - dest.getx());
    double n = src.gety() - m*src.getx();

    // y = mx+n

    /* 
        if let x1 = src, x2 = dest, x0 = to find:
        (x0 -x1)^2 + (y0 - y1)^2 = dist^2
        and the caculate below is the math calculate:
    */

    double a = 1 + (m*m);
    double b = (-2*src.getx()) + (2*m*n) +(-2*src.gety()*m);
    double c = (src.getx()*src.getx()) + (n*n) + (-2*src.gety()*n) + (src.gety()*src.gety()) - (dist*dist);

    //double to_sqrt = (b*b) - (4*a*c);

    // I use : (-b + sqrt ( b*b - 4 * a *c)) / 2*a

    double x1 = (-b + mysqrt((b*b)-(4*a*c)))/(2*a);
    double x2 = (-b - mysqrt((b*b)-(4*a*c)))/(2*a);

    double y1 = (m*x1) + n;
    double y2 = (m*x2) + n;

    Point p1(x1, y1), p2(x2, y2);

    if(dest.distance(p1) <= dest.distance(p2))
        return p1;
    else return p2;
}

// calculate the distance between the two points
double Point::distance(Point p)
{
    double disx = this->x_ - p.getx();
    double disy = this->y_ - p.gety();

    disx = disx * disx;
    disy = disy * disy;
    
    double dis = disx + disy;
    /*
    if(dis != 0 && dis != 1) 
    {
        double result = dis / 2.0;
        double previous = 0.0;

        while (result != previous)
        {
            previous = result;
            result = 0.5 * (result + (dis / result));
        }

        dis = result;
    }
    */

    //return dis;

    return mysqrt(dis);
}

// prints the two coordinates
void Point::print()
{
    cout << "(" << this->x_ << ", " << this->y_ << ")" << endl;
}



double ariel::mysqrt(double number)
{
    if (number < 0) throw __EXCEPTIONS;

    else if(number != 0 && number != 1) 
    {
        double result = number / 2.0;
        double previous = 0.0;

        while (result != previous)
        {
            previous = result;
            result = 0.5 * (result + (number / result));
        }

        number = result;
    }

    return number;
}

