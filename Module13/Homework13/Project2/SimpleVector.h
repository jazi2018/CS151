/* SimpleVector.h - Simple Vector with added functionality
 * Author:     Jared Ziv
 * Module:     13
 * Project:    Homework #2
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <exception>
using namespace std ;

//exceptions to be thrown
struct MaxCapacityException : public exception
{
    virtual const char * what() const noexcept
    {
        return "Vector at maximum capacity";
    }
};

struct EmptyVectorException : public exception
{
    virtual const char * what() const noexcept
    {
        return "Vector is empty";
    }
};

template <class T>
class SimpleVector {

    protected:
        T *aptr ;
        int size = 0 ;                        // number of elements in vector
        int capacity = 0 ;                    // size of underlying array

    public:
        SimpleVector(int = 0) ;               // Constructor
        SimpleVector(const SimpleVector &) ;  // Copy constructor
        ~SimpleVector() ;                     // Destructor

        int getCapacity()
            { return capacity ; }
        int getSize()
            { return size ; }
        
        //Jared functions
        void push_back(const T item);
        T pop_back();
} ;

//Definition of push_back
template <typename T>
void SimpleVector<T>::push_back(const T item)
{
    if (size >= capacity)
    {
        throw MaxCapacityException();
    }

    *(aptr + size) = item;
    size++;
}

//Definition of pop_back
template <typename T>
T SimpleVector<T>::pop_back()
{
    if (size <= 0)
    {
        throw EmptyVectorException();
    }

    //store last index in placeholder variable, clear index, adjust size and return
    T item = *(aptr + size - 1);
    *(aptr + size - 1) = T();
    size--;
    return item;
}

//*************************************************************
//         Constructor for EnhancedSimpleVector class         *
// Sets the size of the array and allocates memory for it.    *
//*************************************************************

//Jared: it seems like the constructor already does what it should do
//based on the assignment documentation (sets size to 0, accepts int
//for capacity of the vector)
template <class T>
SimpleVector<T>::SimpleVector(int new_capacity) {

    size = 0 ;
    capacity = new_capacity ;
    aptr = new T [capacity] ;

    // Empty the contents of the array
    for (int count = 0 ; count < capacity ; count++) {
        *(aptr + count) = T() ;
    }
}

//**************************************************
//     Copy Constructor for SimpleVector class     *
//**************************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) {

    capacity = obj.capacity ;
    aptr = new T [capacity] ;
    for(int count = 0 ; count < capacity ; count++) {
        *(aptr + count) = *(obj.aptr + count) ;
    }
}

//***********************************************
//     Destructor for SimpleVector class        *
//***********************************************
template <class T>
SimpleVector<T>::~SimpleVector() {

    if (capacity > 0) {
        delete [] aptr ;
    }
}

#endif

