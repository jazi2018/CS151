/*

*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <memory>

using namespace std;

struct Stone
{
    char letter;
    int attempts;
    Stone(char l, int a)
    {
        letter = l;
        attempts = a;
    }
};

int main()
{
    srand(time(NULL));

    //create array of 10 unique pointers to stone structs
    unique_ptr<Stone> slots[10];

    //iterate through characters a-j
    for (char letter = 'A'; letter <= 'J'; letter++)
    {
        //at stone letter
        int attempt_ctr = 1;
        while(true)
        {
            int index = rand() % 10;
            if (! slots[index])
            {
                unique_ptr<Stone> new_stone(new Stone(letter, attempt_ctr));
                slots[index] = move(new_stone);
                break;
            }
            else
            {
                attempt_ctr++;
            }
        }
    }

    //report results
    cout << " ** Sorted by slot **" << endl;
    cout << "Slot  Letter  Attempts" << endl;
    cout << "----  ------  --------" << endl;
    int total_attempts = 0;
    for (int i = 0; i < 10; i++)
    {
        total_attempts += slots[i]->attempts;
        printf("%4d %7c %9d\n", i, slots[i]->letter, slots[i]->attempts);
    }
    cout << "Total attempts: " << total_attempts << endl;

    cout << "** Sorted by letter **" << endl;
    cout << "Letter  Slot  Attempts" << endl;
    cout << "------  ----  --------" << endl;
    total_attempts = 0;
    for (char letter = 'A'; letter <= 'J'; letter++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (slots[i]->letter == letter)
            {
                total_attempts += slots[i]->attempts;
                printf("%6c %5d %9d\n", slots[i]->letter, i, slots[i]->attempts);
            }
        }
    }
    cout << "Total attempts: " << total_attempts << endl;

    return 0;
}