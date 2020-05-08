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

## Features / Functions
1. Generation of random game sets or events
   - Random passcode for Room B
2. Data structures for storing game status
   - A data structure named "player" will be used to store the player's status
      - Player's inventory
      - Player's location when the player save the game
      - What did the player discover before
      - First stage, second stage status
   - A data structure named "player" will be used to store the player's status
3. Dynamic memory management [Dynamic Memory](http://www.cplusplus.com/doc/tutorial/dynamic/)
   - A dynamic array would be used to store the player's items 
4. File input/output (e.g., for [loading/saving game status](http://www.cplusplus.com/forum/beginner/106630/))
   - A .txt file will store a player's inventory, solved puzzle, position and progress.
      - Using boolean data type to determine whether a room's door's lock has been unlocked or not
      - Using string data type to store the player's position (e.g. "A")
      - Player's inventory
      - What did the player discover before
      - Status of stages the player in
      - Passcode of Room B (Since it is randomized)
5. Program codes in multiple files
   - Separate program codes to multiple files to make it easier to read and more orgranised
      - A "player.h" to define the data structure of the player
      - A "puzzle.h" to define the data structure for the puzzles
      - A "LoadGame.h" is responsible to load all data from the file input
      - A "SaveGame.h" is responsible to save all data to a file

## Instructions
Download all files except for the .txt file. Use your terminal and move to the directory of the game that is located at. In your terminal, type `make main` to compile the game into executable file called "main". Type `./main` to start the game and follow the in-game instructions. 
