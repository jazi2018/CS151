/* final_main.cpp - Main cpp file to run
 * Author:     Jared Ziv
 * Module:     Final Project
 *
 * Algorithm:
 *   1.  Seed rand() using time(NULL)
 *   2. Instantiate Game and call runGame() function.
 * 
 *      runGame():
 *      runGame contains most of the logic for the game loop.
 *      1. Display map using Map.print()
 *      2. Display options for movement and others and their
 *         respective inputs.
 *      3. Take input, and use a switch statment, where each
 *         input has a case for its action.
 *      4. Check if player is on same coordinate as a monster.
 *         If so, call combat() with the monster.
 *      5. Otherwise, check if player is on same coordinate as
 *         an item. If so, add the item to the player's inventory.
 *      6. Check if any monsters are alive. If they are, continue;
 *      7. If not, prepare for next round. Iterate round, set player
 *         coordinates to 0,0. Store monster attack and health in
 *         temporary variables. Store item magnitude in temporary
 *         variable. Delete [] monsters and delete [] items, and
 *         increment the number of each of them by one.
 *         Allocate new memory for monsters and items using the
 *         numbers of each of them. Populate monsters with Monster
 *         objects, each with the health variable * 2 and attack
 *         variable * 2. Populate items with Item objects, each
 *         with the previous magnitude + 10. There should be a
 *         25% chance for it to be a weapon.
 *         Set map to a Map object, passing parameterized constructor
 *         variables. Call populate, passing the monsters and items
 *         pointers.
 *      8. This loop will be repeated until the player dies, when
 *         the program will return from the function, come to main,
 *         and exit.
 */
#include <iostream>
#include <ctime>
#include "Classes\Game.h"
using namespace std;

int main()
{
    //seed
    srand(time(NULL));

    //create new game class and run
    Game game;
    game.runGame();

    return 0;
}