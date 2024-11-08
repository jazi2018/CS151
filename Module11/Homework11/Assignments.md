## Project 2 – Recursive Member Test (5 points)
Programming Challenge #6:  Write a recursive Boolean function named  isMember.  The function should accept three parameters: an array of integers, the size of the array, and an value to be searched for in the array.  The function should return  true  if the value is found in the array or  false  if the value is not found. 

Demonstrate the use of the function in a program that asks the user to enter values into an array of numbers, then prompts for value(s) to be searched for in that array.  Search for two numbers in the array and two numbers that aren't in the array.

## Project 3 – Palindrome Test (10 points)
Programming Challenge #8:  (Haven't we seen this before?)  A palindrome is a string such as "madam", "radar", "dad", and "I ", which reads the same forward and backward.  The empty string is regarded as a palindrome.  Palindromes consider only letters and numbers.  Spaces and punctuation should be ignored.

For example, the following strings are also a palindromes:  "Sit on a potato pan, Otis!", "Red roots to order", and "Bob 7117 Bob".

Write a recursive function with the heading:

```cpp
bool isPalindrome(string str, int lower, int upper)
```

that returns  true  if and only if the part of the string  str  in positions  lower  through  upper  (inclusive at both ends) is a palindrome.  Test your function by writing a main function that repeatedly asks the user to enter strings.  These strings are then tested for palindromicity (is that even a word?).  The program ends when the user presses the ENTER key without typing any characters before it.

Demonstrate your program using the following test cases:

- reed
- oreo
- Kayak
- Deed
- 1x2x3x4x5
- A Toyota’s a Toyota.
- Stressed desserts.
- 74 ABC ba47
- Never odd or even.
- A man, a plan, a canal --  Panama.

## Project 4 - Winning a game of Nim  (10 points extra credit)
The game of Nim has many variations, but perhaps the simplest is as follows for two players:
A random number is sticks are placed on a table.
Each player alternates taking turns picking up either one stick or two sticks.
The player to pick up the last stick loses the game.
 
Here are three possible outcomes towards the end of the game (three base cases), assuming that it is your turn:
- there is one stick left, in which case you lose.
- there are two sticks left, so you pick up one and leave the other for your opponent.
- there are three sticks left, so you pick up two and leave the final stick for your opponent.

This means that if you wind up with two or three sticks and it is your turn, you always can win.  By extension, if you can leave your opponent with 4 sticks, then they must pick either 1 or 2, leaving you with 2 or 3, so you always can win.  (Another way of saying the same thing is that if it's your turn and there are 4 sticks left, you probably will lose.) 

Can you think of an optimal strategy for picking up sticks?  Do you see a pattern?

Using a recursive function, see if you can develop a winning strategy so that given "n" sticks remaining, the player whose turn it is can always guarantee a win.  Simulate a game with two players starting with "n" sticks.  Remember that your opponent can also move optimally, as well.

Run your program for the starting values of "n" from 3 to 20 determine whether the first player can always win.