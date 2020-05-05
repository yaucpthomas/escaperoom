#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "player.h"
#include "puzzle.h"
#include "LoadGame.h"
#include "SaveGame.h"
#include <thread>
#include <chrono>
using namespace std;

void StartNewGame(Player& player, Puzzle& puzzle);
void StartScene();
void Beginning();

int main()
{
  Player player;
  Puzzle puzzle;
  string command, filename = "";
  //To determine whether player is new or not
  cout<<"Hello there. New player or load old game files?\n"
      <<"Type \"NewPlayer\" for New Player or \"LoadGame\" to Load Game Files\n";
  cin>>command;
  //Check the command is valid or not
  while (command != "NewPlayer" && command != "LoadGame" ){
    cout<<"\nInvalid Command! Type Again\n"
        <<"Type \"NewPlayer\" for New Player or \"LoadGame\" to Load Game Files\n";
    cin>>command;
  }

  if (command == "NewPlayer"){
    StartNewGame(player, puzzle);
    StartScene();
  }
  else {
    LoadGame(player,puzzle,filename);
    cout<<"You're now currently in room "<<player.location<<endl;
  }


  SaveGame(player,puzzle,filename);

}

void StartNewGame(Player& player, Puzzle& puzzle){
  cout<<"Type your favourite number (Must be positive integer)\n";
  int seed;
  cin>>seed;
  srand(seed);
  //Initialise Inventory, puzzle
  puzzle.rooma = "kramer";
  puzzle.pencode = "oleg";
  puzzle.roombclock = 161059;
  puzzle.roomd = 810364;
  puzzle.roombtoc = rand() % 900000 + 100000;
  puzzle.roomc = rand() % 9000 + 1000;

  player.location = "A";
  player.inventory.push_back("notes");
  player.inventory.push_back("pen");
  player.inventory.push_back("ID_card");

  cout<<"That's it! The Game will begin shortly........\n";
  this_thread::sleep_for (chrono::seconds(1));
  cout<<".\n";
  this_thread::sleep_for (chrono::seconds(1));
  cout<<".\n";
  this_thread::sleep_for (chrono::seconds(1));
  cout<<".\n";
  this_thread::sleep_for (chrono::seconds(1));
  cout<<".\n\n\n";
  this_thread::sleep_for (chrono::seconds(2));

}

void StartScene(){
  //Inform user of basic commands
  cout<< "Commands:\n"
      << "grab <item>\n"
      << "lookat <object>\n"
      << "use <object>\n"
      << "use <object> <keyword/number>\n"
      << "moveto <room>\n"
      << "{ Remember to grab the object into the inventory before looking at it … }\n"

      << "Location \n"
      << "Inventory\n"
      << "Savegame\n"
      << "Loadgame\n"
      << "Listcommands\n";
  this_thread::sleep_for (chrono::seconds(10));
  //Intro
  cout<<"\n\n(Door knocked)\n";
  this_thread::sleep_for (chrono::seconds(2));
  cout<<"Who’s there?\n";
  this_thread::sleep_for (chrono::seconds(2));
  cout<<"Oleg. Oleg Penkovsky. Джордж Кисевальтер (countersign)\n";
  this_thread::sleep_for (chrono::seconds(3));
  cout<<"Come in first, my pal. (Door opens) Things go right and we're gonna leave as soon...\n";
  this_thread::sleep_for (chrono::seconds(5));
  cout<<"Popov, you bastard. Caught him right now!\n";
  this_thread::sleep_for (chrono::seconds(4));
  cout<<"Wait, what? Not Oleg?? (How come KGB knows the sign...)\n";
  this_thread::sleep_for (chrono::seconds(4));
  cout<<"Man, you’re so damn bold, huh? How dare you betray your own country?\n";
  this_thread::sleep_for (chrono::seconds(5));
  cout<<"(Pager rings) Sir, we got em. We’ll return now. (Hang up the call)\n";
  this_thread::sleep_for (chrono::seconds(5));
  cout<<"Bring him to the car and give him the taste of pain.\n";
  this_thread::sleep_for (chrono::seconds(4));

  cout<<"No god! Please no!!! NOOO… (Fainted by head hit)\n";
  this_thread::sleep_for (chrono::seconds(4));
  cout<<".\n";
  this_thread::sleep_for (chrono::seconds(2));
  cout<<".\n";
  this_thread::sleep_for (chrono::seconds(2));
  cout<<".\n";

  cout << "\nYou wake up on the cold floor.\n" ;
  this_thread::sleep_for (chrono::seconds(4));
  cout << "You sit up and realize that your body is seriously bruised.\n" ;
  this_thread::sleep_for (chrono::seconds(7));
  cout << "Your feet are also manacled.\n" ;
  this_thread::sleep_for (chrono::seconds(4));
}

