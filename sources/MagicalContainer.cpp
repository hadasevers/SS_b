#include <iostream>
#include <vector>
#include <algorithm>
#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;
        

MagicalContainer::MagicalContainer() : myIndex(0) {} // constructor

void MagicalContainer::addElement(int num)
{
    cout << "addElement" << endl;
    numbers.push_back(num);
    order.push_back(&numbers[0]);
    prime.push_back(&numbers[0]);
    cross.push_back(&numbers[0]);
}

void MagicalContainer::removeElement(int num)
{
    cout << "removeElement" << endl;
}

int MagicalContainer::size()
{
    return this->numbers.size();
}


vector<int>& MagicalContainer::getNumbers()
{
    return numbers;
}





//-------------- MyIterator implemence ---------------//

// defult constructor
MagicalContainer::MyIterator::MyIterator() : myvector(nullptr), myPvector(nullptr), current_index(-1) {}

// constructor                  
MagicalContainer::MyIterator::MyIterator(MagicalContainer &container) : myvector(&(container.numbers)), myPvector(nullptr), current_index(0) {} 

// copy constructor
MagicalContainer::MyIterator::MyIterator(const MyIterator &other) : myvector(other.myvector), myPvector(other.myPvector), current_index(other.current_index) {}


// operatore =
MagicalContainer::MyIterator& MagicalContainer::MyIterator::operator=(const MyIterator& other)
{
    // check for self-assignment
    if (this == &other)
    {
        return *this;
    }

    // copy the data
    this->myvector = other.myvector;
    this->myPvector = other.myPvector;
    this->current_index = other.current_index;

    return *this;
}


bool MagicalContainer::MyIterator::operator==(const MyIterator &other) const
{
    return (this->myvector == other.myvector) && (this->myPvector == other.myPvector) && (this->current_index == other.current_index);  // ?? no check *current_index? // the Pvector is same 
}

bool MagicalContainer::MyIterator::operator!=(const MyIterator &other) const
{
    return !(*this == other); /// or: return !this==other;
}

//return pointer* to the current_index;
int MagicalContainer::MyIterator::operator*() const
{
    /*
    if (current_index >= myPvector->size())
    {
        throw std::out_of_range("the index of the iterator out of range"); // or this.myPvector.size()??
    }
    return *((*myPvector)[(size_t)current_index]);
    */
    return 0;
}

// prefix ++i;
MagicalContainer::MyIterator& MagicalContainer::MyIterator::operator++()
{
    ++current_index;

    return *this;
}

// return the first
int* MagicalContainer::MyIterator::begin()
{
    //return (*myPvector)[0];
    //return myPvector->front();
    return myvector->data();
}

// return the last
int* MagicalContainer::MyIterator::end()
{
    if (current_index >= myvector->size())
    {
        return nullptr;
    }
    //return (myPvector->back())+1;
    return myvector->data() + myvector->size();
}

int MagicalContainer::MyIterator::get_index() const
{
    return this->current_index;
}

vector<int*>* MagicalContainer::MyIterator::get_Pvector() const
{
    return this->myPvector;
}

void MagicalContainer::MyIterator::set_container(MagicalContainer &container)
{
    this->myvector = &(container.getNumbers());
    this->current_index = 0;
}

// 1-order, 2-cross, 3-prime
void MagicalContainer::MyIterator::set_Pvector(MagicalContainer &container, int num)
{
    if (num == 1)
        this->myPvector = &(container.order);
    else if (num == 2)
        this->myPvector = &(container.cross);
    else if (num == 3)
        this->myPvector = &(container.prime);
    else throw runtime_error("error setting Pvector");
}   





//-------------- AscendingIterator implemence ---------------//


// defult constructor
MagicalContainer::AscendingIterator::AscendingIterator() : MyIterator() {}

// constructor
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : MyIterator(container)
{
    this->set_Pvector(container, 1);// = container.order;
}

// copy constructor
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : MyIterator(other) {}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const 
{
    return this->get_index() > other.get_index();
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const 
{
    return this->get_index() < other.get_index();
}

int* MagicalContainer::AscendingIterator::begin()
{
    //return (*(this->get_Pvector()))[0]; //&((*myPvector)[0]);
    //return MyIterator::begin();
    return this->get_Pvector()->front();
}

int* MagicalContainer::AscendingIterator::end()
{
    if (this->get_index() >= this->get_Pvector()->size())
    {
        return nullptr;
    }
    return (this->get_Pvector()->back())+1;
    //return MyIterator::end();

    if (this->get_Pvector()->empty())
    {
        return nullptr;
    }
    return (*(this->get_Pvector()))[this->get_Pvector()->size()]; // return &((*myPvector)[myPvector->size()]);
}






//-------------- SideCrossIterator implemence ---------------//


// defult constructor
MagicalContainer::SideCrossIterator::SideCrossIterator() : MyIterator() {}

// constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : MyIterator(container)
{
    this->set_Pvector(container, 2);
}

// copy constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : MyIterator(other){}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const 
{
    return this->get_index() > other.get_index();
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const 
{
    return this->get_index() < other.get_index();
}

int* MagicalContainer::SideCrossIterator::begin()
{
    //return MyIterator::begin();
    //return (*(this->get_Pvector()))[0];
    return this->get_Pvector()->front();
}

int* MagicalContainer::SideCrossIterator::end()
{
    if (this->get_index() >= this->get_Pvector()->size())
    {
        return nullptr;
    }
    return (this->get_Pvector()->back())+1;

    //return MyIterator::end();
    if (this->get_Pvector()->empty())
    {
        return nullptr;
    }
    return (*(this->get_Pvector()))[this->get_Pvector()->size()];
}






//-------------- PrimeIterator implemence ---------------//


// defult constructor
MagicalContainer::PrimeIterator::PrimeIterator() : MyIterator() {}

// constructor
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : MyIterator(container)
{
    this->set_Pvector(container, 3);
}

// copy constructor
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : MyIterator(other){}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const 
{
    return this->get_index() > other.get_index();
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const 
{
    return this->get_index() < other.get_index();
}

int* MagicalContainer::PrimeIterator::begin()
{
    //return MyIterator::begin();
    //return (*(this->get_Pvector()))[0];
    return this->get_Pvector()->front();
}

int* MagicalContainer::PrimeIterator::end()
{
    if (this->get_index() >= this->get_Pvector()->size())
    {
        return nullptr;
    }
    return (this->get_Pvector()->back())+1;

    //return MyIterator::end();
    if (this->get_Pvector()->empty())
    {
        return nullptr;
    }
    return (*(this->get_Pvector()))[this->get_Pvector()->size()];
}
