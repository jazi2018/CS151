/* lab15_proj1.cpp - Demonstrates set class functionality
 * Author:     Jared Ziv
 * Module:     15
 * Project:    Lab, Part 1
 * Problem statement:   Implement several functions to the set class,
 *      then test in main using various set samples.
 *
 * Algorithm:
 *      minus(other_set):
 *          1. Intialize SetNode pointer it to head. Initialize Set diff to Set().
 *          2. While it is not nullptr:
 *              a. Check if other_set contains it->data. If it doesn't, insert it
 *                 into diff
 *              b. Set it to it->next
 *          3. Return diff
 * 
 *      size():
 *          1. Initialize int size to 0 and SetNode pointer it to head
 *          2. Iterate through set using while loop while it != nullptr. At
 *             every iteration, increment size by one and set it to it->next
 *          3. Return size
 *      
 *      equals(other_set):
 *          1. Initialize SetNode pointer it to head
 *          2. While it is not nullptr
 *              a. If other_set does not contain it->data, return false
 *              b. Set it to it->next
 *          3. Return true
 * 
 *      clear():
 *          1. Initialize SetNode pointers curr to head and next to
 *             head->next
 *          2. While curr is not nullptr
 *              a. Set next to curr->next
 *              b. Delete curr
 *              c. Set curr to next
 *          3. Set head to nullptr
 */
#include <iostream>
#include "SetLinkedList.h"
using namespace std;

template <typename T>
void runTests(Set<T> A, Set<T> B);

int main()
{
    cout << "Test case 1:" << endl;
    string c1_arr1[] = {"C", "G", "E", "A"};
    string c1_arr2[] = {"E", "C", "F"};
    //initialize set 1
    Set<string> str_set1;
    for (string s : c1_arr1)
    {
        str_set1.insert(s);
    }
    //initialize set 2
    Set<string> str_set2;
    for (string s : c1_arr2)
    {
        str_set2.insert(s);
    }
    runTests(str_set1, str_set2);
    //clear sets
    str_set1.clear();
    str_set2.clear();

    cout << endl << "Test case 2:" << endl;
    string c2_arr1[] = {"Carlos", "John", "Alice"};
    string c2_arr2[] = {"John", "Henry", "Maria"};
    //initialize set 1
    for (string s : c2_arr1)
    {
        str_set1.insert(s);
    }
    //initialize set 2
    for (string s : c2_arr2)
    {
        str_set2.insert(s);
    }
    runTests(str_set1, str_set2);
    //clear sets

    cout << endl << "Test case 3:" << endl;
    int c3_arr1[] = {15, 11, 13};
    int c3_arr2[] = {11, 13, 15, 17, 19};
    Set<int> int_set1;
    for (int i : c3_arr1)
    {
        int_set1.insert(i);
    }
    //initialize set 2
    Set<int> int_set2;
    for (int i : c3_arr2)
    {
        int_set2.insert(i);
    }
    runTests(int_set1, int_set2);
    //clear sets
    int_set1.clear();
    int_set2.clear();

    cout << endl << "Test case 4:" << endl;
    //initialize set 1
    int_set1.insert(9);
    runTests(int_set1, int_set2);
}

template <typename T>
void runTests(Set<T> A, Set<T> B)
{
    cout << "Set A: ";
    A.display();
    cout << "Set B: ";
    B.display();
    cout << "A n B: ";
    Set<T> intersection = A.setIntersect(B);
    intersection.display();
    cout << "A - B: ";
    Set<T> diff = A.minus(B);
    diff.display();
    cout << "(A - B) U (A n B): ";
    Set<T> di_union = diff.setUnion(intersection);
    di_union.display();
    cout << "Equal?: " << (di_union.equals(A) ? "Yes" : "No") << endl;
    cout << "Set A has " << A.size() << (A.size() == 1 ? " element." : " elements.") << endl;
}