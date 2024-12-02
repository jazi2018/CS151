/* hmwk14.cpp - Tests functions of LinkedList class
 * Author:     Jared Ziv
 * Module:     14
 * Project:    Homework, Parts 1 - 5
 * Problem statement: Construct various functions of a simple linked list
 *      class. Test in main.
 *
 * Algorithm:
 *      add(double x):
 *          1. Set head to a new ListNode with x and head passed to the
 *             constructor. Increment size.
 *          2. If size is 1, set tail to head. (The single node is both)
 * 
 *      isMember(double x):
 *          1. Initialize a ListNode pointer it to head
 *          2. While it != nullptr
 *              a. If it->value is x, return true
 *              b. Set it = it->next
 *          3. Return false
 * 
 *      print():
 *          1. If size is 0, output "(null)" and return
 *          2. Initialize a ListNode pointer it to head
 *          3. While it != nullptr:
 *              a. output it->value
 *              b. Set it = it->next
 * 
 *      reverse():
 *          1. If size is <= 1, the list cannot be reversed. Return.
 *          2. Initialize ListNode pointers curr and prev to head->next
 *             and head, respectively.
 *          3. While curr != nullptr:
 *              a. Initialize a ListNode pointer next to curr->next
 *              b. Set curr->next to prev (flip the pointer)
 *              c. Set prev to curr, and curr to next
 *          4. Set tail to head, and tail->next to nullptr
 *          5. Set head to prev
 *      
 *      search(double x):
 *          1. Initialize ListNode pointer it to head
 *          2. Initialize int idx to 0
 *          3. While it != nullptr:
 *              a. If it->value is x, return idx
 *              b. Set it to it->next and increment idx
 *          4. Return -1
 * 
 *      insert(double x, int pos):
 *          1. If pos < 0, return. The index is invalid
 *          2. Otherwise, if pos is 0, call add(x)
 *          3. Otherwise, if pos < size:
 *              a. Intialize ListNode pointers curr and prev to
 *                 head->next and head, respectively
 *              b. Starting from i = 1, and incrementing while i <
 *                 pos, set prev to curr and curr to curr->next
 *                 every iteration. This will move curr to the
 *                 desired index.
 *              c. Set prev->next to a new ListNode, passing x and
 *                 curr to the constructor. Increment size.
 *          4. Otherwise, set tail->next to a new ListNode, passing
 *             x and curr to the constructor. Update tail to
 *             tail->next. Increment size.
 */
#include "HmwkLinkedList.cpp"
using namespace std;

int main()
{
    //Project 1
    LinkedList list;
    list.add(7.0);
    list.add(8.0);
    list.add(9.0);

    bool test = list.isMember(9.0);
    cout << "9.0 in list: " << (test ? "True" : "False") << endl;
    test = list.isMember(8.0);
    cout << "8.0 in list: " << (test ? "True" : "False") << endl;
    test = list.isMember(5.0);
    cout << "5.0 in list: " << (test ? "True" : "False") << endl;

    //Project 2
    LinkedList empty;
    cout << "\nEmpty list: " << endl;
    empty.print();
    cout << "Populated list: " << endl;
    list.print();
    
    //Project 3
    cout << "\nReversing list..." << endl;
    cout << "Reversed populated list: " << endl;
    list.reverse();
    list.print();

    //Project 4
    cout << "\nSearching for number positions..." << endl;
    int idx = list.search(7.0);
    cout << "Index of 7.0: " << ((idx == -1) ? "Not found" : to_string(idx)) << endl;
    idx = list.search(9.0);
    cout << "Index of 9.0: " << ((idx == -1) ? "Not found" : to_string(idx)) << endl;
    idx = list.search(2.0);
    cout << "Index of 2.0: " << ((idx == -1) ? "Not found" : to_string(idx)) << endl;

    //Project 5
    //insert at beginning
    cout << "\nAdding 5.0 at index 0" << endl;
    list.insert(5.0, 0);
    cout << "New list: " << endl;
    list.print();
    //validate index
    idx = list.search(5.0);
    cout << "Index of 5.0: " << idx << endl;
    //insert in middle
    cout << "Adding 2.0 at index 2" << endl;
    list.insert(2.0, 2);
    cout << "New list: " << endl;
    list.print();
    idx = list.search(2.0);
    cout << "Index of 2.0: " << idx << endl;
    //insert at end
    cout << "Adding 1.0 at end of list" << endl;
    list.insert(1.0, 5);
    cout << "New list: " << endl;
    list.print();
    idx = list.search(1.0);
    cout << "Index of 1.0: " << idx << endl;

    return 0;
}