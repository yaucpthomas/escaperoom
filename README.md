# escaperoom
## Team member 
Ng To San (3035601619),  Yau Chin Pang (3035689257)

## Game Description with basic game rules
We would design an escape game, which includes kinds of general concepts in other similar games, such as discovering various clues, items, mysterious traps and traces, and different versions of endings. In this escape game, we will adapt the true story of the Cold War, which is a well-known espionage and betrayal in the Soviet Union. Players will act as a betrayed spy ([Pyotr Popov](https://en.wikipedia.org/wiki/Pyotr_Semyonovich_Popov)), who had just been caught and charged with treason with sufficient evidence before being ready to leave from his own intelligence agency. After long-time inhumane torture, the spy could only remember his own mission - get all the necessary information and escape asap, but unfortunately, he couldn't remember all the details of the information.

Therefore, the rules to complete the mission are:
1. Figure out the way(s) to escape from the old building *1 
2. Find back all the necessary information correctly
3. Find ways to make CIA (America) recognize own identity after successfully escaping
   (*1 The old building used to be a human experiment factory, which may retain traces of people trying to escape from here.)

To motivate the players to continue the game, though a bit fantastical, this escape game will include the respawn function with random respawn points instead of restarting the current state. 

## Features / Functions
1. Generation of random game sets or events
   - Random respawn point
   - Magic items (e.g. dice) for random rewards/penalties spawned at random time
   - Random passcodes or clues 
2. Data structures for storing game status
   - Using boolean data type to determine whether one particular puzzle has been solved or not and a clue or hint has been discovered or not
   - Using string data type to store the player's position (e.g. "A3")
   - A display bar to display the items in the backpack & update with the items received
   - Commands to display player current position (Paper map exists but without position update)
3. Dynamic memory management [Dynamic Memory](http://www.cplusplus.com/doc/tutorial/dynamic/)
   - A dynamic array would be used to store the player's items 
4. File input/output (e.g., for [loading/saving game status](http://www.cplusplus.com/forum/beginner/106630/))
   - A .txt file will store a player's inventory, solved puzzle, position and progress. 
5. Program codes in multiple files
   - Separate program codes to multiple files to make it easier to read the codes and more orgranised
6. Proper indentation and naming styles 
   - Indentation: K&R style based on [Indentation style](https://en.wikipedia.org/wiki/Indentation_style)
   - Naming Style: Function names directly based on own function 
      e.g. `Action(command)` for executing different commands, `UseItem(item)` for using specific item, etc...
7. In-code documentation
   - Command Explanations
   - Item Explanations
