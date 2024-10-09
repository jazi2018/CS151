/* Lab7.cpp - create various Animal objects
 * Author:     Jared Ziv
 * Module:     7
 * Project:    Lab, Part 2
 * Problem statement: Create a parent class Animal with subclasses for
 *                    Foxes and Owls.
 *
 * Algorithm:
 *   Followed lab instructions.
 * 
 * Review Questions:
 *      1. What is/are the names of the base classes?
 *          - The base class is named Animal
 *      2. What is/are the names of the derived classes?
 *          - The derived classes are named Fox and Owl
 *      3. Does  Animal  have a parent class?
 *          - Animal does NOT have a parent class
 *      4. Is the function  showInfo  overridden?  Is  makeNoise?  Is  sleep?
 *          - showInfo and makeNoise are overridden. sleep is not overwritten.
 *      5. If the data member  name  in the  Animal  class were made  protected
 *         (instead of  private), would you need to use getters in the showInfo
 *         function of the child classes  Fox  and  Owl? 
 *          - You would not need to use getters, since they would be accessible
 *            by name by derived classes
 *      6. What if the class data members were left  private,  but the base access
 *         modifiers to the  Animal  class in both child classes were made  protected,
 *         would you need to use getters in the  showInfo  function of the child classes
 *         Fox  and  Owl? 
 *          - You WOULD need to use getters. The protected base access modifier wont
 *            change access to private data members (they will still be private)
 */
#include <iostream>
#include "Animal.h"
#include "Fox.h"
#include "Owl.h"

using namespace std;

int main()
{
    Animal * oscar = new Animal("Oscar");
    Owl * errol = new Owl("Errol", "Great Grey");
    Fox * foxy = new Fox("Foxy");

    cout << endl;
    //show info
    oscar->showInfo();
    errol->showInfo();
    foxy->showInfo();

    cout << endl;
    //make noise
    oscar->makeNoise();
    errol->makeNoise();
    foxy->makeNoise();

    cout << endl;
    //sleep
    oscar->sleep();
    errol->sleep();
    foxy->sleep();
    return 0;
}