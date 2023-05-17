#include <iostream>

using namespace std;

#pragma once

namespace ariel
{
    class Point
    {
        private:
            double x_;
            double y_;

        public:
            void setx(double newx); // set x coordinate
            void sety(double newy); // set y coordinate

        //public:
            Point(double xnum, double ynum); // constructor - create a new Point
            double getx(); // get x coordinate
            double gety(); // get y coordinate
            static Point moveTowards(const Point &src, Point &dest, double dist); // The closest point to the dest, within the given distance
            double distance(const Point &pnt) const; // calculate the distance between the two points
            void print() const; // prints the two coordinates
    };
}