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
#include <cstring>
#include <sstream>

using namespace std;

struct Inventory
{
    static const int DESC_SIZE = 100, DATE_SIZE = 20;
    char desc[DESC_SIZE], date[DATE_SIZE];
    int quantity;
    double cost, price;
    //default constructor
    Inventory() : desc(""), date(""), quantity(0), cost(0.0), price(0.0) { }
    //parameterized constructor
    Inventory(string desc, string date, int quant, double cost, double price) :
        quantity(quant),
        cost(cost), price(price)
        { 
            strcpy(this->desc, desc.c_str());
            strcpy(this->date, date.c_str());
        }
};

//modularize for clarity
void readInventory(fstream &file, int idx);
Inventory createInventory();

int main()
{
    const string filename = "inventory.bin";
    int total_entries = 1;
    //create / open binary file
    fstream file(filename, ios::binary | ios::in | ios::out);
    //ensures file exists and is created
    if (!file)
    {
        cout << filename << " not found and could not be created. Exiting." << endl;
        exit(1);
    }
    else
    {
        // file.clear();
        // file.seekg(0, ios::beg);
        // //counts total number of entries existing when file was opened
        // while(file)
        // {
        //     file.seekg(sizeof(Inventory), ios::cur);
        //     total_entries++;
        // }
        // file.close();
    }
    //run menu
    cout << "Select one of the following" << endl;
    while (true)
    {
        string sel;
        //selection loop
        while(true)
        {
            cout << "1. Add new records" << endl
             << "2. Display record" << endl
             << "3. Quit program" << endl;
            getline(cin, sel);
            if (sel[0] == '1' || sel[0] == '2' || sel[0] == '3') { break; }
            else { cout << "Invalid input. Please enter 1, 2 or 3." << endl; }
        }

        if (sel[0] == '1')
        {
            //add new record
            Inventory inv = createInventory();
            file.open(filename, ios::binary | ios::out | ios::app);
            file.write(reinterpret_cast<char *> (&inv), sizeof(Inventory));
            file.close();
        }
        else if (sel[0] == '2')
        {
            if (total_entries == 0)
            {
                cout << "No valid entries!" << endl;
            }
            else
            {
                //read record
                while (true)
                {
                    string idx;
                    cout << "Enter desired index out of " << total_entries << ":" << endl;
                    getline(cin, idx);
                    istringstream str(idx);
                    int i;
                    if (str >> i && i > -1) { readInventory(file, i); break;}
                    else { cout << "Please enter a valid index." << endl;}
                }
            } 
        }
        else
        {
            //exit program
            break;
        }
    }
    return 0;
}

void readInventory(fstream &file, int idx)
{
    Inventory inv;
    long start = idx * sizeof(Inventory);
    file.clear();
    file.seekg(start, ios::beg);
    file.read(reinterpret_cast<char *> (&inv), sizeof(Inventory));
    cout << inv.desc; //add rest of functionality later
}

Inventory createInventory()
{
    //define inventory variable
    Inventory inv;

    //define description
    while (true)
    {
        string desc;
        cout << "Enter item description (100 char MAX): " << endl;
        getline(cin, desc);
        // -1 to include null terminator
        if(strlen(desc.c_str()) > inv.DESC_SIZE - 1) { cout << "Description too large." << endl; }
        else { strcpy(inv.desc, desc.c_str()); break; }
    }

    //define quantity
    while (true)
    {
        string quant;
        cout << "Enter item quantity: " << endl;
        getline(cin, quant);
        istringstream str(quant);
        int q_int;
        if (str >> q_int && q_int > -1) { inv.quantity = q_int; break; }
        else { cout << "Please enter a valid, non-negative integer." << endl; }
    }

    //define cost
    while (true)
    {
        string cost;
        cout << "Enter item cost: " << endl;
        getline(cin, cost);
        istringstream str(cost);
        double c_dub;
        if (str >> c_dub && c_dub >= 0) { inv.cost = c_dub; break; }
        else { cout << "Please enter a valid, non-negative double." << endl; }
    }

    //define price
    while (true)
    {
        string price;
        cout << "Enter item price: " << endl;
        getline(cin, price);
        istringstream str(price);
        double p_dub;
        if (str >> p_dub && p_dub >= 0) { inv.price = p_dub; break; }
        else { cout << "Please enter a valid, non-negative double." << endl; }
    }

    //define date
    while (true)
    {
        string date;
        cout << "Enter item description (100 char MAX): " << endl;
        getline(cin, date);
        // -1 to include null terminator
        if(strlen(date.c_str()) > inv.DATE_SIZE - 1) { cout << "Date too large." << endl; }
        else { strcpy(inv.date, date.c_str()); break; }
    }

    return inv;
}