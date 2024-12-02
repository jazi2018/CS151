## Review Questions (10 points)
Each question below is based on the textbook's definition of the  ListNode  structure (given below):
```cpp
struct ListNode {
      double value ;
      ListNode *next ;
      // Constructor
      ListNode (double new_value, ListNode *new_next = nullptr
      {  
          value = new_value ;
          next = new_next ;
      }
} ;
  ```
 
10. Write a function with the heading:
```cpp
void printSecond(ListNode *ptr)
```
which prints the value stored in the second node of the list passed as a parameter.  The function should print an error message and stop running the program if the list passed to it has less than 2 nodes.

12. Write a function with the heading:
```cpp
ListNode * removeFirst(ListNode *ptr)
```
which is passed a linked list as parameter and returns the new head of the list:  That is, it removes the first node and returns what is left.  The function should deallocate the storage of the removed node.  The function returns  nullptr  if the list passed to it is empty.

For each of the following program fragments, predict what the output will be.

14.
```cpp
ListNode *p = new ListNode(56.4) ;
p = new ListNode(34.2, p) ;
cout << (*p).value << endl << p->value ;
```
16.
```cpp
ListNOde *p = new ListNode(56.4, new ListNode(31.5)) ;
ListNode *q = p ;
while (q->next != nullptr)
{
    q = q->next;
}
cout << q->value ;
```

 
## Programming Challenges (20 points)
These Challenges are also taken from Chapter 17 (9th edition) or Chapter 18 (10th edition) of our textbook. 

Please combine them into a single project.

### Project 1 – Simple LinkedList Class
Programming Challenge #1:  Using an appropriate definition of  ListNode,  design a simple linked list class with only two member functions and a default constructor:
```cpp
  void add(double x) ;
  bool isMember(double x) ;  
  Linkedlist ( ) ;
```
The  add  function adds a new node containing  x  to the front (head) of the list, while the  isMember  function tests to see if the list contains a node with the value  x.  Test your linked list class by adding various numbers to the list and then testing for membership.

Sample Algorithm:

- Create a new class  LinkedList.h
- Add a structure  ListNode  from the textbook
- Add a LinkNode pointer named  head
- Create definitions for the constructor,  add,  and  isMember  functions
- Create a .cpp file which will define the member functions
- In the constructor, initialize the  head  variable to  nullptr
- In the  add  function use:
  ```cpp
  head = ListNode(x, head) ;
  ```
    where x is the value being inserted at the front of the list

- In the  isMember  function
    - Create a  ListNote  pointer and initialize to  head
    - Traverse the list.  If the value found is equal to the parameter passed to  isMember,  then return  true.  If at the end of the list, then return  false.

Once you've tested your  ListList  class, change  main  to:

- Create a  LinkedList  object using the default constructor.
- Add nodes 7.0, 8.0, and 9.0.
- Using  isMember,  test to see if 9.0 is in the list (should return  true),  if 7.0 is in the list (should return  true), and if 5.0 is in the list (should return  false).

### Project 2 – List Print (continued)
Programming Challenge 3:  Modify the list class you created in the previous challenge to add a  print  member function .
```cpp
  void print() ;  
```
Change  main  to test the class by printing an empty list and a non-empty list.  When the list is empty, print something like "(empty)"  or  "(null)".

### Project 3 – List Reverse (continued)
Programming Challenge #6:  Modify your  LinkedList  class above by adding a member function for reversing the list:
``` cpp
  void reverse() ;  
```
The member function rearranges the nodes in the list so that their order is reversed.  You should do this without creating or destroying nodes.  (Hint:  Traverse the list just changing pointers.)

Test your new function by reversing the contents of a  LinkedList.

### Project 4 – List Search (continued)
Programming Challenge #7:  Modify the list class to include a member function:
```cpp
  int search(double x) ;  
```
It should return the position of a number  x  on the list.  The first node in the list is at position 0, the second node is at position 1, and so on.  If  x  is not found on the list, the search should return -1. 

Test the new member function by searching for two elements which are in the list, then searching for an element which is not in the list.

### Project 5 – Member Insertion by Position (continued)
Programming Challenge #8:  Modify the list class above by adding a member function for inserting a new item at a specified position:
```cpp
  void insert(double x, int pos) ; 
```
A position of 0 means that  x  will become the first item on the list, a position of 1 means that  x  will become the second item on the list, and so on.  A position equal to, or greater than, the length of the list means that the  x  is placed at the end of the list.  Test your function by inserting an element at the head of a list, in the middle of a list, and at the end of a list.

Consolidate all Programming Challenges above into a single  LinkedList  class and provide all required tests in a single version of  main:

Please put  main  in its own file with a complete opening comment block and comments throughout the code.
In the output, make sure to identify at each step what is being demonstrated.
Submit all program files, screen snips of the output of your programs, and a document with the answers to the Review Questions.