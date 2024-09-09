// dangling_pointers.cpp tests compiler and runtime errors with various dangling pointers
// Jared Ziv
// Module 3, Lab 3
#include <iostream>

using namespace std;

int * badReturn();

int main()
{
    // Dangling pointer issue #1
    cout << "Part #1" << endl;
    int *ptr1;
    if (true)
    {
        int square = 25;
        ptr1 = &square;
    }
    *ptr1 = 29;
    cout << "Dangling pointer: " << *ptr1 << endl << endl;


    /* Dangling pointer issue #2
    cout << "Part #2" << endl;
    int *ptr2 = new int(11);

    delete ptr2;
    *ptr2 = 75;
    cout << "Dangling pointer: " << *ptr2 << endl << endl;
    */

    // Dangling pointer issue #3
    cout << "Part #3" << endl;
    int *ptr3 = badReturn();
    cout << "Dangling pointer: " << *ptr3 << endl;

    //WIll the value in ptr3 be re-initialized?
    *ptr3 = 45;
    ptr3 = badReturn();
    cout << "When called again: " << *ptr3 << endl;
    return 0;
}

// Return the address of a local variable 
int * badReturn() { 
    static int x = 13 ;
    return &x ;    
} 