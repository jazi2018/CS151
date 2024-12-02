#pragma once
using namespace std;

struct ListNode
{
    double value;
    ListNode * next;

    ListNode(double new_value, ListNode * new_next = nullptr) :
    value(new_value), next(new_next) {}
};

class LinkedList
{
    private:
        ListNode * head;
        ListNode * tail;
        int size;
    public:
        LinkedList() : head(nullptr), tail(nullptr), size(0) {}

        //member functions
        void add(double x);
        bool isMember(double x);
        void print();
        void reverse();
        int search(double x);
        void insert(double x, int pos);
};