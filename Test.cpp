#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"
using namespace ariel;

#include "doctest.h"


// checking that all functions are propriety
TEST_CASE("TEST 1 - WITHOUT ERROR")
{
    float f = 0.5;
    Fraction a(5,3);
    Fraction b;
    
    CHECK_NOTHROW(Fraction a(5,3)); //true
    CHECK_NOTHROW(Fraction b);      //true
    CHECK_NOTHROW(Fraction c(0,0)); //true

    CHECK_NOTHROW(a+b); //true
    CHECK_NOTHROW(a+f); //true
    CHECK_NOTHROW(f+a); //true

    CHECK_NOTHROW(a-b); //true
    CHECK_NOTHROW(a-f); //true
    CHECK_NOTHROW(f-a); //true

    CHECK_NOTHROW(a*b); //true
    CHECK_NOTHROW(a*f); //true
    CHECK_NOTHROW(f*a); //true

    CHECK_NOTHROW(a/b); //true
    CHECK_NOTHROW(a/f); //true
    CHECK_NOTHROW(f/a); //true

    CHECK_NOTHROW(a++); //true
    CHECK_NOTHROW(++a); //true

    CHECK_NOTHROW(a--); //true
    CHECK_NOTHROW(--a); //true    
}


// validity of the comparisons
TEST_CASE("TEST 1 - VALIDITY COMPARISONS")
{
    float f = 0.5;
    Fraction a(1,2);
    Fraction b(3,4);

    CHECK((f+a == 1) == true);
    CHECK((1 == a+f) == true);
    CHECK((a+b == a+0.75) == true);

    CHECK((f-a <= 0) == true);
    CHECK((0 <= a-f) == true);
    CHECK((a-f <= a) == true);

    CHECK((f-a < 1) == true);
    CHECK((0 < a) == true);
    CHECK((a-f < a) == true);

    CHECK((f-a >= 0) == true);
    CHECK((0 >= a-f) == true);
    CHECK((a >= a-f) == true);

    CHECK((0.5 > f-a) == true);
    CHECK((a > 0) == true);
    CHECK((a > a-f) == true);
}


// correct calculation - arithmetic
TEST_CASE("TEST 1 - CORRECT CALCULATION")
{
    float f = 0.5;
    Fraction a(1,2);
    Fraction b(3,4);
    Fraction c(0,25);

    CHECK(f+a == 1);
    CHECK(a+f == 1);
    CHECK(a+b == 1.25);

    CHECK(f-a == 0);
    CHECK(a-f == 0);
    CHECK(a-b == -0.25);
    
    CHECK(f*a == 0.25);
    CHECK(a*f == 0.25);
    CHECK(a*b == 0.375);
   
    CHECK(f/a == 1);
    CHECK(a/f == 1);
    CHECK(a/c == 2);

    CHECK(a++ == 1.5);
    CHECK(++a == 1.5);
    
    CHECK(a-- == -0.5);
    CHECK(--a == -0.5);
}

// reducing fractures
TEST_CASE("TEST 1 - REDUCING FRACTURES")
{
    Fraction a(1,4);
    Fraction b(2,8);
    Fraction c(0,0);
    Fraction d(1,2);
    Fraction e(0,2);

    // no error in this function
    CHECK_NOTHROW(b.reduce());
    CHECK_NOTHROW(c.reduce());

    CHECK(b.reduce() == a);
    CHECK((a==b) == true);
    CHECK((a+b == d) == true);
    CHECK((2*b == d) == true);

    CHECK((e.reduce() == c) == true); // reduce of zero
}

// division by 0
TEST_CASE("TEST 1 - DIVISION BY ZERO")
{
    Fraction a(1,4);
    Fraction b(0,8);
    Fraction c(0,0);

    CHECK_THROWS(Fraction (1,0));
    CHECK_THROWS(a/0); 
    CHECK_THROWS(a/b); 
    CHECK_THROWS(a/c);
    CHECK_THROWS(5/c); 
}

