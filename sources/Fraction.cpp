#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cmath>
#include <algorithm> // For __gcd; taken from the internet
#include "Fraction.hpp"
using namespace ariel;
using namespace std;

namespace ariel{

    // max int and min int for check overflow
    int max_int = std::numeric_limits<int>::max();
    int min_int = std::numeric_limits<int>::min();

    // create a new Fraction
    Fraction::Fraction(int num, int den): numer_(num), denom_(den) 
    {
        if (den == 0) throw invalid_argument("invalid_argument");
    }

    // defult constructor
    Fraction::Fraction() : Fraction(1, 1){}

    // float constructor
    Fraction::Fraction(float num) : Fraction((num*1000), 1000){}
    

    int Fraction::getNumerator() const
    {
        return this->numer_;
    }


    int Fraction::getDenominator() const
    {
        return this->denom_;
    }


    // add two fractions
    Fraction Fraction::operator + (const Fraction& other) const
    {
        int numer = 0, denom = 1;

        // if the denominator is same - add the numerator
        if (this->denom_ == other.getDenominator()) 
        {
            denom = this->denom_;
            numer = this->numer_ + other.getNumerator();
            
            // check overflow
            if ( __builtin_sadd_overflow(this->numer_, other.getNumerator(), &numer) == true)
                throw overflow_error("overflow_error");

        }
        // if they different - do all the calculate
        else
        {
            denom = this->denom_ *other.getDenominator();
            numer = (this->numer_*other.getDenominator()) + (other.getNumerator()*this->denom_);

            int result;
            if ((__builtin_smul_overflow(this->denom_, other.getDenominator(), &denom) == true) ||
                (__builtin_smul_overflow(this->numer_, other.getDenominator(), &result) == true) ||
                (__builtin_smul_overflow(other.getNumerator(), this->denom_, &result) == true) ||
                (__builtin_sadd_overflow((this->numer_*other.getDenominator()), (other.getNumerator()*this->denom_), &result) == true))
            {
                throw overflow_error("overflow_error"); 
            }
        }
        
        Fraction f(numer, denom);
        return f.reduce();
    }


    // add fraction and float
    Fraction operator + (const Fraction& frc, float flt) 
    {
        Fraction f(flt);
        return frc+f;
    }

    // add float and fraction
    Fraction operator + (float flt, const Fraction& frc) 
    {
        Fraction f(flt);
        return frc+f;
    }


    // subtract two fractions
    Fraction Fraction::operator - (const Fraction& other) const
    {
        int numer = 0, denom = 1;

        if (this->denom_ == other.getDenominator()) 
        {
            denom = this->denom_;
            numer = this->numer_ - other.getNumerator();

            if ( __builtin_ssub_overflow(this->numer_, other.getNumerator(), &numer) == true)
                throw overflow_error("overflow_error");
        }
        else
        {
            denom = this->denom_ *other.getDenominator();
            numer = (this->numer_*other.getDenominator()) - (other.getNumerator()*this->denom_);

            int result;
            if ((__builtin_smul_overflow(this->denom_, other.getDenominator(), &denom) == true) ||
                (__builtin_smul_overflow(this->numer_, other.getDenominator(), &result) == true) ||
                (__builtin_smul_overflow(other.getNumerator(), this->denom_, &result) == true) ||
                (__builtin_ssub_overflow((this->numer_*other.getDenominator()), (other.getNumerator()*this->denom_), &result) == true))
            {
                throw overflow_error("overflow_error"); 
            }
        }

        Fraction f (numer, denom);
        return f.reduce();
    }

    // subtract fraction and float
    Fraction operator - (const Fraction& frc, float flt) 
    {
        Fraction f(flt);
        return frc-f;
    }

    // subtract float and fraction
    Fraction operator - (float flt, const Fraction& frc) 
    {
        Fraction f(flt);
        return f-frc;
    }


