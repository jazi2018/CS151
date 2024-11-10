/* hmwkN_projN.cpp - Uses a recursive algorithm to win Nim
 * Author:     Jared Ziv
 * Module:     11
 * Project:    Homework, Part 4
 * Problem statement: Using a recursive function, see if you can develop a winning
 *      strategy so that given "n" sticks remaining, the player whose turn it is can
 *      always guarantee a win. Simulate a game with two players starting with "n" sticks.
 *
 * Algorithm:
 *  1. If sticks == 1, return !player_turn (current player loses)
 *  2. Otherwise:
 *      a. If sticks % 3 == 2, return a recursive call and decrement the sticks by 1
 *         while also passing !player_turn (it is the other players turn)
 *      b. If sticks % 3 == 0, return playNim(sticks - 2, !player_turn)
 *      c. Otherwise (if sticks % 3  == 1), gen a random number and subtract it from
 *         sticks. Pass to a recursive call. In this case the player whos turn it is
 *         has already lost
 */
#include <iostream>
#include <random>
#include <time.h>
#include <iomanip>
//#define DEBUG

using namespace std;

bool playNim(int sticks, bool my_turn);

int main()
{
    int win_count = 0, lose_count = 0;
    cout << "       Nim Results" << endl;
    for (int i = 3; i <= 20; i++)
    {
        bool win = playNim(i, true);
        win ? win_count++ : lose_count++;
        string output = win ? "First player wins" : "First player loses";
        cout << left << setw(5) << i << ": " << output << endl;
    }
    cout << endl << "       Total Results" << endl;
    cout << left << setw(10) << "Wins" << ": " << win_count << endl;
    cout << left << setw(10) << "Losses" << ": " << lose_count << endl;
    return 0;
}

bool playNim(int sticks, bool player_turn)
{
    //base case: one stick left
    if (sticks == 1)
    {
        //if player_turn, player loses so false gets returned
        //vice versa is also true
        return !player_turn;
    }
    //recursive case
    else
    {
        if (sticks % 3 == 2)
        {
            //%3 == 2 means that the player should pick up 1 stick
            //i.e. 2 sticks remaining : 2 % 3 = 2 : player picks up 1 to win
            return playNim(sticks - 1, !player_turn);
        }
        else if (sticks % 3 == 0)
        {
            //player should pick up 2 sticks
            //i.e. 3 sticks remaining : 3 % 3 = 0 : player picks up 2 to win
            return playNim(sticks - 2, !player_turn);
        }
        //in the case that sticks % 3 == 1, the player whos turn it is is LOSING
        //assuming optimal play. It doesnt matter what number they pick up, so
        //here a random number is selected
        else
        {
            int num = rand() % 2 + 1;
            return playNim(sticks - num, !player_turn);
        }
    }
}

/* PLAYER TURN
1 = L
2 = W
3 = W
4 = L
5 = W
6 = W
7 = L
8 = W
etc. if sticks % 3 = 1, the player whos turn it is loses
     assuming optimal play from both players
*/