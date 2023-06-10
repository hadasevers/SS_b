#include <iostream>
#include <vector>
#include <algorithm>
#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;
        

// constructor
MagicalContainer::MagicalContainer() : myIndex(0) {} 


void MagicalContainer::addElement(int num)
{
    // if the vector is empty
    if (numbers.size() == 0)
        numbers.push_back(num);

    // if the new num is bigger than the previous big one, add it num
    else if (num >= numbers[numbers.size()-1])
    {
       if (num > numbers[numbers.size()-1])
       numbers.push_back(num);
    }
    
    // put the number in the correct position
    else
    {
        size_t indexIn = 0;

        for(size_t i=0; i<numbers.size(); ++i)
        {
            indexIn = i;
            if(num < numbers[i])
                break;
        }

        if (num == numbers[indexIn]) // the number is already exist in the vector
            return;

        int currentNum = num;
        for(size_t i=indexIn; i<numbers.size(); ++i)
        {
            int temp = numbers[i];
            numbers[i] = currentNum;
            currentNum = temp;
        }
        numbers.push_back(currentNum);
    }

    ++myIndex;
    this->update();
}


void MagicalContainer::removeElement(int num)
{
    // check if the vector is empty
    if (numbers.empty() == true)
        return;

    int indexIn = -1;

    // finding the relevant index
    for(size_t i=0; i<numbers.size(); ++i)
    {
        if(num == numbers[i])
        {
            indexIn = i;
            break;
        }
    }

    if(indexIn == -1) // the number no exist
        throw runtime_error("Removing a non-existing element");

    // update the members
    for(size_t i=(size_t)indexIn; i<numbers.size()-1; ++i){
        int temp = numbers[i+1];
        numbers[i] = temp;
    }

    numbers.pop_back(); // remove the number
    --myIndex;
    this->update(); // update the pointer's vectors
}


// update the pointer's vectors
void MagicalContainer::update()
{
    this->order.clear();
    this->cross.clear();
    this->prime.clear();

    for (size_t i=0; i<numbers.size(); ++i)
    {
        //  push to order vector
        this->order.push_back(&(numbers[i])); 

        //  push to cross vector
        if(i%2 ==0)
            this->cross.push_back(&(numbers[i/2]));
        else
            this->cross.push_back(&(numbers[(size_t)numbers.size()-((i/2)+1)]));

        //  push to prime vector
        if(isPrime(numbers[i]) == true) // is prime
            this->prime.push_back(&(numbers[i]));
    }
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
MagicalContainer::MyIterator::MyIterator()
    : myvector(nullptr), myPvector(nullptr), current_index(-1) {}

// constructor                  
MagicalContainer::MyIterator::MyIterator(MagicalContainer &container)
    : myvector(&(container.numbers)), myPvector(&(container.order)), current_index(0) {} 

// copy constructor
MagicalContainer::MyIterator::MyIterator(const MyIterator &other)
    : myvector(other.myvector), myPvector(other.myPvector), current_index(other.current_index) {}

// operatore =
MagicalContainer::MyIterator& MagicalContainer::MyIterator::operator=(const MyIterator& other)
{
    // check for self-assignment
    if (this == &other)
    {
        return *this;
    }

    else if(this->myvector != other.myvector) // the container is different
        throw runtime_error("the container is different");

    // copy the data
    this->myvector = other.myvector;
    this->myPvector = other.myPvector;
    this->current_index = other.current_index;

    return *this;
}

bool MagicalContainer::MyIterator::operator==(const MyIterator &other) const
{
    return (this->current_index == other.current_index && this->myvector == other.myvector);
}

bool MagicalContainer::MyIterator::operator!=(const MyIterator &other) const
{
    return !(*this == other);
}

// return number in this index;
int MagicalContainer::MyIterator::operator*() const
{
    if (current_index >= myPvector->size())
    {
        throw std::out_of_range("the index of the iterator out of range"); // or this.myPvector.size()??
    }
    return (*(*myPvector)[(size_t)current_index]);
}

// prefix ++i;
MagicalContainer::MyIterator& MagicalContainer::MyIterator::operator++()
{
    if(current_index >= myPvector->size())
        throw runtime_error("Attempt to increment beyond the end");

    ++current_index;
    return *this;
}

// return the first
MagicalContainer::MyIterator& MagicalContainer::MyIterator::begin()
{
    this->current_index = 0;
    return *this;
}

// return one after the last
MagicalContainer::MyIterator& MagicalContainer::MyIterator::end()
{
    this->current_index = this->myPvector->size();
    return *this;
}

int MagicalContainer::MyIterator::get_index() const
{
    return this->current_index;
}

vector<int*>*& MagicalContainer::MyIterator::get_Pvector()
{
    return this->myPvector;
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
    this->set_Pvector(container, 1); // = container.order;
}

// copy constructor
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : MyIterator(other){}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const 
{
    return this->get_index() > other.get_index();
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const 
{
    return this->get_index() < other.get_index();
}







//-------------- SideCrossIterator implemence ---------------//


// defult constructor
MagicalContainer::SideCrossIterator::SideCrossIterator() : MyIterator() {}

// constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : MyIterator(container)
{
    this->set_Pvector(container, 2); // = container.cross;
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







//-------------- PrimeIterator implemence ---------------//


// defult constructor
MagicalContainer::PrimeIterator::PrimeIterator() : MyIterator() {}

// constructor
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : MyIterator(container)
{
    this->set_Pvector(container, 3); // = container.prime;
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




bool ariel::isPrime(int num)
{
    if(num <= 1)
        return false;
    
    for(int i=2; i*i <= num; ++i)
    {
        if(num % i == 0)
            return false;
    }
    
    return true;
}