    // multiply two fractions
    Fraction Fraction::operator * (const Fraction& other) const
    {
        int numer = 0, denom = 1;

        Fraction myf (this->numer_, this->denom_);
        Fraction othf (other.numer_, other.denom_);

        myf.reduce();
        othf.reduce();

        denom = myf.getDenominator() *othf.getDenominator();
        numer = myf.getNumerator()*othf.getNumerator();

        if  ((__builtin_smul_overflow(myf.getDenominator(), othf.getDenominator(), &denom) == true) ||
             (__builtin_smul_overflow( myf.getNumerator(), othf.getNumerator(), &numer) == true))
        {
            throw overflow_error("overflow_error");
        }

        Fraction f(numer, denom);        
        return f.reduce();
    }

    // multiply fraction and float
    Fraction operator * (const Fraction& frc, float flt) 
    {
        Fraction f(flt);
        return frc*f;
    }

    // multiply float and fraction
    Fraction operator * (float flt, const Fraction& frc) 
    {
        Fraction f(flt);
        f.reduce();
        return f*frc;
    }


    // divide two fractions
    Fraction Fraction::operator / (const Fraction& other) const
    {
        if (other == 0) throw runtime_error("runtime_error");
        else if (*this == 0) return Fraction(0,1);
        else
        {
            Fraction f(this->numer_, this->denom_);
            Fraction d(other.getDenominator(), other.getNumerator());
            return f*d;
        }
    }

    // divide fraction and float
    Fraction operator / (const Fraction& frc, float flt) 
    {
        if (flt == 0) throw runtime_error("runtime_error");
        else
        {
            Fraction f(flt);
            return frc/f;
        }
    }

    // divide float and fraction
    Fraction operator / (float flt, const Fraction& frc) 
    {
        if (frc == 0) throw runtime_error("runtime_error");
        else
        {
            Fraction f(flt);
            return f/frc;
        }
    }


    // compare two fractions
    bool operator == (const Fraction& frc, const Fraction& other) 
    {
        float Frc = (float)frc.getNumerator()/frc.getDenominator();
        float Other = (float)other.getNumerator()/other.getDenominator();
        if (Frc==Other) return true;
        else return false;
    }

    // compare fraction and float
    bool operator == (const Fraction& frc, float flt) 
    {
        float Frc = (float)frc.getNumerator()/frc.getDenominator();
        if (Frc==flt) return true;
        else return false;
    }

    // compare float and fraction
    bool operator == (float flt, const Fraction& frc) 
    {
        float Frc = (float)frc.getNumerator()/frc.getDenominator();
        if (flt==Frc) return true;
        else return false;
    }


    // check who is the bigger between two fractions
    bool Fraction::operator > (const Fraction& other) const
    {
        float Frc = (float)this->numer_/this->denom_;
        float Other = (float)other.getNumerator()/other.getDenominator();
        if (Frc>Other) return true;
        else return false;
    }

    // check who is the bigger between fraction and float
    bool operator > (const Fraction& frc, float flt) 
    {
        float Frc = (float)frc.getNumerator()/frc.getDenominator();
        if ( Frc>flt) return true;
        else return false;
    }

    // check who is the bigger between float and fraction
    bool operator > (float flt, const Fraction& frc) 
    {
        float Frc = (float)frc.getNumerator()/frc.getDenominator();
        if ( flt>Frc) return true;
        else return false;
    }


    // check who is maybe the bigger between two fractions
    bool Fraction::operator >= (const Fraction& other) const
    {
        float Frc = (float)this->numer_/this->denom_;
        float Other = (float)other.getNumerator()/other.getDenominator();
        if (Frc>=Other) return true;
        else return false;
    }

    // check who is maybe the bigger between fraction and float
    bool operator >= (const Fraction& frc, float flt) 
    {
        float Frc = (float)frc.getNumerator()/frc.getDenominator();
        if (Frc>=flt) return true;
        else return false;
    }

    // check who is maybe the bigger between float and fraction
    bool operator >= (float flt, const Fraction& frc) 
    {
        float Frc = (float)frc.getNumerator()/frc.getDenominator();
        if (flt>=Frc) return true;
        else return false;
    }


