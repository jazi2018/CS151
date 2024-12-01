/* lab14_proj1.cpp - Demonstrates LinkedList class functionality
 * Author:     Jared Ziv
 * Module:     14
 * Project:    Lab, Part 1
 * Problem statement: Add functions to linked list class. Added display(),
 *      remove(), removeAt(), lastIndexOf(), set(), and contains().
 *
 * Algorithm:
 *      display():
 *          1. If list is empty, output "(null)" and return
 *          2. Initialize a node pointer to head
 *          3. While the pointer != nullptr:
 *              a. Output the pointer->data
 *              b. Set the pointer to itself->next
 *      
 *      remove():
 *          1. If the list is emtpy, return false
 *          2. If the data at head is the same as the passed data:
 *              a. Create a pointer to the next node
 *              b. Delete the data at the head pointer
 *              c. Set the head pointer to the next node
 *              d. Decrement size
 *              e. If head was the only node, set tail to nullptr as well
 *              f. Return true
 *          3. Initialize node pointer before to head and curr to
 *             head->next
 *          4. While curr != nullptr
 *              a. If curr->data is myData:
 *                  - Set before->next to curr->next
 *                  - Delete curr
 *                  - Decrement size
 *                  - Return true
 *              b. Set before to curr
 *              c. Set curr to curr->next
 *          5. Return false
 * 
 *      removeAt():
 *          1. If the passed index is negative or >= size, throw
 *             out_of_range exception
 *          2. Initialize a node pointer del_node to nullptr and T data
 *             to T()
 *          3. If index is 0:
 *              a. Set del_node to head
 *              b. Set data to del_node->data
 *              c. Set head to head->next
 *              d. If head is now nullptr, set tail to nullptr
 *          4. Otherwise:
 *              a. Set del_node to head->next
 *              b. Initialize node pointer prev_node to head
 *              c. For i iterations, while i < index - 1:
 *                  - set del_node to del_node->next
 *                  - set prev_node to prev_node->next
 *              d. Set data to del_node->data
 *              e. Set prev_node->next to del_node->next
 *              f. If tail is del_node, set tail to prev_node
 *          5. Delete del_node, decrement size, and return data
 * 
 *      lastIndexOf():
 *          1. Initialize int data_idx to -1, and idx to 0
 *          2. Initialize node pointer it to head
 *          3. While it != nullptr:
 *              a. If it->data is myData, set data_idx to idx
 *              b. Set it to it->next and increment idx
 *          4. Return data_idx
 * 
 *      contains():
 *          1. Initialize node pointer it to head
 *          2. While it != nullptr:
 *              a. If it->data is myData, return true
 *              b. Set it to it->next
 *          3. Return false
 * 
 *      set():
 *          1. If index is out of range (same as removeAt()), return
 *             T()
 *          2. Initialize node pointer it to head
 *          3. Initialize T data to T()
 *          4. Iterate it to desired index using the same method as
 *             removeAt()
 *          5. Set data to it->data
 *          6. Set it->data to myData
 *          7. Return data
 */
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> list;

    cout << "Testing display() function:" << endl;
    cout << "Empty list: " << endl;
    list.display();

    cout << "\nAdding elements 10, 20, 30, 20, and 40." << endl;
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);
    list.addLast(20);
    list.addLast(40);
    cout << "List after adding elements: " << endl;
    list.display();

    cout << "\nTesting remove() function:" << endl;
    cout << "Removing 20 from the list." << endl;
    bool removed = list.remove(20);
    cout << "Remove successful: " << (removed ? "Yes" : "No") << endl;
    cout << "List after removing 20: " << endl;
    list.display();

    cout << "\nTesting removeAt() function:" << endl;;
    cout << "Removing element at index 2." << endl;
    try {
        int removed_value = list.removeAt(2);
        cout << "Removed value: " << removed_value << endl;
        cout << "List after removing element at index 2: " << endl;
        list.display();
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\nTrying to remove element at (invalid) index 10." << endl;
    try {
        list.removeAt(10);
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\nTesting set() function:" << endl;
    cout << "Setting index 1 to 50." << endl;
    try {
        int old_value = list.set(1, 50);
        cout << "Old value at index 1: " << old_value << endl;
        cout << "List after setting 50 at index 1: " << endl;
        list.display();
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\nTrying to set value at (invalid) index 10." << endl;
    int invalid_set = list.set(10, 100);
    cout << "Returned: " << invalid_set << endl;
    cout << "Current list: " << endl;
    list.display();

    cout << "\nTesting lastIndexOf() function:" << endl;
    list.addLast(30);
    cout << "Added 30 to the end of the list." << endl;
    cout << "Current list: " << endl;
    list.display();
    int last_index = list.lastIndexOf(30);
    cout << "Last index of 30: " << last_index << endl;

    cout << "\nTesting contains() function:" << endl;
    bool contains_50 = list.contains(50);
    bool contains_60 = list.contains(60);
    cout << "List contains 50: " << (contains_50 ? "Yes" : "No") << endl;
    cout << "List contains 60: " << (contains_60 ? "Yes" : "No") << endl;

    return 0;
}