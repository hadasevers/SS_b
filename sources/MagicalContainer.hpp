#include <iostream>
#include <vector>
#include <string>

using namespace std;

#pragma once

namespace ariel
{
    class MagicalContainer
    {
        private:
            vector<int> numbers;
            vector<int*> order;
            vector<int*> prime;
            vector<int*> cross;
            int myIndex;

        public:
            MagicalContainer(); // constructor
            void addElement(int num);
            void removeElement(int num);
            int size();
            vector<int>& getNumbers();

            class MyIterator
            {
                private:
                    vector<int> *myvector;
                    vector<int*> *myPvector;
                    int current_index;

                public:
                    MyIterator(); // defult constructor
                    MyIterator(MagicalContainer &container); // constructor
                    MyIterator(const MyIterator &other); // copy constructor
                    MyIterator(MyIterator &&other)= default;; //move constructor
                    virtual ~MyIterator() = default;
                    MyIterator& operator=(const MyIterator& other);
                    MyIterator& operator=(MyIterator &&other) = default; // move assigment operator
                    bool operator==(const MyIterator &other) const;
                    bool operator!=(const MyIterator &other) const;
                    int operator*() const; //return pointer* to the current_index;
                    MyIterator& operator++();
                    //virtual bool operator>(const MyIterator &other) const = 0;
                    //virtual bool operator<(const MyIterator &other) const = 0;
                    virtual int* begin() = 0;
                    virtual int* end() = 0;
                    int get_index() const;
                    vector<int*>* get_Pvector() const;
                    void set_container(MagicalContainer &container);
                    void set_Pvector(MagicalContainer &container, int num); // 1-order, 2-cross, 3-prime
            };


            class AscendingIterator : public MyIterator
            {
                public:
                    AscendingIterator(); // defult constructor
                    AscendingIterator(MagicalContainer &container); // constructor
                    AscendingIterator(const AscendingIterator &other); // copy constructor
                    AscendingIterator(AscendingIterator &&other) = default;; //move constructor
                    AscendingIterator& operator=(AscendingIterator &&other) = default; // move assigment operator
                    AscendingIterator& operator=(const AscendingIterator& other) = default; // copy assigment operator
                    ~AscendingIterator() override = default;
                    bool operator>(const AscendingIterator &other) const;
                    bool operator<(const AscendingIterator &other) const;
                    int* begin() override;
                    int* end() override;
            };

            class SideCrossIterator : public MyIterator
            {
                public:
                    SideCrossIterator(); // defult constructor
                    SideCrossIterator(MagicalContainer &container); // constructor
                    SideCrossIterator(const SideCrossIterator &other); // copy constructor
                    SideCrossIterator(SideCrossIterator &&other) = default;; //move constructor
                    SideCrossIterator& operator=(SideCrossIterator &&other) = default; // move assigment operator
                    SideCrossIterator& operator=(const SideCrossIterator& other) = default; // copy assigment operator
                    ~SideCrossIterator() override = default;
                    bool operator>(const SideCrossIterator &other) const;
                    bool operator<(const SideCrossIterator &other) const;
                    int* begin() override;
                    int* end() override;
            };


            class PrimeIterator : public MyIterator
            {
                public:
                    PrimeIterator(); // defult constructor
                    PrimeIterator(MagicalContainer &container); // constructor
                    PrimeIterator(const PrimeIterator &other); // copy constructor
                    PrimeIterator(PrimeIterator &&other) = default;; //move constructor
                    PrimeIterator& operator=(PrimeIterator &&other) = default; // move assigment operator
                    PrimeIterator& operator=(const PrimeIterator& other) = default; // copy assigment operator
                    ~PrimeIterator() override = default;
                    bool operator>(const PrimeIterator &other) const;
                    bool operator<(const PrimeIterator &other) const;
                    int* begin() override;
                    int* end() override;
            };
    };
}