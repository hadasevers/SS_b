#include <string>
#include <stdio.h>
#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace std;
using namespace ariel;


TEST_SUITE("MagicalContainer Test")
{
    TEST_CASE("addElement Test")
    {
        CHECK_NOTHROW(MagicalContainer c); //true
        MagicalContainer c;

        //CHECK(c.getNumbers()[0] == nullptr);
        CHECK(c.size() == 0);

        // check positive and negative
        CHECK_NOTHROW(c.addElement(5));  // positive
        CHECK_NOTHROW(c.addElement(0));  // zero
        CHECK_NOTHROW(c.addElement(-9)); // negative

        c.addElement(5);
        c.addElement(0);
        c.addElement(-9);

        CHECK(c.size() == 3);

        CHECK(c.getNumbers()[0] == 5);
        CHECK(c.getNumbers()[1] == 0);
        CHECK(c.getNumbers()[2] == -9);


        c.addElement(5); // 5 already exist
        CHECK(c.size() == 3);
        
        string str = to_string(c.getNumbers()[0]);

        for(size_t i=1; i<c.getNumbers().size(); ++i)
        {
            str = str + ", " + to_string(c.getNumbers()[i]);
        }

        CHECK(str.compare("5, 0, -9")); // check 5 not add
    }


    TEST_CASE("removeElement Test")
    {
        MagicalContainer c;

        c.addElement(5);
        c.addElement(0);
        c.addElement(-9);

        CHECK(c.size() == 3);

        CHECK_NOTHROW(c.removeElement(5));
        CHECK_NOTHROW(c.removeElement(0));
        CHECK_NOTHROW(c.removeElement(-9));
        CHECK_NOTHROW(c.removeElement(7)); // check if number not exist

        c.removeElement(5);
        c.removeElement(0);
        c.removeElement(-9);

        CHECK_NOTHROW(c.removeElement(7)); // check when the container empty
    }


    TEST_CASE("size Test")
    {
        MagicalContainer c;

        CHECK(c.size() == 0);

        c.addElement(5);
        c.addElement(0);
        c.addElement(-9);
        CHECK(c.size() == 3);

        // check when add exist number
        c.addElement(5);
        CHECK(c.size() == 3);

        c.removeElement(5);
        c.removeElement(0);
        c.removeElement(-9);
        CHECK(c.size() == 0);

        // check when the container empty
        c.removeElement(5);
        CHECK(c.size() == 0);

        c.addElement(5);
        CHECK(c.size() == 1);

        // check when remove not exist number
        c.removeElement(7); 
        CHECK(c.size() == 1);
    }

}



TEST_SUITE("AscendingIterator Test")
{
    TEST_CASE("empty container test")
    {
        MagicalContainer c;
        
        // defult constructor
        CHECK_NOTHROW(MagicalContainer::AscendingIterator m1);
        MagicalContainer::AscendingIterator m1;
        CHECK(m1.get_index() == -1);
        //CHECK(m1.get_Pvector() == nullptr);

        // my constructor
        CHECK_NOTHROW(MagicalContainer::AscendingIterator m2(c));
        MagicalContainer::AscendingIterator m2(c);
        CHECK(m2.get_index() == 0);
        //CHECK(m2.get_Pvector() == nullptr);

        // copy constructor
        CHECK_NOTHROW(MagicalContainer::AscendingIterator m3(m2));
        MagicalContainer::AscendingIterator m3(m2);
        CHECK(m2.get_index() == 0);
        //CHECK(m2.get_Pvector() == nullptr);

        CHECK(m2 == m3); // true
        CHECK(m1 != m3); // true

        CHECK_NOTHROW(m1.set_container(c));
        m1.set_container(c);
        CHECK(m1 == m3); // true

        CHECK(!(m1 > m2));
        CHECK(!(m1 < m2));

        CHECK_THROWS(++m1); // after the finish
        CHECK_THROWS(++m2); // after the finish
        CHECK_THROWS(++m3); // after the finish
    }

    TEST_CASE("no empty container test")
    {
        MagicalContainer c;
        c.removeElement(5);
        c.removeElement(0);
        c.removeElement(-9);
        c.removeElement(8);
        c.removeElement(25);
        c.removeElement(-17);

        // defult constructor
        MagicalContainer::AscendingIterator m1;

        // my constructor
        MagicalContainer::AscendingIterator m2(c);

        // copy constructor
        MagicalContainer::AscendingIterator m3(m2);

        CHECK(m2 == m3); // true
        CHECK(m1 != m3); // true

        CHECK_NOTHROW(m1.set_container(c));
        m1.set_container(c);
        CHECK(m1 == m3); // true

        ++m1;
        ++m2;
        CHECK(m2 == m1); // true
        CHECK(m1 > m3); // true
        CHECK(m3 < m2); // true

        CHECK(m1.get_index() == 1);

        CHECK(*m3 == -17); // true
        CHECK(*m1 == -9); // true
        CHECK(*m2 == -9); // true

        ++m1;
        CHECK(*m1 == -0); // true

        ++m1;
        ++m1;
        ++m1;
        CHECK(*m1 == 25); // the last member
        CHECK(m1.get_index() == 5);

        CHECK_THROWS(++m1); // after the finish

        cout << "finish order" << endl;
    }
}

