#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include "player.h"
#include "puzzle.h"
#include "LoadGame.h"
#include "SaveGame.h"
using namespace std;

void StartNewGame(Player& player, Puzzle& puzzle);
void StartScene();
void Beginning();
void Inventory(Player player);

int main(){
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
    cout<<"You're now currently in room "<<player.location<<endl<<endl;
  }

  if (player.firststage){
    Beginning();
  }
  //First Stage of Game
  getline(cin, command);
  while(player.firststage){
      getline(cin, command);
          if (command == "SaveGame"){
              SaveGame(player,puzzle,filename);
          }
          else if (command == "Listcommands"){
              cout<<"\nCommands:\n"
                  <<"grab <item>\n"
                  <<"lookat <object>\n"
                  <<"use <object>\n"
                  <<"use <object> <keyword/number>\n"
                  <<"moveto <room>\n"
                  <<"[Remember to grab the object into the inventory before looking at it …]\n\n"

                  <<"Location \n"
                  <<"Inventory\n"
                  <<"Savegame\n"
                  <<"Loadgame\n"
                  <<"Listcommands\n";

          }

          else if (command ==  "lookat self"){
              cout<<"\nYour suit is torn, your long sleeves are shredded, and also your trousers.\n" ;
              this_thread::sleep_for (chrono::seconds(5));
              cout<<"You notice that your elbows and knees were scratched and suffering from oozy suppuration.\n" ;
              this_thread::sleep_for (chrono::seconds(5));
              cout<<"Your movements and reactions also become dull, or this is why you can no longer feel pain.\n" ;
              this_thread::sleep_for (chrono::seconds(5));
              cout<<"However, you can still feel something in your [pocket].\n";
              player.lookat.push_back("pocket");
          }
          else if ((command ==  "lookat pocket" ) && (find(player.lookat.begin(),player.lookat.end(),"pocket")) != end(player.lookat)){
            cout<<"You go through your pocket.\n";
            this_thread::sleep_for (chrono::seconds(3));
            cout<<"You find a few pieces of [notes], a [pen] and your agent [ID card].\n";
            player.lookat.push_back("notes");
            player.lookat.push_back("pen");
            player.lookat.push_back("ID card");
            player.inventory.push_back("notes");
            player.inventory.push_back("pen");
            player.inventory.push_back("ID card");
          }
          else if((command ==  "lookat notes") && (find(player.lookat.begin(),player.lookat.end(),"notes")) != end(player.lookat)){
            cout<<"The notes hold together with a [paper clip]\n"
                <<"“You may not know who I am but I do know you\n"
                <<"well, and I do know what will happen to you next.\n"
                <<"Use the puzzles to get password and escape this\n"
                <<"place as soon as possible. Take a good look on\n"
                <<"yourself and use those items well. The docs and\n"
                <<"pager may also help you, so do remember, take\n"
                <<"all docs before you leave. Good luck.”\n";
            player.lookat.push_back("paper clip");
          }
          else if ((command == "lookat pen") && (find(player.lookat.begin(),player.lookat.end(),"pen")) != end(player.lookat)){
            cout<<"“This pen is engraved with the name Penkovsky, what does it mean? ”\n";
            this_thread::sleep_for (chrono::seconds(6));
            cout<<"And there is a small button on this pen.\n";
            this_thread::sleep_for (chrono::seconds(4));
            cout<<"It seems that it has been modified for emergencies…\n";
          }

          else if ((command == "lookat ID card") && (find(player.lookat.begin(),player.lookat.end(),"ID_card")) != end(player.lookat)){
            cout<<"You look at the ID card and realize that this card is not yours.\n";
            this_thread::sleep_for (chrono::seconds(6));
              cout<<"Maybe the card is the informer who gives the notes to you...\n";
          }

          else if ((command == "grab paper clip") && (find(player.lookat.begin(),player.lookat.end(),"paper_clip")) != end(player.lookat)){
              cout<<"You have grabbed the paper clip.\n";
              player.inventory.push_back("paper clip");
          }
          else if ((command ==  "lookat paper clip") && (find(player.lookat.begin(),player.lookat.end(),"paper_clip")) != end(player.lookat)){
            cout<<"This paper clip seems to be useful for certain purposes…\n";
          }
          else if ((command == "use paper clip") && (find(player.inventory.begin(),player.inventory.end(),"paper_clip")) != end(player.inventory)){
                  cout<<"You try to bend the paper clip and use it to unlock the manacle.\n";
                  this_thread::sleep_for (chrono::seconds(6));
                  cout<<"Fortunately, it does work, and you are free to move around the room.\n";
                  player.firststage = false;
                  player.secondstage = true;
          }
          else if (command == "quit"){
            exit(1);
          }
          else if (command == "inventory"){
            Inventory(player);
          }
          else{
              cout<<"Seems it doesn't work properly. Try again.\n";
          }
  }
  return 0;
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

  player.firststage = true;
  player.secondstage = false;
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

void Inventory(Player player){
  cout<<"You have following item in your inventory: \n";
  if (player.inventory.size() != 0){
    for (int i = 0; i < player.inventory.size(); ++i){
      cout<<player.inventory[i]<<" ";
    }
  }
  else{
    cout<<"You have no item in your list now. Use \"grab\" command to grab something!";
  }
  cout<<endl;
}

void Beginning(){
  cout << "You find your[self] in a sealed room named [room X].\n" ;
  this_thread::sleep_for (chrono::seconds(6));
  cout << "Earthworms and cockroaches are stretching their legs.\n" ;
  this_thread::sleep_for (chrono::seconds(6));
  cout << "There is a locked door in front of you with an electric door lock named [lock X] on its surface. (X = A, B, C, D)\n" ;
  cout << "Game has started! You may start to type your commands.\n"<<endl;

}