void Beginning(){
  cout << "You find your[self] in a sealed room named [room X].\n" ;
  this_thread::sleep_for (chrono::seconds(6));
  cout << "Earthworms and cockroaches are stretching their legs.\n" ;
  this_thread::sleep_for (chrono::seconds(6));
  cout << "There is a locked door in front of you with an electric door lock named [lock X] on its surface. (X = A, B, C, D)\n" ;
  cin.ignore();
}

  



    bool firststage = true
    while(firststage){
        void Beginning()
        getline(cin, command);
            if (command == "Loadgame"){
                LoadGame(player,puzzle,filename);
                cout<<"You're now currently in room "<<player.location<<endl;
            }
            else if (command == "Savegame"){
                SaveGame(player,puzzle,filename);
            }
            else if (command == "Listcommands"){
                cout<<"Commands:\n"
                    <<"grab <item>\n"
                    <<"lookat <object>\n"
                    <<"use <object>\n"
                    <<"use <object> <keyword/number>\n"
                    <<"moveto <room>\n"
                    <<"[Remember to grab the object into the inventory before looking at it …]\n"

                    <<"Location \n"
                    <<"Inventory\n"
                    <<"Savegame\n"
                    <<"Loadgame\n"
                    <<"Listcommands\n";
                    cin.ignore();
            }
            else if (command ==  "lookat self"){
                cout<<"Your suit is torn, your long sleeves are shredded, and also your trousers.\n" ;
                this_thread::sleep_for (chrono::seconds(5));
                cout<<"You notice that your elbows and knees were scratched and suffering from oozy suppuration.\n" ;
                this_thread::sleep_for (chrono::seconds(5));
                cout<<"Your movements and reactions also become dull, or this is why you can no longer feel pain.\n" ;
                this_thread::sleep_for (chrono::seconds(5));
                cout<<"However, you can still feel something in your [pocket].\n"
                    if (command ==  "lookat pocket"){
                        cout<<"You go through your pocket.\n";
                        this_thread::sleep_for (chrono::seconds(3));
                        cout<<"You find a few pieces of [notes], a [pen] and your agent [ID card].\n";
                            if (command ==  "lookat notes"){
                                cout<<"The notes hold together with a [paper clip]\n"
                                    <<"“You may not know who I am but I do know you\n"
                                    <<"well, and I do know what will happen to you next.\n"
                                    <<"Use the puzzles to get password and escape this\n"
                                    <<"place as soon as possible. Take a good look on\n"
                                    <<"yourself and use those items well. The docs and\n"
                                    <<"pager may also help you, so do remember, take\n"
                                    <<"all docs before you leave. Good luck.”\n";
                                cin.ignore();
                            }
                            else if (command == "lookat pen"){
                                cout<<"“This pen is engraved with the name Penkovsky, what does it mean? ”\n";
                                this_thread::sleep_for (chrono::seconds(6));
                                cout<<"And there is a small button on this pen.\n";
                                this_thread::sleep_for (chrono::seconds(4));
                                cout<<"It seems that it has been modified for emergencies…\n";
                                cin.ignore();
                            }
                            else if (command == "lookat ID card"){
                                cout<<"You lookat the ID card and realize that this card is not yours.\n";
                                this_thread::sleep_for (chrono::seconds(6));
                                cout<<"Maybe the card is the informer who gives the notes to you...\n";
                                cin.ignore();
                            }
                            else{
                                cout<<"Seems it doesn't work properly. Try again."
                                cin.ignore();
                            }
                    }
                    else{
                        cout<<"Seems it doesn't work properly. Try again."
                        cin.ignore();
                    }
                cin.ignore();
            }
            else if (command ==  "grab paperclip"){
                cout<<"You have grabbed the paperclip.\n";
                if (command ==  "lookat paperclip"){
                    cout<<"This paper clip seems to be useful for certain purposes…\n";
                    cin.ignore();
                }
                else if (command ==  "use paperclip"){
                    cout<<"You try to bend the paperclip and use it to unlock the manacle.\n"
                        <<"Fortunately, it does work, and you are free to move around the room.\n";
                    firststage = false
                }
                else{
                    cout<<"Seems it doesn't work properly. Try again."
                    cin.ignore();
                }
                cin.ignore();
            }
            else{
                cout<<"Seems it doesn't work properly. Try again."
                cin.ignore();
            }
        return 0;
     }