TEST_SUITE("PrimeIterator Test")
{
    TEST_CASE("empty container test")
    {
        MagicalContainer c;
        
        // defult constructor
        CHECK_NOTHROW(MagicalContainer::PrimeIterator m1);
        MagicalContainer::PrimeIterator m1;
        CHECK(m1.get_index() == -1);
        //CHECK(m1.get_Pvector() == nullptr);

        // my constructor
        CHECK_NOTHROW(MagicalContainer::PrimeIterator m2(c));
        MagicalContainer::PrimeIterator m2(c);
        CHECK(m2.get_index() == 0);
        //CHECK(m2.get_Pvector() == nullptr);

        // copy constructor
        CHECK_NOTHROW(MagicalContainer::PrimeIterator m3(m2));
        MagicalContainer::PrimeIterator m3(m2);
        CHECK(m2.get_index() == 0);
        //CHECK(m2.get_Pvector() == nullptr);

        CHECK(m2 == m3); // true
        CHECK(m1 != m3); // true

        CHECK_NOTHROW(m1.set_container(c));
        m1.set_container(c);
        CHECK(m1 == m3); // true

        CHECK(!(m1 > m2));
        CHECK(!(m1 < m2));

        CHECK_THROWS(++m1); // after the finish
        CHECK_THROWS(++m2); // after the finish
        CHECK_THROWS(++m3); // after the finish

    }

    TEST_CASE("no empty container test")
    {
        MagicalContainer c;
        c.removeElement(5);
        c.removeElement(0);
        c.removeElement(9);
        c.removeElement(8);
        c.removeElement(25);
        c.removeElement(17);

        // defult constructor
        MagicalContainer::PrimeIterator m1;

        // my constructor
        MagicalContainer::PrimeIterator m2(c);

        // copy constructor
        MagicalContainer::PrimeIterator m3(m2);

        CHECK(m2 == m3); // true
        CHECK(m1 != m3); // true

        CHECK_NOTHROW(m1.set_container(c));
        m1.set_container(c);
        CHECK(m1 == m3); // true

        ++m1;
        ++m2;
        CHECK(m2 == m1); // true
        CHECK(m1 > m3); // true
        CHECK(m3 < m2); // true

        CHECK(m1.get_index() == 1);

        CHECK(*m3 == 5); // true
        CHECK(*m1 == 17); // true
        CHECK(*m2 == 17); // true

        CHECK_THROWS(++m1); // after the finish

        cout << "finish prime" << endl;
    }
}

TEST_SUITE("SideCrossIterator Test")
{
    TEST_CASE("empty container test")
    {
        MagicalContainer c;
        
        // defult constructor
        CHECK_NOTHROW(MagicalContainer::SideCrossIterator m1);
        MagicalContainer::SideCrossIterator m1;
        CHECK(m1.get_index() == -1);
        //CHECK(m1.get_Pvector() == nullptr);

        // my constructor
        CHECK_NOTHROW(MagicalContainer::SideCrossIterator m2(c));
        MagicalContainer::SideCrossIterator m2(c);
        CHECK(m2.get_index() == 0);
        //CHECK(m2.get_Pvector() == nullptr);

        // copy constructor
        CHECK_NOTHROW(MagicalContainer::SideCrossIterator m3(m2));
        MagicalContainer::SideCrossIterator m3(m2);
        CHECK(m2.get_index() == 0);
        //CHECK(m2.get_Pvector() == nullptr);

        CHECK(m2 == m3); // true
        CHECK(m1 != m3); // true

        CHECK_NOTHROW(m1.set_container(c));
        m1.set_container(c);
        CHECK(m1 == m3); // true

        CHECK(!(m1 > m2));
        CHECK(!(m1 < m2));

        CHECK_THROWS(++m1); // after the finish
        CHECK_THROWS(++m2); // after the finish
        CHECK_THROWS(++m3); // after the finish
    }

    TEST_CASE("no empty container test")
    {
        MagicalContainer c;
        c.removeElement(5);
        c.removeElement(0);
        c.removeElement(9);
        c.removeElement(8);
        c.removeElement(25);
        c.removeElement(17);

        // defult constructor
        MagicalContainer::SideCrossIterator m1;

        // my constructor
        MagicalContainer::SideCrossIterator m2(c);

        // copy constructor
        MagicalContainer::SideCrossIterator m3(m2);

        CHECK(m2 == m3); // true
        CHECK(m1 != m3); // true

        CHECK_NOTHROW(m1.set_container(c));
        m1.set_container(c);
        CHECK(m1 == m3); // true

        ++m1;
        ++m2;
        CHECK(m2 == m1); // true
        CHECK(m1 > m3); // true
        CHECK(m3 < m2); // true

        CHECK(m1.get_index() == 1);

        CHECK(*m3 == 0); // true
        CHECK(*m1 == 25); // true
        CHECK(*m2 == 25); // true

        ++m1; // 5
        ++m1; // 17
        ++m1; // 8
        ++m1; // 9
        CHECK(*m1 == 9); // true
        CHECK(m1.get_index() == 5);

        CHECK_THROWS(++m1); // after the finish

        cout << "finish cross" << endl;
    }
}
