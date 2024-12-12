# Final Project | Text Based RPG

//introduction here

## Requirements fulfilled

Items bolded on this list of requirements are present in the project:
- **Inheritance**
- Polymorphism
- Text File I/O
- Recursion
- Exceptions
- **An overloaded operator**
- An abstract class of your own design
- A data structure with an iterator (list, vector, stack, queue, set...) of your own design
- **A data structure from the C++ Standard Template Library (STL)**

## TODO:

1. Create Game class for testing with main game loop
2. ~~Create item class~~
3. ~~Complete Entity / Player class~~ - implement inventories
4. Create a map class
    - 2x2 array - should track position of players and enemies
    - Have a container with all enemies and their positions. Function to check player position and return anything within the player position index.
    - Consider a room class which could exist within the map class (if wanting to be extra)
5. Implement game saving by writing to a binary file the game class
6. Implement game loading