    // check who is the bigger between two fractions
    bool Fraction::operator < (const Fraction& other) const
    {
        float Frc = (float)this->numer_/this->denom_;
        float Other = (float)other.getNumerator()/other.getDenominator();
        if (Frc<Other) return true;
        else return false;
    }

    // check who is the bigger between fraction and float
    bool operator < (const Fraction& frc, float flt) 
    {
        float Frc = (float)frc.getNumerator()/frc.getDenominator();
        if (Frc<flt) return true;
        else return false;
    }

    // check who is the bigger between float and fraction
    bool operator < (float flt, const Fraction& frc) 
    {
        float Frc = (float)frc.getNumerator()/frc.getDenominator();
        if (flt<Frc) return true;
        else return false;
    }


    // check who is maybe the bigger between two fractions
    bool Fraction::operator <= (const Fraction& other) const
    {
        float Frc = (float)this->numer_/this->denom_;
        float Other = (float)other.getNumerator()/other.getDenominator();
        if (Frc<=Other) return true;
        else return false;
    }

    // check who is maybe the bigger between fraction and float
    bool operator <= (const Fraction& frc, float flt) 
    {
        float Frc = (float)frc.getNumerator()/frc.getDenominator();
        if (Frc<=flt) return true;
        else return false;
    }

    // check who is maybe the bigger between float and fraction
    bool operator <= (float flt, const Fraction& frc) 
    {
        float Frc = (float)frc.getNumerator()/frc.getDenominator();
        if (flt<=Frc) return true;
        else return false;
    }


    // adds 1 to the fraction . postfix (n++).
    const Fraction Fraction::operator ++ (int n)
    {
        Fraction f(this->numer_, this->denom_);
        this->numer_ = this->numer_ + this->denom_;
        this->reduce();
        return f.reduce();
    }


    // adds 1 to the fraction. prefix (++n).
    Fraction Fraction::operator ++ ()
    {
        this->numer_ = this->numer_+this->denom_;
        this->reduce();
        Fraction f(this->numer_, this->denom_);
        return f.reduce();
    }


    // substracts 1 to the fraction. postfix (n--).
    const Fraction Fraction::operator -- (int n)
    {
        Fraction f(this->numer_, this->denom_);
        this->numer_ = this->numer_ - this->denom_;
        this->reduce();
        return f.reduce();
    }


    // substracts 1 to the fraction. prefix (--n).
    Fraction Fraction::operator -- ()
    {
        this->numer_ = this->numer_ - this->denom_;
        this->reduce();
        Fraction f(this->numer_, this->denom_);
        return f.reduce();
    }


    // print a fraction to an output
    ostream& operator << (ostream& output, const Fraction& other)
    {
        Fraction f(other.numer_, other.denom_);
        f.reduce();
        
        return output << f.getNumerator() << "/" << f.getDenominator();
    }


    // read a fraction from an input
    istream& operator >> (istream& input, Fraction& other)
    {
        float numer, denom;
        input >> numer >> denom;

        if (denom == 0) throw runtime_error("runtime_error");
        else if ((floor(numer) != numer ) || (floor(denom) != denom)) throw runtime_error("runtime_error"); // check if enter a float number
        else
        {
            other.numer_ = numer;
            other.denom_ = denom;
        }

        if(!input)
            throw runtime_error("");
       
        return input;
    }


    // return the fraction reduced
    Fraction Fraction::reduce()
    {
        int numer = this->getNumerator(), denom = this->getDenominator();

        int gcd = __gcd(numer, denom); // find the gcd
        numer = numer/gcd;
        denom = denom/gcd;

        if (numer == 0)
        {
            denom = 1;
        }

        // if we have "-" in the denominator - move to the numerator
        else if ((numer > 0) and (denom < 0)) 
        {
            numer = (-1)*numer;
            denom = (-1)*denom;
        }

        // if also the denomanitor an numerator < 0, change this number to be positive number
        else if ((numer < 0) and (denom < 0)) 
        {
            numer = (-1)*numer;
            denom = (-1)*denom;
        }

        // update the new value
        this->numer_ = numer;
        this->denom_ = denom;

        return Fraction(numer, denom);
    }
};