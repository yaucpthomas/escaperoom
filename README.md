# escaperoom
## Team member 
Ng To San (3035601619),  Yau Chin Pang (3035689257)

## Game Description with Basic Game Rules
We would design an escape game, which includes kinds of general concepts in other similar games, such as discovering various clues and items, mysterious traps and baits, different versions of endings. In this escape game, players will act as a betrayed spy who had just been caught and charged with treason with sufficient evidence before being ready to leave from his own intelligence agency. After long-time inhumane torture, the spy could only remember his own mission - get all the necessary information and escape asap, but unfortunately, he couldn't remember all the details of the information.

Therefore, the rules to complete the mission are:
1. Figure out the way(s) to escape from the old building *1 
2. Find back all the necessary information correctly
3. Find secret signals to make others recognize own identity after escaping
(*1 The old building used to be a human experiment factory, which may retain traces of people trying to escape from here.)

To motivate the players to continue the game, though a bit fantastical, this escape game will include the respawn function with random respawn points instead of restarting the current state. 

## Features / Functions
1. Generation of random game sets or events
   - Random respawn point
   - Magic items (e.g. dice) for random rewards/penalties spawned at random time
   - Random passcodes or clues 
   
2. Data structures for storing game status
   - A .txt file will contain a player's inventory, progress and solved puzzle
    - A Dynamic Array will store player's item
    - Boolean data type will be used to determine whether a particular puzzle is solved or not
    - Boolean data type will be used to determine if a clue or hint is discovered or not
   - A display bar to display the items in the backpack & update with the items received
   - Commands to display player current position (Paper map exists but without position update)
   
3. Dynamic memory management [Dynamic Memory](http://www.cplusplus.com/doc/tutorial/dynamic/)
   - A dynamic array would be used to store the player's items named "backpack"
   
4. File input/output (e.g., for [loading/saving game status](http://www.cplusplus.com/forum/beginner/106630/))
   - A .txt file will store a player's inventory, solved puzzle, position and progress. 
   
5. Program codes in multiple files
   - 
   
6. Proper indentation and naming styles 
   - Indentation: K&R style based on [Indentation style](https://en.wikipedia.org/wiki/Indentation_style)
   - Naming Style: Function names directly based on own function 
      e.g. `Action(command)` for executing different commands, `UseItem(item)` for using specific item, etc...
      
7. In-code documentation
   - Command Explanations
   - Item Explanations
