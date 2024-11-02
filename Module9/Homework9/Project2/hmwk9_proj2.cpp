/* hmwk9_proj2.cpp - program that can read and write structs to a .dat file
 * Author:     Jared Ziv
 * Module:     9
 * Project:    Homework, Part 2
 * Problem statement:  Write a program that uses a structure to store inventory information
 *      in a binary file. If the inventory file doesn't exist, please create one when first
 *      running your program.
 *
 * Algorithm:
 *   1. Create new fstream object and open to filename. If it fails, report and exit the program
 *      with code 1. Otherwise, close the file.
 *   2. Display a menu with choices to add, view and edit files, or exit the program.
 *   3. Get user input for the menu. Compare cases using a switch statement.
 *   4. Repeatedly get user input until exit is selected.
 * 
 *      Adding files:
 *          (Before entering the function, open file to filename with binary, out, and app flags)
 *          1. Create placeholder Inventory object
 *          2. Create a string called buffer
 *          3. Prompt input for each data member of the structure. Read into buffer using
 *             getline and parse using stringstream. If input is invalid based on homework
 *             specifications, print an appropriate error message and return from the function
 *          4. If all input is valid, write to the open file using reinterpret_cast <char *> and
 *             a reference to the Inventory object.
 *          (After exiting the function, close file)
 *      
 *      Reading files:
 *          (Before entering the function, open file to filename with binary and in flags.
 *           Pass desired index to the function.)
 *          1. Create a placeholder Inventory object
 *          2. Seekg to idx * sizeof(Inventory) from ios::beg
 *          3. Read to the placeholder Inventory object
 *          4. If file has any failure flag, print that the index is invalid and return
 *          5. Otherwise, print each member of the placeholder inventory object.
 *          (After exiting the function, close file)
 * 
 *      Editing files:
 *          (Before entering the function, open file to filename with binary, in, and out flags.
 *           Pass desired index to function.)
 *          1. Follow the steps for reading files.
 *          2. At step 5 (of reading files), when printing the values, include numbers in front.
 *          3. Accept user input for a number. Use a switch statement to prompt for input using
 *             the same error checking as present in writing files for the selected data member.
 *             Update the value in the placeholder inventory object.
 *          4. Write the inventory object to the file using file.write() and idx * sizeof(Inventory)
 *          (After exiting the function, close file)
 */
#include <iostream>
#include <fstream>      //for file access
#include <iomanip>      //for output formatting
#include <sstream>      //for input validation
#include <cstring>      //for string size validation

using namespace std;

struct Inventory
{
    static const int DESC_SIZE = 100, DATE_SIZE = 20;
    char desc[DESC_SIZE], date[DATE_SIZE];
    int quantity;
    double cost, price;
};

//reads a specific entry based on index
void readInventory(fstream &file, const int idx);
//accesses a specific entry and allows modifications to be made
void editInventory(fstream &file, const int idx);
//creates a new entry
void addInventory(fstream &file);

int main()
{
    const string filename = "inventory.dat";
    //create file if doesn't exist already
    fstream file(filename, ios::in | ios::out | ios::binary | ios::app);
    if (!file)
    {
        cout << "File could not be created or opened. Exiting." << endl;
        exit(1);
    }
    else { file.close(); }

    int sel = 0;
    while (sel != 4)
    {
        cout << "Select one of the following:" << endl;
        cout << "1. Add new record" << endl;
        cout << "2. Display record" << endl;
        cout << "3. Change record" << endl;
        cout << "4. Exit" << endl;
        string input;
        getline(cin, input);
        stringstream(input) >> sel;

        int entry_idx;
        switch (sel)
        {
            //add new record
            case 1:
                //open file in binary for output
                file.open(filename, ios::binary | ios::out | ios::app);
                addInventory(file);
                file.close();
                break;
            //display record
            case 2:
                cout << "Enter desired index: " << endl;
                getline(cin, input);
                stringstream(input) >> entry_idx;
                //input validation
                if (entry_idx < 0)
                {
                    cout << "Invalid index. Must be a positive integer." << endl;
                    break;
                }
                //open file for reading
                file.open(filename, ios::binary | ios::in);
                readInventory(file, entry_idx);
                file.close();
                break;
            //change record
            case 3:
                cout << "Enter desired index: " << endl;
                getline(cin, input);
                stringstream(input) >> entry_idx;
                //input validation
                if (entry_idx < 0)
                {
                    cout << "Invalid index. Must be a positive integer." << endl;
                    break;
                }

                //open file for reading and writing
                file.open(filename, ios::binary | ios::in | ios::out);
                editInventory(file, entry_idx);
                file.close();
                break;
            case 4:
                cout << "Exiting." << endl;
                break;

            default:
                cout << "Invalid selection." << endl;
                break;
        }
    }
    
    return 0;
}

