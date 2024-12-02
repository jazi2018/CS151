#pragma once
#include <iostream>
#include <iomanip>
#include "HmwkLinkedList.h"
using namespace std;

void LinkedList::add(double x)
{
    //add new node and adjust size
    head = new ListNode(x, head);
    ++size;

    //if only node, adjust tail
    if (size == 1)
    {
        tail = head;
    }
}

bool LinkedList::isMember(double x)
{
    ListNode * it = head;
    //iterate through linked list
    while (it != nullptr)
    {
        //return true if value is found
        if (it->value == x)
        {
            return true;
        }

        //move to next node
        it = it->next;
    }

    //return false if value is not found
    return false;
}

void LinkedList::print()
{
    //if empty, print null
    if (size == 0)
    {
        cout << "(null)" << endl;
        return;
    }

    //iterate thru list and print each node
    ListNode * it = head;
    while(it != nullptr)
    {
        cout << it->value << endl;
        it = it->next;
    }
}

void LinkedList::reverse()
{
    if (size <= 1)
    {
        //list cannot be reversed
        return;
    }
    //initialize iterators
    ListNode * curr = head->next;
    ListNode * prev = head;
    while (curr != nullptr)
    {
        ListNode * next = curr->next;
        //flip pointer
        curr->next = prev;
        //move iterators forward
        prev = curr;
        curr = next;
    }
    //set new tail to old head; assign next to nullptr
    tail = head;
    tail->next = nullptr;
    //set new head to old tail (currently prev iterator)
    head = prev;
}

int LinkedList::search(double x)
{
    //initialize iterators
    ListNode * it = head;
    int idx = 0;

    //go through list
    while (it != nullptr)
    {
        if (it->value == x)
        {
            return idx;
        }

        //iterate
        it = it->next;
        ++idx;
    }

    //if not found, return -1
    return -1;
}

void LinkedList::insert(double x, int pos)
{
    //out of bounds
    if (pos < 0)
    {
        return;
    }
    //first item
    else if (pos == 0)
    {
        add(x);
    }
    //any position that isnt last
    else if (pos < size)
    {
        ListNode * curr = head->next;
        ListNode * prev = head;
        //move to desired index (starting from idx 1)        
        for(int i = 1; i < pos; ++i)
        {
            prev = curr;
            curr = curr->next;
        }
        //curr at desired index
        prev->next = new ListNode(x, curr);
        ++size;
    }
    //tail of linked list
    else
    {
        //add new node at tail of linked list
        tail->next = new ListNode(x, nullptr);
        //update tail
        tail = tail->next;
        ++size;
    }

}