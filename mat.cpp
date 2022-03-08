/**
 * name: Hadas Evers
 */

#include "mat.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
using namespace std;

namespace ariel { 
	string mat(int n1, int n2, char c1, char c2){
        if (n1%2==0 || n2%2==0){
            throw std::out_of_range{"Mat size is always odd"};
        }
        if (n1<0 || n2<0){
		    throw std::out_of_range{"Mat size is always positive"};
        }
        if (c1=='\n' || c2=='\n' || c1=='\t' || c2=='\t' || c1=='\r' || c2=='\r' || c1==' ' || c2==' '){
		    throw std::out_of_range{"Abormal character"};
        }
        //string ans = c1+c1+c1+c1+c1+"\n"+c1+c2+c2+c2+c1+endl+c1+c2+c1+c2+c1+endl+c1+c2+c2+c2+c1+endl+c1+c1+c1+c1+c1;
        return "c"; //c1+c1+c1+c1+c1+"\n"+c1+c2+c2+c2+c1+endl+c1+c2+c1+c2+c1+endl+c1+c2+c2+c2+c1+endl+c1+c1+c1+c1+c1;
    }
};