void addInventory(fstream &file)
{
    //define new inventory for storing
    Inventory inv;
    
    cout << "Enter item description: " << endl;
    string buffer;
    getline(cin, buffer);
    //validate string size
    if (strlen(buffer.c_str()) < inv.DESC_SIZE)
    {
        strcpy(inv.desc, buffer.c_str());
    }
    else
    {
        cout << "String too large. Max " << inv.DESC_SIZE - 1 << " characters." << endl;
        return;
    }

    cout << "Enter quantity:" << endl;
    getline(cin, buffer);
    stringstream(buffer) >> inv.quantity;
    //validate quantity
    if (inv.quantity < 0)
    {
        cout << "Quantity must be positive." << endl;
        return;
    }

    cout << "Enter cost:" << endl;
    getline(cin, buffer);
    stringstream(buffer) >> inv.cost;
    //validate cost
    if (inv.cost < 0)
    {
        cout << "Cost must be positive." << endl;
        return;
    }

    cout << "Enter price:" << endl;
    getline(cin, buffer);
    stringstream(buffer) >> inv.price;
    //validate price
    if (inv.price < 0)
    {
        cout << "Price must be positive." << endl;
        return;
    }

    cout << "Enter date:" << endl;
    getline(cin, buffer);
    //validate string size
    if (strlen(buffer.c_str()) < inv.DATE_SIZE)
    {
        strcpy(inv.date, buffer.c_str());
    }
    else
    {
        cout << "String too large. Max " << inv.DATE_SIZE - 1 << " characters." << endl;
        return;
    }

    //if all conditions are valid, write inv to binary file and report success
    file.write(reinterpret_cast<char *> (&inv), sizeof(Inventory));
    cout << "Success." << endl;
}

void editInventory(fstream &file, const int idx)
{
    Inventory inv;
    //access start of file
    file.seekg(idx * sizeof(Inventory), ios::beg);
    file.read(reinterpret_cast<char *> (&inv), sizeof(Inventory));

    //if read fails, exit function
    if (file.fail())
    {
        cout << "No existing file found at index " << idx << '.' << endl;
        return;
    }

    //print menu with values
    cout << "Select a value to edit:" << endl;
    cout << setw(19) << left << "1. Item description" << ": " << inv.desc << endl;
    cout << setw(19) << left << "2. Item quantity" << ": " << inv.quantity << endl;
    cout << setw(19) << left << "3. Item cost" << ": " << inv.cost << endl;
    cout << setw(19) << left << "4. Item price" << ": " << inv.price << endl;
    cout << setw(19) << left << "5. Date added" << ": " << inv.date << endl;

    //validate selection input
    int sel;
    string buffer;
    getline(cin, buffer);
    stringstream(buffer) >> sel;

    //boolean varaible for correct output upon function completion
    bool failed = false;
    //perform relevant operation, taken from addInventory()
    switch (sel)
    {
        case 1:
            cout << "Enter item description: " << endl;
            getline(cin, buffer);
            if (strlen(buffer.c_str()) < inv.DESC_SIZE)
            {
                strcpy(inv.desc, buffer.c_str());
            }
            else
            {
                cout << "String too large. Max " << inv.DESC_SIZE - 1 << " characters." << endl;
                failed = true;
            }
            break;

        case 2:
            cout << "Enter quantity:" << endl;
            getline(cin, buffer);
            stringstream(buffer) >> inv.quantity;
            if (inv.quantity < 0)
            {
                cout << "Quantity must be positive." << endl;
                failed = true;
            }
            break;

        case 3:
            cout << "Enter cost:" << endl;
            getline(cin, buffer);
            stringstream(buffer) >> inv.cost;
            if (inv.cost < 0)
            {
                cout << "Cost must be positive." << endl;
                failed = true;
            }
            break;
        
        case 4:
            cout << "Enter price:" << endl;
            getline(cin, buffer);
            stringstream(buffer) >> inv.price;
            if (inv.price < 0)
            {
                cout << "Price must be positive." << endl;
                failed = true;
            }
            break;
        
        case 5:
            cout << "Enter date:" << endl;
            getline(cin, buffer);
            if (strlen(buffer.c_str()) < inv.DATE_SIZE)
            {
                strcpy(inv.date, buffer.c_str());
            }
            else
            {
                cout << "String too large. Max " << inv.DATE_SIZE - 1 << " characters." << endl;
                failed = true;
            }
            break;
        
        default:
            cout << "Invalid selection." << endl;
            return;
    }

    //if operation failed, exit function before updating entry
    if (failed)
    {
        cout << "Edit failed." << endl;
        return;
    }

    //move back to original file position, write eidited inv to file
    file.seekg(idx * sizeof(Inventory), ios::beg);
    file.write(reinterpret_cast<char *> (&inv), sizeof(Inventory));
}

void readInventory(fstream &file, const int idx)
{
    Inventory inv;
    //seek to provided index and read to inv
    file.seekg(idx * sizeof(Inventory), ios::beg);
    file.read(reinterpret_cast<char *> (&inv), sizeof(Inventory));
    
    //if could not read, no valid entry at index
    if (file.fail())
    {
        cout << "No entry found at index " << idx << '.' << endl;
    }
    //otherwise report values of entry
    else
    {
        cout << setw(17) << left << "Item description" << ": " << inv.desc << endl;
        cout << setw(17) << left << "Item quantity" << ": " << inv.quantity << endl;
        cout << setw(17) << left << "Item cost" << ": " << inv.cost << endl;
        cout << setw(17) << left << "Item price" << ": " << inv.price << endl;
        cout << setw(17) << left << "Date added" << ": " << inv.date << endl;
    }
}