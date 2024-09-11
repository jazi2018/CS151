/*
project2.cpp: use two techniques to fill dynamically allocated 2D arrays with random numbers
Author: Jared Ziv
Module 3, Homework 3
Project 2

Problem statement: Use two methods to dynamically allocate two dimensional arrays from the
    heap. Then, populate the arrays with random integers. Report the values of the arrays
    including row totals and averages. Finally, deallocate the arrays.

Algorithm:
    1. Seed rand() using the time library
    2. Allocate a one dimensional array of 20 ints from the heap
    3. Iterate through the array, fill with rand() % 99 + 1 (1-99) at each iteration. Add the 
       value generated by rand() to a variable storing the running total.
    4. After storing the value, print the number.
    5. Calculate and report the average by dividing the total by 20. Report the total.
    6. Dynamically allocate an array of arrays by first allocating an array equal to the
       height (4) of the 2d array. Then, iterate through each index of the existing array and
       allocate a new array equal to the width (5) 
    7. Using the first array, print each row by iterating through, using a counter for rows
       and columns. Nested in both for loops, the index being printed is equal to the row
       counter times the width of the array (5), plus the column counter
       On each row increment, report the new row
       Include a variable to calculate the average of each row. Report the average every
       row increment
       After printing the value, assign the value to the second dynamically allocated
       array at the relevant position (i.e. arr[row][col])
    8. Iterate through the second (2D) dynamically allocated array, printing each row
       and totaling + calculating the average. Report these at the end of every row
       iteration. When the loop is done, report the overall total and average
    9. Loop through the 2D array, using delete on one row at a time
   10. Delete the original array
*/

#include <iostream>
#include <time.h>

using namespace std;

int main()
{
   srand(time(NULL));
   int row_total = 0, total = 0; //use two variables, one for each row and one overall
   float average = 0;
   int arr_length = 20;

   int *base_array = new int[arr_length];

   cout << "          ** Original array of 20 numbers **" << endl;
   for (int i = 0; i < arr_length; i++) //iterate through array
   {
      int random_num = rand() % 99 + 1; //generate 1-99
      base_array[i] = random_num;
      total += random_num;
      cout << base_array[i] << " ";
   }
   cout << endl;
   average = (float)total / arr_length;
   printf("            Total: %d  Average: %.2f\n", total, average);

   //reset total and average values
   total = 0;
   average = 0;

   //assign height and width variables for visual clarity
   int height = 4, width = 5;

   //create array of arrays
   int **arr_of_arr = new int *[height];
   for (int row = 0; row < height; row++)
   {
      arr_of_arr[row] = new int[width];
   }

   cout << endl << "         *** Original array as a 4 x 5 ***" << endl;
   //iterate through original array as a 2D array
   for (int row = 0; row < height; row++)
   {
      cout << "Row " << row << ":";
      for (int col = 0; col < width; col ++)
      {
         int index = (row * width) + col;
         row_total += base_array[index];
         printf("%4d", base_array[index]);

         //assign index of base array to corresponding position in array of arrays
         arr_of_arr[row][col] = base_array[index];
      }
      //calculate relevant values and report
      total += row_total;
      average = (float)row_total / width;
      printf("   Total:%5d  Average:%6.2f\n", row_total, average);
      row_total = 0;
   }
   //calculate and print overall array values
   average = (float)total / arr_length;
   printf("                       Grand Total:%5d  Average:%6.2f\n", total, average);


   //reset row and overall total
   row_total = 0;
   total = 0;

   cout << endl << "         *** Using an array of arrays ***" << endl;
   //iterate through array of arrays
   for (int row = 0; row < height; row++)
   {
      cout << "Row " << row << ":";
      for (int col = 0; col < width; col++)
      {
         printf("%4d", arr_of_arr[row][col]);
         //add current index to row total
         row_total += arr_of_arr[row][col];
      }
      //add the whole row to the grand total, calc row average
      total += row_total;
      average = (float)row_total / width;
      printf("   Total:%5d  Average:%6.2f\n", row_total, average);
      //reset row_total for next iteration
      row_total = 0;
   }
   average = (float)total / arr_length;
   printf("                       Grand Total:%5d  Average:%6.2f\n", total, average);

   //deallocate array of arrays
   for (int row = 0; row < height; row++)
   {
      //delete each nested array
      delete[] arr_of_arr[row];
   }
   //delete parent array
   delete[] arr_of_arr;

   //deallocate original array
   delete[] base_array;

   return 0;
}