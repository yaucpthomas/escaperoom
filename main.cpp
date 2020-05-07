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
      << "{ Put an underscore between words in command e.g. lookat CD driver ✘ -> lookat CD_driver ✔}\n"

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
    bool secondstage = false
    while(firststage){
        Beginning()
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
                                cout<<"You look at the ID card and realize that this card is not yours.\n";
                                this_thread::sleep_for (chrono::seconds(6));
                                cout<<"Maybe the card is the informer who gives the notes to you...\n";
                                cin.ignore();
                            }
                            else{
                                cout<<"Seems it doesn't work properly. Try again.\n"
                                cin.ignore();
                            }
                        cin.ignore();
                    }
                    else{
                        cout<<"Seems it doesn't work properly. Try again.\n"
                        cin.ignore();
                    }
                cin.ignore();
            }
            else if (command == "grab paper clip"){
                cout<<"You have grabbed the paper clip.\n";
                player.inventory.push_back("paper clip");
                if (command ==  "lookat paper clip"){
                    cout<<"This paper clip seems to be useful for certain purposes…\n";
                    cin.ignore();
                }
                else if (command == "use paper clip"){
                    cout<<"You try to bend the paper clip and use it to unlock the manacle.\n";
                    this_thread::sleep_for (chrono::seconds(6));
                    cout<<"Fortunately, it does work, and you are free to move around the room.\n";
                    firststage = false
                    secondstage = true
                }
                else{
                    cout<<"Seems it doesn't work properly. Try again.\n"
                    cin.ignore();
                }
                cin.ignore();
            }
            else{
                cout<<"Seems it doesn't work properly. Try again.\n"
                cin.ignore();
            }
        return 0;
     }

        while(secondstage){
            Beginning()
            getline(cin, command);
            for (player.location = "A";){
                if (command == "lookat room A"){
                    cout<<"You concentrate your tired mind,\n";
                    this_thread::sleep_for (chrono::seconds(5));
                    cout<<"walk around the messy room,\n";
                    this_thread::sleep_for (chrono::seconds(4));
                    cout<<"and take a closer look at the surroundings.\n";
                    this_thread::sleep_for (chrono::seconds(6));
                    cout<<"You find that there are a [card reader] beside the computer,\n";
                    this_thread::sleep_for (chrono::seconds(7));
                    cout<<"a small pack of chewing [gum]\n";
                    this_thread::sleep_for (chrono::seconds(5));
                    cout<<"and a file covering a document named Uncensored Proofread Context [Part A] on the floor.\n";
                    cin.ignore();
                }
                else if (command == "grab gum"){
                    cout<<"You have grabbed the gum.\n";
                    player.inventory.push_back("gum");
                    cin.ignore();
                }
                else if (command == "grab card reader") {
                    cout<<"You have grabbed the card reader.\n";
                    player.inventory.push_back("card reader");
                    cin.ignore();
                }
                else if (command == "grab Part A") {
                    cout<<"You have grabbed the Part A.\n";
                    player.inventory.push_back("Part A");
                    cin.ignore();
                }
            }
            for (player.location = "B";){
                if (command == "lookat room B"){
                    cout<<"You concentrate your tired mind,\n";
                    this_thread::sleep_for (chrono::seconds(5));
                    cout<<"walk around the messy room,\n";
                    this_thread::sleep_for (chrono::seconds(4));
                    cout<<"and take a closer look at the surroundings.\n";
                    this_thread::sleep_for (chrono::seconds(6));
                    cout<<"You find that there are a small digital [clock],a [pager]\n";
                    this_thread::sleep_for (chrono::seconds(7));
                    cout<<"and a file covering a document named Uncensored Proofread Context [Part B] on the floor.\n";
                    cin.ignore();
                }
                else if (command == "grab clock"){
                    cout<<"You have grabbed the clock.\n";
                    player.inventory.push_back("clock");
                    cin.ignore();
                }
                else if (command == "grab pager") {
                    cout<<"You have grabbed the pager.\n";
                    player.inventory.push_back("pager");
                    cin.ignore();
                }
                else if (command == "grab Part B") {
                    cout<<"You have grabbed the Part B.\n";
                    player.inventory.push_back("Part B");
                    cin.ignore();
                }
            }
            for (player.location = "C";){
                if (command == "lookat room C"){
                    cout<<"You concentrate your tired mind,\n";
                    this_thread::sleep_for (chrono::seconds(5));
                    cout<<"walk around the messy room,\n";
                    this_thread::sleep_for (chrono::seconds(4));
                    cout<<"and take a closer look at the surroundings.\n";
                    this_thread::sleep_for (chrono::seconds(6));
                    cout<<"You find that there is a seemingly broken [projector] and a reel [scroll box]\n";
                    cin.ignore();
                }
                else if (command == "grab projector"){
                    cout<<"You have grabbed the projector.\n";
                    player.inventory.push_back("projector");
                    cin.ignore();
                }
                else if (command == "grab scroll box") {
                    cout<<"You have grabbed the scroll box.\n";
                    player.inventory.push_back("scroll box");
                    cin.ignore();
                }
            }
                    for (player.location = "D";){
                if (command == "lookat room D"){
                    cout<<"You concentrate your tired mind,\n";
                    this_thread::sleep_for (chrono::seconds(5));
                    cout<<"walk around the messy room,\n";
                    this_thread::sleep_for (chrono::seconds(4));
                    cout<<"and take a closer look at the surroundings.\n";
                    this_thread::sleep_for (chrono::seconds(6));
                    cout<<"You find that there are a [poster] pasted on the desk,\n";
                    this_thread::sleep_for (chrono::seconds(7));
                    cout<<"a [color paper] with incomprehensible squared holes on it,\n";
                    this_thread::sleep_for (chrono::seconds(7));
                    cout<<"and a file covering a document named Uncensored Proofread Context [Part D] on the floor.\n";
                    cin.ignore();
                }
                else if (command == "grab poster"){
                    cout<<"You have grabbed the poster.\n";
                    player.inventory.push_back("poster");
                    cin.ignore();
                }
                else if (command == "grab color paper") {
                    cout<<"You have grabbed the color paper.\n";
                    player.inventory.push_back("color paper");
                    cin.ignore();
                }
                else if (command == "grab Part D") {
                    cout<<"You have grabbed the Part D.\n";
                    player.inventory.push_back("Part D");
                    cin.ignore();
                }
            }
        }
