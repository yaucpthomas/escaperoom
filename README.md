# Escape Room
## Team member 
- Ng To San      3035601619
- Yau Chin Pang  3035689257

## Game Description with Basic Game Rules
We would design an escape game, which includes kinds of general concepts in other similar games, such as discovering various clues, items, mysterious traps and traces, and different versions of endings. In this escape game, we will adapt the true story of the Cold War, which is a well-known espionage and betrayal in the Soviet Union. Players will act as a betrayed spy ([Pyotr Popov](https://en.wikipedia.org/wiki/Pyotr_Semyonovich_Popov)), who had just been caught and charged with treason with sufficient evidence before being ready to leave from his own intelligence agency. After long-time inhumane torture, the spy could only remember his own mission - get all the necessary information and escape asap, but unfortunately, he couldn't remember all the details of the information.

Therefore, the rules to complete the mission are:
1. Figure out the way(s) to escape from the old building *1 
2. Find back all the necessary information correctly
3. Find ways to make CIA (America) recognize own identity after successfully escaping
   (*1 The old building used to be a human experiment factory, which may retain traces of people trying to escape from here.)

To motivate the players to continue the game, though a bit fantastical, this escape game will include the respawn function with random respawn points instead of restarting the current state. 

## Features / Functions
1. Generation of random game sets or events
   - Random passcodes or clues 
2. Data structures for storing game status
   - A data structure named "player" will be used to store the player's status
      - Player's name
      - Player's inventory
      - Player's location when the player save the game
      - Player's seed for randomization at the beginning of the game
      - Whether the player discovered a hint or not
      - Whether the player solved a puzzle or not
   - A display bar to display the items in the backpack & update with the items received
   - Commands to display player current position (Paper map exists but without position update)
3. Dynamic memory management [Dynamic Memory](http://www.cplusplus.com/doc/tutorial/dynamic/)
   - A dynamic array would be used to store the player's items 
4. File input/output (e.g., for [loading/saving game status](http://www.cplusplus.com/forum/beginner/106630/))
   - A .txt file will store a player's inventory, solved puzzle, position, seed of randomization and progress. 
      - Using boolean data type to determine whether one particular puzzle has been solved or not and a clue or hint has been discovered or not
      - Using string data type to store the player's position (e.g. "A3")
      - A integer showing how many items the players had, followed by a list of items
      - The seed for randomization will be stored to ensure the hints, clues and passcodes will remain unchanged
5. Program codes in multiple files
   - Separate program codes to multiple files to make it easier to read and more orgranised
      - A "tutorial.h" is about teaching players how the game works 
      - A "map.h" includes all the commands regarding the map (e.g. "OpenMap")
      - A "LoadGame.h" is responsible to load all data from the file input
      - A "SaveGame.h" is responsible to save all data to a file
6. Proper indentation and naming styles 
   - Indentation: K&R style based on [Indentation style](https://en.wikipedia.org/wiki/Indentation_style)
   - Naming Style: Function names directly based on own function 
      e.g. `Action(command)` for executing different commands, `UseItem(item)` for using specific item, etc...
7. In-code documentation
   - Command Explanations
   - Item Explanations
