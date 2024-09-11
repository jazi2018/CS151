/*project1.cpp contains code for project 1 of homework 3, involves dynamic heap
    memory allocation with arrays
Author: Jared Ziv
Module 3, Homework 3
Project 1

Problem Statement: Dynamically allocate an array of user defined size, storing
    name and score of students. Sort array in ascending order, calculate and 
    report average score.

Algorithm:
    1. Prompt for user input and store in size variable
    2. Allocate an array from the heap based on user input
    3. Loop through the indeces of the array (starting at 0), prompting the
       user for name and score input at each index. Verify that the input
       is valid. Store the input.
    4. After storing the input, add the value of the input to a total_score
       variable.
    5. After filling the array, sort the array using insertion sort
    6. Calculate average score by dividing total_score by size
    7. Report array with names and scores, as well as average score
*/
#include <iostream>
#include <iomanip>

using namespace std;

//score class to store in arrays
class Score
{
    private:
        float score;
        string name;
    public:
        Score() //default constructor
        {
            score = 0;
            name = "";
        } 
        Score(int sc, string nm) //parameterized constructor
        {
            score = sc;
            name = nm;
        }
        ~Score() //destructor
        {
            /*
            including code below will print this every time a temp is created
            and destroyed in the sorting algorithm
            */
           //cout << "Score of " << name << " destructed" << endl;
        }
        float getScore()
        {
            return score;
        }
        string getName()
        {
            return name;
        }
        void setScore(float s)
        {
            score = s;
        }
        void setName(string n)
        {
            name = n;
        }
};

void insertionSort(Score arr[], int size);

int main()
{
    //prompt for user input and store in size variable
    int size = 0;
    float total_score = 0;

    cout << "Please enter number of test scores." << endl;
    cin >> size;

    //allocate an array from the heap based on user input
    Score *score_array = new Score[size];

    //loop through the indeces of the array
    for (int i = 0; i < size; i++)
    {
        //prompt user for score and name input
        string name_input = "";
        int score_input = 0;
        if ((score_array + i)->getName() == "") //if invalid int, skips this step when loop is repeated
        {
            cout << "Please enter name of student " << i + 1 << ":" << endl;
            cin >> name_input;
            (score_array + i)->setName(name_input);
        }

        cout << "Please enter " << (score_array + i)->getName() << "'s score:" << endl;
        cin >> score_input;
        //validate user input
        if (score_input < 0)
        {
            cout << "Test score cannot be negative." << endl;
            //restart current iteration
            i--;
            continue;
        }
        //store input in score_array
        (score_array + i)->setScore(score_input);
        total_score += score_input;
    }

    //sort array
    insertionSort(score_array, size);

    //calculate average score
    float avg_score = total_score / size;

    //report array
    cout << " Name       Score" << endl;
    cout << "-------    -------" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << setw(10) << left << (score_array + i)->getName();
        cout << right << setw(8) << setprecision(2) << fixed << (score_array + i)->getScore() << endl;
    }
    cout << "Average score: " << avg_score << endl;

    delete [] score_array;

    return 0;
}

void insertionSort(Score arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && (arr + j)->getScore() < (arr + j - 1)->getScore())
        {
            Score temp = *(arr + j);
            *(arr + j) = *(arr + j - 1);
            *(arr + j - 1) = temp;
            j--;
        }
    }
}