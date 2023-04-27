#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#pragma once

namespace ariel
{
    class Fraction
    {
        private:
        int numer_;  // numerator
        int denom_;  // denominator

        public:
        Fraction(int num, int den);   // create a new Fraction
        Fraction();  // "defult" constructor

        Fraction& operator + (const Fraction& other); // add two fractions
        friend Fraction operator + (const Fraction& frc, float flt); // add fraction and float
        friend Fraction operator + (float flt, const Fraction& frc); // add float and fraction

        Fraction& operator - (const Fraction& other); // subtract two fractions
        friend Fraction operator - (const Fraction& frc, float flt); // subtract fraction and float
        friend Fraction operator - (float flt, const Fraction& frc); // subtract float and fraction

        Fraction& operator * (const Fraction& other); // multiply two fractions
        friend Fraction operator * (const Fraction& frc, float flt); // multiply fraction and float
        friend Fraction operator * (float flt, const Fraction& frc); // multiply float and fraction

        Fraction& operator / (const Fraction& other); // divide two fractions
        friend Fraction operator / (const Fraction& frc, float flt); // divide fraction and float
        friend Fraction operator / (float flt, const Fraction& frc); // divide float and fraction

        friend bool operator == (const Fraction& frc, const Fraction& other); // compare two fractions
        friend bool operator == (const Fraction& frc, float flt); // compare fraction and float
        friend bool operator == (float flt, const Fraction& frc); // compare float and fraction

        bool operator > (const Fraction& other);  // check who is the bigger between two fractions
        friend bool operator > (const Fraction& frc, float flt);  // check who is the bigger between fraction and float
        friend bool operator > (float flt, const Fraction& frc);  // check who is the bigger between float and fraction

        bool operator >= (const Fraction& other); // check who is maybe the bigger between two fractions
        friend bool operator >= (const Fraction& frc, float flt); // check who is maybe the bigger between fraction and float
        friend bool operator >= (float flt, const Fraction& frc); // check who is maybe the bigger between float and fraction

        bool operator < (const Fraction& other);  // check who is the bigger between two fractions
        friend bool operator < (const Fraction& frc, float flt);  // check who is the bigger between fraction and float
        friend bool operator < (float flt, const Fraction& frc);  // check who is the bigger between float and fraction

        bool operator <= (const Fraction& other); // check who is maybe the bigger between two fractions
        friend bool operator <= (const Fraction& frc, float flt); // check who is maybe the bigger between fraction and float
        friend bool operator <= (float flt, const Fraction& frc); // check who is maybe the bigger between float and fraction

        const Fraction operator ++ (int n);  // adds 1 to the fraction . postfix (n++).

        Fraction& operator ++ (); // adds 1 to the fraction. prefix (++n).

        const Fraction operator -- (int n);  // substracts 1 to the fraction. postfix (n--).

        Fraction& operator -- (); // substracts 1 to the fraction. prefix (--n).
        
        friend ostream& operator << (ostream& output, const Fraction& other); // print a fraction to an output
        friend istream& operator >> (istream& input, Fraction& other); // read a fraction from an input
        Fraction reduce(); // return the fraction reduced
    };
}


