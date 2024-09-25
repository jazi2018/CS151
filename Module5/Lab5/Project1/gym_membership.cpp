/*
gym_membership.cpp - Track members at a gym as well as total visits and active members
Author:     Jared Ziv
Module:     5
Project:    1 (Lab)
Problem Statement: Demonstrate the use of static variables through a member struct
        which tracks various information about a gym member.

Algorithm:
    Followed instructions listed on lab page.
*/
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const double BASIC_RATE = 42.75,   
             PREMIUM_RATE = 60.00;

struct Member
{
    static int 
        total_visits,      // all visits from members  
        active_members,    // total members active in gym  
        last_id;           // id assigned to newest member
    
    int id;         // id of this member
    string name;    // name of this member
    char type;      // rate (B = basic, P = premium)  
    int visits;     // visits by this member

    Member(string name, char type) {  
        this->name = name ;
        this->type = type ;
        visits = 0 ; 
        active_members++ ; 
        id = last_id++ ; 
    }

    ~Member(){
        active_members--;
    }
} ;

// Define static variables
int Member::total_visits = 0 ; 
int Member::active_members = 0 ;  
int Member::last_id = 100000 ; 

void visit(Member &member)
{
    member.visits++;
    member.total_visits++;
}

int main()
{
    srand(time(NULL));

    vector<Member *> member_structs;
    member_structs.reserve(4);

    Member * oprah = new Member("Oprah Winfrey", 'P');
    member_structs.push_back(oprah);

    Member * fluffy = new Member("Fluffy Iglesias", 'P');
    member_structs.push_back(fluffy);

    Member * charlie = new Member("Charlie Sheen", 'B');
    member_structs.push_back(charlie);

    Member * leona = new Member("Leona Helmsley", 'B');
    member_structs.push_back(leona);

    member_structs.erase(member_structs.begin() + 2); //delete charlie sheen from vector
    delete charlie; //deallocate charlie
    
    cout << "ID       Name           Visits  Type   Rate" << endl;
    cout << "-------  -------------  ------  ----   ----" << endl;
    for (int i = 0; i < member_structs.size(); i++)
    {
        int visits = rand() % 16 + 5; //5-20
        while (visits > 0)
        {
            visit(*member_structs.at(i));
            visits--;
        }

        double rate;
        //determine rate
        switch(member_structs.at(i)->type)
        {
            case 'B':
                rate = BASIC_RATE;
                break;
            case 'P':
                rate = PREMIUM_RATE;
                break;
            default:
                return -1;
        }

        //report member (using same assignment loop)
        printf("%6d %-16s %5d   %-3c    $%4.2f\n", member_structs.at(i)->id,
                                         member_structs.at(i)->name.c_str(),
                                         member_structs.at(i)->visits,
                                         member_structs.at(i)->type,
                                         rate);
    }
    cout << "Total visits: " << Member::total_visits << endl;
    cout << "Active members: " << Member::active_members << endl;

    //clean up the heap
    while (member_structs.size() > 0)
    {
        //delete last object in pointer
        delete member_structs.back();

        //remove (now dangling) pointer
        member_structs.pop_back();
    }
    return 0;
}