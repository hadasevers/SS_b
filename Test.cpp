/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Hadas Evers
 * 
 * Date: 03/2022
 */

#include "doctest.h"
#include "mat.hpp"
#include <cmath>
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

/**
 * Returns true if the carpet is a square
 */
bool square(string input) {
    int len = input.length();
    int size = int(sqrt(len));
    if ((size*size) == len) return true;
    else return false;
}

/**
 * Returns true if the carpet is a uniform pattern
 */
bool uniform(string input) {
    bool ans = true;
    int len = input.length();
    for (int i = 0; i < len; ++i)
       if (input[0] != input[i]) ans = false;
    return ans;
}



TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));
	/* Add more test here */
    CHECK(nospaces(mat(9, 1, '@', '&')) == "@@@@@@@@@");
    CHECK(nospaces(mat(1, 5, '@', '-')) == nospaces(mat(5, 1, '@', '-')));
    CHECK(nospaces(mat(3, 5, '@', '@')) == nospaces(mat(5, 3, '@', '@')));
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    /* Add more test here */
    CHECK_THROWS(mat(7, 4, '$', '%'));
    CHECK_THROWS(mat(0, 0, '$', '%'));
    CHECK_THROWS(mat(-1, 0, '$', '%'));
    CHECK_THROWS(mat(-5, 7, '$', '%'));
    CHECK_THROWS(mat(-2, -5, '$', '%'));
    CHECK_THROWS(mat(-3, -7, '$', '%'));
}

TEST_CASE("Symmetry input") {
    CHECK(square(mat(1, 1, '$', '%')) == true);
    CHECK(square(mat(7, 7, '$', '%')) == true);
    CHECK(square(mat(3, 7, '$', '$')) == false);
}

TEST_CASE("Uniform input") {
    CHECK(uniform(mat(1, 1, '$', '%')) == true);
    CHECK(uniform(mat(7, 7, '@', '-')) == false);
    CHECK(uniform(mat(3, 7, '$', '$')) == true);
}

TEST_CASE("Abormal character") {
    CHECK_THROWS(mat(7, 5, ' ', ' '));
    CHECK_THROWS(mat(3, 5, '\r', '-'));
    CHECK_THROWS(mat(3, 5, '\t', '\n'));
    CHECK_THROWS(mat(3, 5, '#', ' '));
}




/* Add more test cases here */