/* hmwk9_proj2.cpp - <simple description>
 * Author:     Jared Ziv
 * Module:     9
 * Project:    Homework, Part 1
 * Problem statement:  <problem statement>
 *
 * Algorithm:
 *   1.  <detailed algorithm>
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstring>

using namespace std;

struct Inventory
{
    static const int DESC_SIZE = 100, DATE_SIZE = 20;
    char desc[DESC_SIZE], date[DATE_SIZE];
    int quantity;
    double cost, price;
};

//modularize for clarity
bool isValid(const Inventory inv);
void readInventory(fstream &file, const int idx);
void editInventory(fstream &file, const int idx);
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
            case 1:
                file.open(filename, ios::binary | ios::out | ios::app);
                addInventory(file);
                file.close();
                break;
            case 2:
                cout << "Enter desired index: " << endl;
                getline(cin, input);
                stringstream(input) >> entry_idx;
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
            case 3:
                //change record
                cout << "Enter desired index: " << endl;
                getline(cin, input);
                stringstream(input) >> entry_idx;
                if (entry_idx < 0)
                {
                    cout << "Invalid index. Must be a positive integer." << endl;
                    break;
                }

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

bool isValid(const Inventory inv)
{
    //checks validity of numbers. cstring handling is carried out during input
    return inv.cost >= 0 && inv.price >= 0 && inv.quantity >= 0;
}

void addInventory(fstream &file)
{
    Inventory inv;
    
    cout << "Enter item description: " << endl;
    string buffer;
    getline(cin, buffer);
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
    if (inv.quantity < 0)
    {
        cout << "Quantity must be positive." << endl;
        return;
    }

    cout << "Enter cost:" << endl;
    getline(cin, buffer);
    stringstream(buffer) >> inv.cost;
    if (inv.cost < 0)
    {
        cout << "Cost must be positive." << endl;
        return;
    }

    cout << "Enter price:" << endl;
    getline(cin, buffer);
    stringstream(buffer) >> inv.price;
    if (inv.price < 0)
    {
        cout << "Price must be positive." << endl;
        return;
    }

    cout << "Enter date:" << endl;
    getline(cin, buffer);
    if (strlen(buffer.c_str()) < inv.DATE_SIZE)
    {
        strcpy(inv.date, buffer.c_str());
    }
    else
    {
        cout << "String too large. Max " << inv.DATE_SIZE - 1 << " characters." << endl;
        return;
    }

    if (isValid(inv))
    {
        file.write(reinterpret_cast<char *> (&inv), sizeof(Inventory));
        cout << "Success." << endl;
    }
    else
    {
        cout << "Invalid input. Entry not written." << endl;
    }
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

    //copy pasted from addInventory()
    cout << "Enter item description: " << endl;
    string buffer;
    getline(cin, buffer);
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
    if (inv.quantity < 0)
    {
        cout << "Quantity must be positive." << endl;
        return;
    }

    cout << "Enter cost:" << endl;
    getline(cin, buffer);
    stringstream(buffer) >> inv.cost;
    if (inv.cost < 0)
    {
        cout << "Cost must be positive." << endl;
        return;
    }

    cout << "Enter price:" << endl;
    getline(cin, buffer);
    stringstream(buffer) >> inv.price;
    if (inv.price < 0)
    {
        cout << "Price must be positive." << endl;
        return;
    }

    cout << "Enter date:" << endl;
    getline(cin, buffer);
    if (strlen(buffer.c_str()) < inv.DATE_SIZE)
    {
        strcpy(inv.date, buffer.c_str());
    }
    else
    {
        cout << "String too large. Max " << inv.DATE_SIZE - 1 << " characters." << endl;
        return;
    }

    if (isValid(inv))
    {
        //move back to original file position
        file.seekg(idx * sizeof(Inventory), ios::beg);
        file.write(reinterpret_cast<char *> (&inv), sizeof(Inventory));
    }
}

void readInventory(fstream &file, const int idx)
{
    Inventory inv;
    file.seekg(idx * sizeof(Inventory), ios::beg);
    file.read(reinterpret_cast<char *> (&inv), sizeof(Inventory));
    
    if (file.fail())
    {
        cout << "No entry found at index " << idx << '.' << endl;
    }
    else
    {
        cout << setw(17) << left << "Item description" << ": " << inv.desc << endl;
        cout << setw(17) << left << "Item quantity" << ": " << inv.quantity << endl;
        cout << setw(17) << left << "Item cost" << ": " << inv.cost << endl;
        cout << setw(17) << left << "Item price" << ": " << inv.price << endl;
        cout << setw(17) << left << "Date added" << ": " << inv.date << endl;
    }
}