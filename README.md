# escaperoom
## Team member 
Ng To San (3035601619),  Yau Chin Pang (3035689257)

## Game Description 
We would design an escape game, which includes kinds of general concepts in other similar games, such as discovering various clues and items, mysterious traps and baits, different versions of endings. To motivate the players to continue the game, this escape game will include the respawn function with random respawn points instead of restarting the current state. 

## Features / Functions
1. Generation of random game sets or events
   - Random respawn point
   - Magic items (e.g. dice) for random rewards/penalties spawned at random time
   - Random passcodes or clues 
2. Data structures for storing game status
   - Using boolean data type to determine whether one particular puzzle has been solved or not
   - Using string data type to store the player's position (e.g. "A3")
   - A display bar to display the items in the backpack & update with the items received
   - Commands to display player current position (Paper map exists but without position update)
3. Dynamic memory management [Dynamic Memory](http://www.cplusplus.com/doc/tutorial/dynamic/)
   - A dynamic array would be used to store the player's items 
4. File input/output (e.g., for [loading/saving game status](http://www.cplusplus.com/forum/beginner/106630/))
   - A .txt file will store a player's inventory, solved puzzle, position and progress. 
5. Program codes in multiple files
6. Proper indentation and naming styles 
   - Indentation: based on [Indentation style](https://en.wikipedia.org/wiki/Indentation_style)
   - Naming Style: Function names directly based on own function 
      e.g. `Action(command)` for executing differen commands, `UseItem(item)` for using specific item, etc...
7. In-code documentation
   - Command Explanations
   - Item Explanations
