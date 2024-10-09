/* PersonAtMCC.h - The parent class of Instructor, Student, and Staff
 * Author:     Jared Ziv
 * Module:     7
 * Project:    Lab, Part 1
 * Description:
 *
 *    Data members:
 *       id (string)
 *       name (string)
 *       address (string)
 *       phone (string)
 *
 *    Functions:
 *       default constructor
 *       partial constructor (id & name)
 *       full constructor
 *       all getters and setters
 *       showinfo
 */

#ifndef PERSON_AT_MCC_H
#define PERSON_AT_MCC_H

#include <iostream>
using namespace std ;

class PersonAtMCC 
{

    private:
        long id ;
        string name ;
        string address ;
        string phone ;

    public :

        PersonAtMCC() {
            PersonAtMCC(0, "no name yet", "no address yet", "no phone yet") ;
        }

        PersonAtMCC(long long id, string name) {
            PersonAtMCC(id, name, "no address yet", "no phone yet") ;
        }

        PersonAtMCC(long id, string name, string address, string phone) //parameterized constructor
        {
            setId(id); setName(name); setAddress(address); setPhone(phone);
        }

        // Getters
        long long getId() const {  return id ; }
        string getName() const { return name ; }
        string getAddress() const { return address ; }
        string getPhone() const { return phone ; }

        // Setters
        void setId(long long new_id) { id = new_id ; }
        void setName(string new_name) { name = new_name ; }
        void setAddress(string new_address) { address = new_address ; }
        void setPhone(string new_phone) { phone = new_phone ; }

        // show person's info on screen
        void showInfo() 
        {
            cout << "ID: " << id
                 << "  Name: " << name
                 << "  Address: " << address << endl
                 << "    Phone: " << phone << endl << endl ;
        }
} ;

#endif
