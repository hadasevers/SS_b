#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Fraction.hpp"
using namespace ariel;
using namespace std;

namespace ariel{

    // create a new Fraction
    Fraction::Fraction(int num, int den): numer_(num), denom_(den) {}

    // "defult" constructor
    Fraction::Fraction(): Fraction(1, 1) {}


    // add two fractions
    Fraction& Fraction::operator + (const Fraction& other)
    {
        return *this;
    }

    // add fraction and float
    Fraction operator + (const Fraction& frc, float flt)
    {
        return frc;
    }

    // add float and fraction
    Fraction operator + (float flt, const Fraction& frc)
    {
        return frc;
    }


    // subtract two fractions
    Fraction& Fraction::operator - (const Fraction& other)
    {
        return *this;
    }

    // subtract fraction and float
    Fraction operator - (const Fraction& frc, float flt)
    {
        return frc;
    }

    // subtract float and fraction
    Fraction operator - (float flt, const Fraction& frc)
    {
        return frc;
    }


    // multiply two fractions
    Fraction& Fraction::operator * (const Fraction& other)
    {
        return *this;
    }

    // multiply fraction and float
    Fraction operator * (const Fraction& frc, float flt)
    {
        return frc;
    }

    // multiply float and fraction
    Fraction operator * (float flt, const Fraction& frc)
    {
        return frc;
    }


    // divide two fractions
    Fraction& Fraction::operator / (const Fraction& other)
    {
        return *this;
    }

    // divide fraction and float
    Fraction operator / (const Fraction& frc, float flt)
    {
        return frc;
    }

    // divide float and fraction
    Fraction operator / (float flt, const Fraction& frc)
    {
        return frc;
    }


    // compare two fractions
    //bool Fraction::operator == (const Fraction& other)
    bool operator == (const Fraction& frc, const Fraction& other)
    {
        return true;
    }

    // compare fraction and float
    bool operator == (const Fraction& frc, float flt)
    {
        return true;
    }

    // compare float and fraction
    bool operator == (float flt, const Fraction& frc)
    {
        return true;
    }


    // check who is the bigger between two fractions
    bool Fraction::operator > (const Fraction& other)
    {
        return true;
    }

    // check who is the bigger between fraction and float
    bool operator > (const Fraction& frc, float flt)
    {
        return true;
    }

    // check who is the bigger between float and fraction
    bool operator > (float flt, const Fraction& frc)
    {
        return true;
    }


    // check who is maybe the bigger between two fractions
    bool Fraction::operator >= (const Fraction& other)
    {
        return true;
    }

    // check who is maybe the bigger between fraction and float
    bool operator >= (const Fraction& frc, float flt)
    {
        return true;
    }

    // check who is maybe the bigger between float and fraction
    bool operator >= (float flt, const Fraction& frc)
    {
        return true;
    }


    // check who is the bigger between two fractions
    bool Fraction::operator < (const Fraction& other)
    {
        return true;
    }

    // check who is the bigger between fraction and float
    bool operator < (const Fraction& frc, float flt)
    {
        return true;
    }

    // check who is the bigger between float and fraction
    bool operator < (float flt, const Fraction& frc)
    {
        return true;
    }


    // check who is maybe the bigger between two fractions
    bool Fraction::operator <= (const Fraction& other)
    {
        return true;
    }

    // check who is maybe the bigger between fraction and float
    bool operator <= (const Fraction& frc, float flt)
    {
        return true;
    }

    // check who is maybe the bigger between float and fraction
    bool operator <= (float flt, const Fraction& frc)
    {
        return true;
    }


    // adds 1 to the fraction . postfix (n++).
    const Fraction Fraction::operator ++ (int n)
    {
        return *this;
    }


    // adds 1 to the fraction. prefix (++n).
    Fraction& Fraction::operator ++ ()
    {
        return *this;
    }


    // substracts 1 to the fraction. postfix (n--).
    const Fraction Fraction::operator -- (int n)
    {
        return *this;
    }

    // substracts 1 to the fraction. prefix (--n).
    Fraction& Fraction::operator -- ()
    {
        return *this;
    }


    // print a fraction to an output
    ostream& operator << (ostream& output, const Fraction& other)
    {
        //output << other.numer_ << "/" << other.denom_ << endl;
        return output;
    }


    // read a fraction from an input
    istream& operator >> (istream& input, Fraction& other)
    {
        //input >> other.numer_ >> endl;
        return input;
    }


    // return the fraction reduced
    Fraction Fraction::reduce()
    {
        return *this;
    }

};