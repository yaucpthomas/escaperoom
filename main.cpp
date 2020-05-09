#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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
void Beginning(Player player);
void Inventory(Player player);
void RoomMove(Player player,Puzzle puzzle,string command);

int main(){
  Player player;
  Puzzle puzzle;
  string command, filename = "";
  vector<string>::iterator pos;
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
    Inventory(player);
  }

  if (player.firststage){
    Beginning(player);
  }
  cout << "Game has started! You may start to type your commands.\n"<<endl;
  //First Stage of Game
    getline(cin, command);
    while(player.firststage){
    getline(cin, command);
    cout<<"test: "<<command<<endl;
    cout<<endl;
          if (command == "SaveGame"){
              SaveGame(player,puzzle,filename);
          }
          else if (command == "Listcommands"){
              cout<<"\nCommands:\n"
                  <<"grab <item>\n"
                  <<"lookat <item>\n"
                  <<"use <item>\n"
                  <<"use <item> <keyword/number/item>\n"
                  <<"moveto \n"
                  <<"[REMEMBER TO GRABb the object into the inventory before looking at it …]\n\n"

                  <<"Location \n"
                  <<"Inventory\n"
                  <<"Savegame\n"
                  <<"Loadgame\n"
                  <<"Listcommands\n";

          }
          else if (command == "moveto") {
              cout<<"Which room do you want to get in?\n"
                  <<"Type A, B, C, D to move to that respective\n";
              RoomMove(player, puzzle, command);
          }
          else if (command ==  "lookat self"){
              cout<<"Your suit is torn, your long sleeves are shredded, and also your trousers.\n" ;
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
            cout<<"You find a few pieces of [notes], a [pen] and your agent [ID card].\n"
                <<"[notes], [pen] and [ID card] has been added to your inventory automatically.\n";
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
            cout<<"“I think the pen belongs to someone else, I think?”\n";
            this_thread::sleep_for (chrono::seconds(6));
            cout<<"And there is a small button on this pen.\n";
            this_thread::sleep_for (chrono::seconds(4));
            cout<<"It seems that it has been modified for emergencies…\n";
          }
          else if ((command == "use pen") && (find(player.inventory.begin(),player.inventory.end(),"pen")) != end(player.inventory)){
            cout<<"You press the small button on the pen though it seems to be kinds of weird.\n";
            this_thread::sleep_for (chrono::seconds(7));
            cout<<"The pen splits after your exertion, and then the inner part pops up.\n";
            this_thread::sleep_for (chrono::seconds(7));
            cout<<"“Damn it! A 4-letter electric lock!? Are you sure about that!?”\n";
            this_thread::sleep_for (chrono::seconds(6));
            cout<<"“OK… Let me just not think how the electronic lock is made.”\n";
            this_thread::sleep_for (chrono::seconds(6));
            cout<<"“Man, what’s the password then? How come I know the password?\n";
            this_thread::sleep_for (chrono::seconds(6));
            cout<<"You look back at the name on the pen, and find that things are just that simple…\n";
          }
          else if ((command == "use pen oleg") && (find(player.inventory.begin(),player.inventory.end(),"pen")) != end(player.inventory)){
            cout<<"You enter the password and press the button again.“Beep!” a sudden sound intimidates you.\n";
            this_thread::sleep_for (chrono::seconds(7));
            cout<<"The two ends pop up somethings interesting: a tiny head of [screwdriver] and a dome-shaped head of [penlight]. It should be useful for escape...\n";
            player.lookat.push_back("screwdriver");
            player.lookat.push_back("screwdriver");
            player.inventory.push_back("penlight");
            player.inventory.push_back("penlight");
          }
          else if ((command == "lookat ID card") && (find(player.lookat.begin(),player.lookat.end(),"ID card")) != end(player.lookat)){
            cout<<"You look at the ID card and realize that this card is not yours.\n";
            this_thread::sleep_for (chrono::seconds(4));
              cout<<"Maybe the card is the informer who gives the notes to you...\n";
          }
          else if ((command == "grab paper clip") && (find(player.lookat.begin(),player.lookat.end(),"paper clip")) != end(player.lookat)){
              cout<<"You have grabbed the paper clip.\n";
              player.inventory.push_back("paper clip");
          }
          else if ((command ==  "lookat paper clip") && (find(player.inventory.begin(),player.inventory.end(),"paper clip")) != end(player.inventory)){
            cout<<"This paper clip seems to be useful for certain purposes…\n";
          }
          else if ((command == "use paper clip") && (find(player.inventory.begin(),player.inventory.end(),"paper clip")) != end(player.inventory)){
                  cout<<"You try to bend the paper clip and use it to unlock the manacle.\n";
                  this_thread::sleep_for (chrono::seconds(6));
                  cout<<"Fortunately, it does work, and you are free to move around the room.\n";
                  player.firststage = false;
                  player.secondstage = true;
                  pos = find(player.inventory.begin(),player.inventory.end(),"paper clip");
                  player.inventory.erase(pos);
                  pos = find(player.lookat.begin(),player.lookat.end(),"paper clip");
                  player.lookat.erase(pos);
                  cout<<"paper clip has been deleted from your inventory.\n";
          }
          else if (command == "quit"){
            exit(1);
          }
          else if (command == "inventory"){
            Inventory(player);
          }
          else if (command != " "){
              cout<<"Seems it doesn't work properly. Try again.\n";
          }
  }

  //Second Stage
  while(player.secondstage){
           getline(cin, command);
           cout<<endl;
           if (command == "quit"){
             exit(1);
           }
           else if (command == "inventory"){
             Inventory(player);
           }
           else if (command == "SaveGame"){
             SaveGame(player,puzzle,filename);
           }
           else if ((command == "lookat room A") &&( player.location == "A")){
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
                cout<<"a file covering a document named Uncensored Proofread Context [Part A] on the floor,\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout <<"and a locked door in front of you with an electric door [lock] on its surface.\n";
                player.lookat.push_back("lock")
                player.lookat.push_back("card reader");
                player.lookat.push_back("gum");
                player.lookat.push_back("Part A");
            }
            else if ((command == "grab gum") && ( find(player.lookat.begin(),player.lookat.end(),"gum") != end(player.lookat)) && (player.location == "A")){
                cout<<"You have grabbed the gum.\n";
                player.inventory.push_back("gum");
            }
            else if ((command == "grab card reader") && ( find(player.lookat.begin(),player.lookat.end(),"card reader") != end(player.lookat)) && (player.location == "A")) {
                cout<<"You have grabbed the card reader.\n";
                player.inventory.push_back("card reader");
            }
            else if ((command == "grab Part A") && ( find(player.lookat.begin(),player.lookat.end(),"Part A")!= end(player.lookat)) && (player.location == "A") ) {
                cout<<"You have grabbed the Part A.\n";
                player.inventory.push_back("Part A");
            }

            else if ((command == "lookat room B") && (player.location == "B")){
                cout<<"You concentrate your tired mind,\n";
                this_thread::sleep_for (chrono::seconds(5));
                cout<<"walk around the messy room,\n";
                this_thread::sleep_for (chrono::seconds(4));
                cout<<"and take a closer look at the surroundings.\n";
                this_thread::sleep_for (chrono::seconds(6));
                cout<<"You find that there are a small digital [clock],a [pager]\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"and a file covering a document named Uncensored Proofread Context [Part B] on the floor.\n";
                player.lookat.push_back("clock");
                player.lookat.push_back("pager");
                player.lookat.push_back("Part B");
            }
            else if ((command == "grab clock") && (find(player.lookat.begin(),player.lookat.end(),"clock") != end(player.lookat) )&& (player.location == "B")){
                cout<<"You have grabbed the clock.\n";
                player.inventory.push_back("clock");
            }
            else if ((command == "grab pager") && (find(player.lookat.begin(),player.lookat.end(),"pager") != end(player.lookat)) && (player.location == "B")) {
                cout<<"You have grabbed the pager.\n";
                player.inventory.push_back("pager");
            }
            else if ((command == "grab Part B") && (find(player.lookat.begin(),player.lookat.end(),"Part B")!= end(player.lookat)) && (player.location == "B")) {
                cout<<"You have grabbed the Part B.\n";
                player.inventory.push_back("Part B");
            }

            else if ((command == "lookat room C") && (player.location == "C")){
                cout<<"You concentrate your tired mind,\n";
                this_thread::sleep_for (chrono::seconds(5));
                cout<<"walk around the messy room,\n";
                this_thread::sleep_for (chrono::seconds(4));
                cout<<"and take a closer look at the surroundings.\n";
                this_thread::sleep_for (chrono::seconds(6));
                cout<<"You find that there is a seemingly broken [projector] and a reel [scroll box]\n";
                player.lookat.push_back("projector");
                player.lookat.push_back("scroll box");
            }
            else if ((command == "grab projector") && (find(player.lookat.begin(),player.lookat.end(),"projector")!= end(player.lookat)) && (player.location == "C") ){
                cout<<"You have grabbed the projector.\n";
                player.inventory.push_back("projector");
            }
            else if ((command == "grab scroll box") && (find(player.lookat.begin(),player.lookat.end(),"scroll box")!= end(player.lookat)) && (player.location == "C")) {
                cout<<"You have grabbed the scroll box.\n";
                player.inventory.push_back("scroll box");
            }
            else if ((command == "grab painting") && (find(player.lookat.begin(),player.lookat.end(),"painting")!= end(player.lookat)) && (player.location == "C")){
                cout<<"You have grabbed the projector.\n";
                player.inventory.push_back("projector");
            }
            else if ((command == "grab Part C") && (find(player.lookat.begin(),player.lookat.end(),"Part C")!= end(player.lookat)) && (player.location == "C") ){
                cout<<"You have grabbed the Part C.\n";
                player.inventory.push_back("Part C");
            }

            else if ((command == "lookat room D") && player.location == "D"){
                cout<<"You concentrate your tired mind,\n";
                this_thread::sleep_for (chrono::seconds(5));
                cout<<"walk around the messy room,\n";
                this_thread::sleep_for (chrono::seconds(4));
                cout<<"and take a closer look at the surroundings.\n";
                this_thread::sleep_for (chrono::seconds(6));
                cout<<"You find that there are a [poster] pasted on the desk,\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"a [tape] with incomprehensible squared holes on it,\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"and a file covering a document named Uncensored Proofread Context [Part D] on the floor.\n";
                player.lookat.push_back("poster");
                player.lookat.push_back("tape");
                player.lookat.push_back("Part D");
            }
            else if ((command == "grab poster") && (find(player.lookat.begin(),player.lookat.end(),"poster")!= end(player.lookat)) && (player.location == "D") ){
                cout<<"You have grabbed the poster.\n";
                player.inventory.push_back("poster");
            }
            else if ((command == "grab tape") && (find(player.lookat.begin(),player.lookat.end(),"tape")!= end(player.lookat)) && (player.location == "D") ) {
                cout<<"You have grabbed the tape.\n";
                player.inventory.push_back("tape");
            }
            else if ((command == "grab Part D") && (find(player.lookat.begin(),player.lookat.end(),"Part D") != end(player.lookat)) && (player.location == "D") ) {
                cout<<"You have grabbed the Part D.\n";
                player.inventory.push_back("Part D");
            }
            else if ((command == "lookat lock") && (find(player.lookat.begin(),player.lookat.end(),"lock") != end(player.lookat)) && (player.location == "A") ){
                cout<<"The electronic lock says it is now in OFFLINE MODE. It seems to be connected to this seemingly stainless steel vault door,\n";
                this_thread::sleep_for (chrono::seconds(7);
                cout<<"which may require a specific password to unlock. It is also seemingly impossible to damage the door by other methods.\n";
            }
            else if (command == "use lock" && player.location == "A"){
                    cout<<"OFFLINE MODE\n";
                    LockPassword(Puzzle &puzzle)
            }
            else if ((command == "lookat gum") && (find(player.inventory.begin(),player.inventory.end(),"gum") != end(player.inventory))){
                cout<<"“Why there is a gum here? Clues or something else?”\n";
            }
            else if ((command == "use gum") && (find(player.inventory.begin(),player.inventory.end(),"gum") != end(player.inventory))){
                cout<<"You stop thinking something weird and take the gum.\n";
                this_thread::sleep_for (chrono::seconds(5));
                cout<<"“Fresh! Seems it has not yet expired.”\n";
            }
            else if ((command == "lookat card reader") && (find(player.inventory.begin(),player.inventory.end(),"card reader") != end(player.inventory))){
                cout<<"You see the card reader with a display screen and a bottom slot.\n";
                this_thread::sleep_for (chrono::seconds(6));
                cout<<"You guess whether something should be inserted in the card reader…\n";
            }
            else if ((command == "use card reader") && (find(player.inventory.begin(),player.inventory.end(),"card reader") != end(player.inventory))){
                cout<<"You try to turn on the card reader in other ways, but eventually those ways seem to be in vain…\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"It looks like it won’t turn on without a suitable card…\n";
            }
            else if (((command == "use ID card card reader") || (command == "use ID card card reader")) && (find(player.inventory.begin(),player.inventory.end(),"ID card")!= end(player.inventory))
                                              && (find(player.inventory.begin(),player.inventory.end(),"card reader") != end(player.inventory))){
                cout<<"You realize that you have an ID card in your pocket that the card reader may work if you insert the ID card.\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"“If everything goes the right place, it should be a right choice to insert it. Just take a try… Great! Something just pops up. Ehhh, crazy stuff again ?”";
                cout<<"Caesar says: “A->F && {1:18 2:6 2:11 3:2 4:15 5:28}”\n"
                    <<"PW:_ _ _ _ _ _\n\n"
                    <<"Wzns rd qnkj ns ymj mtwwtw,\n"
                    <<"Jxhfuj fx rd rfotw,\n"
                    <<"Afsnxm bnymtzy fsd xnlsx,\n"
                    <<"Jhhqjxnfxyjx bjwj xynqq ktzsi,\n"
                    <<"Wjujfy ymj ytwyzwj, zsynq Xfyfs'x psthp.\n"
                    <<"Xtwwd, rd ufq, fsi rd ufwjsyx,\n"
                    <<"Jqzyj rd xns, gwnsl rj yt mjfajs.\n";
            }
            else if ((command == "lookat Part A") && (find(player.inventory.begin(),player.inventory.end(),"Part A")) != end(player.inventory)){
                cout<<"You look at the document and find that it is just like a section of a whole uncensored context.\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"“Seems that more documents are required to figure out what actually it is…”\n";
            }
            else if ((command == "lookat clock") && (find(player.inventory.begin(),player.inventory.end(),"clock")) != end(player.inventory)){
                cout<<"You look at the clock and find that it seems like an electric clock which should not be the product outcome in this decade.\n";
                this_thread::sleep_for (chrono::seconds(8));
                cout<<"You also find that behind the clock, there are switches on the left for changing the time on the small front screen, and a secret tap trigger on the right.\n";
                this_thread::sleep_for (chrono::seconds(9));
                cout<<"You try to open it by hand but it does not seem to work. \n";
                this_thread::sleep_for (chrono::seconds(5));
                cout<<"“Maybe using some tools can do this stuff...”\n";
            }
            else if (((command == "use screwdriver clock") || (command == "use clock screwdriver")) && (find(player.inventory.begin(),player.inventory.end(),"screwdriver") != end(player.inventory))
                                                  && (find(player.inventory.begin(),player.inventory.end(),"clock") != end(player.inventory))){
                cout<<"You realize that you can use the head of the screwdriver in your pen to open the trigger, and it does work.\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"But then, a small piece of chip pops up and you are intimidated again.\n";
                this_thread::sleep_for (chrono::seconds(5));
                cout<<"There are words on the small chips on both sides.\n";
                this_thread::sleep_for (chrono::seconds(4));
                cout<<"You try to focus on those words, although they are pretty small. “Oh come on, man. Crazy stuff again ?”\n";
                cout<<"{147}\n"
                    <<"A2A5B1B2B3B4B5C5\n"
                    <<"E1E2E3F3G1G2G3G34G5\n"
                    <<"I1J1K1K2K3K4K5\n"
                    <<"{PW:_ _ _ _ _ _}\n"
                    <<"A2A5B1B2B3B4B5C5\n"
                    <<"E1E2E3E4E5F1F3F5G1G3G4G5\n"
                    <<"I2I5J1J2J3J4J5K5\n"
                    <<"M1M2M3M4M5N1N5O1O2O3O4O5\n"
                    <<"Q1Q2Q3Q5R1R3R5S1S3S4S5\n"
                    <<"U1U2U3U5V1V3V5W1W2W3W4W5\n";
            }
            else if ((command == "use clock") && (find(player.inventory.begin(),player.inventory.end(),"clock")) != end(player.inventory)){
                cout<<"You think the clock seems to be used to display the current time only.\n";
                this_thread::sleep_for (chrono::seconds(5));
                cout<<"But later when you think more deeply, you realize that this clock may not just show the current time,\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"and then you try to tap the switches to see if anything would happen.\n";
                this_thread::sleep_for (chrono::seconds(5));
                cout<<"“Wait what? How come I can type 99:99:99 in this freaking clock? What the hell is going on?”\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"“Hold up, wait a minute. Or it should be something else?”\n";
            }
            else if ((command == "lookat pager") && (find(player.inventory.begin(),player.inventory.end(),"pager")) != end(player.inventory)){
                cout<<"You find a pager and you recall the words from the [notes] at the beginning.\n";
                this_thread::sleep_for (chrono::seconds(6));
                cout<<"The surface is full of dust and tar. You try to clean it with your torn suit and you see a CIA logo at the top left corner on the pager.\n";
                this_thread::sleep_for (chrono::seconds(8));
                cout<<"“Oh god, finally. I got a way to leave here.”\n";
            }
            else if ((command == "use pager") && (find(player.inventory.begin(),player.inventory.end(),"pager")) != end(player.inventory)){
                cout<<"You press the CIA logo at the top left corner on the pager and something shows on the little screen.\n";
                cout<<"CS : _ _ _ _ _ _\n";
            }
            else if ((command == "lookat Part B") && (find(player.inventory.begin(),player.inventory.end(),"Part B")) != end(player.inventory)){
                cout<<"You look at the document and find that it is just like a section of a whole uncensored context.\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"“Seems that more documents are required to figure out what actually it is…”\n";
            }
            else if ((command == "lookat projector") && (find(player.inventory.begin(),player.inventory.end(),"projector")) != end(player.inventory)){
                cout<<"Although the projector seems to be broken, you press on the start button and it still works. It should be used to reflect something in detail…\n";
            }
            else if ((command == "lookat scroll box") && (find(player.inventory.begin(),player.inventory.end(),"scroll box")) != end(player.inventory)){
                cout<<"You find that the scroll box inside has a mysterious [painting] and a document named Uncensored Proofread Context [Part C].\n";
                player.lookat.push_back("painting");
                player.lookat.push_back("Part C");
            }
            else if ((command == "lookat painting") && (find(player.inventory.begin(),player.inventory.end(),"painting")) != end(player.inventory)){
                cout<<"You find that the painting style of the painting is a little weird, which makes you think it should not be just painting at all…\n";
            }
            else if ((command == "use projector") && (find(player.inventory.begin(),player.inventory.end(),"projector") != end(player.inventory))
                                                && (find(player.inventory.begin(),player.inventory.end(),"painting") != end(player.inventory))) {
                cout<<"You realize that you can use the projector to have a clear look at the painting.\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"As you expect, something shows from the underneath…\n";
                cout<<"Orange(O)->Apple(A)->Banana(B)->Melon(M)\n"
                    <<"OOBAM->2\n"
                    <<"OBOAM->2\n"
                    <<"AOMBA->4\n"
                    <<"OBMMA->8\n"
                    <<"BMAAM->8\n"
                    <<"PW:_ _ _ _ _ _\n"
                    <<"MAOOM\n"
                    <<"ABOBB\n"
                    <<"MOBMB\n"
                    <<"OOAOO\n"
                    <<"BOMAO\n"
                    <<"MAOBA\n";
            }
            else if ((command == "lookat Part C") && (find(player.inventory.begin(),player.inventory.end(),"Part C")) != end(player.inventory)){
                cout<<"You look at the document and find that it is just like a section of a whole uncensored context.\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"“Seems that more documents are required to figure out what actually it is…”\n";
            }
            else if ((command == "lookat poster") && (find(player.inventory.begin(),player.inventory.end(),"poster")) != end(player.inventory)){
                cout<<"You pick up and have a close look on the poster.\n";
                this_thread::sleep_for (chrono::seconds(5));
                cout<<"It looks like a piece of plain paper, but when you try to see through it with the faint light from the nearby light bulb,\n";
                this_thread::sleep_for (chrono::seconds(8));
                cout<<"you vaguely see some dots and line hidden.\n";
                this_thread::sleep_for (chrono::seconds(5));
                cout<<"You want to know what that is, and you look for a stronger light source,\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"and meanwhile, some ideas crop up from your mind…\n";
            }
            else if (((command == "use penlight poster")|| (command == "use poster penlight"))&& (find(player.inventory.begin(),player.inventory.end(),"penlight")) != end(player.inventory)
                                               && (find(player.inventory.begin(),player.inventory.end(),"poster")) != end(player.inventory)){
                cout<<"You go through your pocket to find something useful, and you remember you’ve got a penlight from your pen.\n";
                this_thread::sleep_for (chrono::seconds(5));
                cout<<"“OMG. I’m smart af boi. OK, let just shine on this lovely damn thing and see what’s the next...” As you expected, another puzzle comes out...\n"
                    <<"PW: _ _ _ _ _ _\n"
                    <<"1)- .... . .-. .  .-- . .-. .  .-- .. ... .  --- .-.. -..  --- .-- .-.. ...  ... .- -  --- -.  .-  -... .- .-. -.  -.. --- --- .-. --··--\n"
                    <<"2). .. --. .... -  ..-. .-.. . .--  .- .-- .- -.-- --··--\n"
                    <<"3)..-. .. -. -.. .. -. --.  - .... .  . .-.. -.. . .-.  --- .-- .-.. ...  --- -.  - .... . .. .-.  .-- .- -.-- ·-·-·-\n"
                    <<"4)--- -. .  --- .-- .-..  .-.. . ..-. -  -... . .... .. -. -.. --··--\n"
                    <<"5).- -. -..  --.. . .-. ---  --- .-- .-.. ...  -.-. --- ..- .-.. -.. -.-. .- .-.. --  - .... . .. .-.  -- .. -. -.. ·-·-·-\n"
                    <<"6)- .... .-. . .  --- .-- .-.. ...  -.-. .- -- .  -... .- -.-. -.-  - ---  - .... .  -. . ... - --··--\n"
                    <<"7)... .- .. -..  - .... .  --- - .... . .-.  ... .. -..-  --- .-- .-.. ...  .-- . .-. .  .-- .- .. - .. -. --.  ..-. --- .-.  -.-- --- ..- .. -.  - .... .  .-- . ... - ·-·-·-\n"
                    <<"8)- .... . -.  - .... . ... .  ..-. --- ..- .-.  --- .-- .-.. ...  ... .- .. -..  --. --- --- -.. -... -.-- .  - ---  - .... . .. .-.  --- .-.. -..  .-.. .. ..-. . ·-·-·-\n";
            }
            else if ((command == "lookat tape") && (find(player.inventory.begin(),player.inventory.end(),"tape")) != end(player.inventory)){
                cout<<"It seems to be used for sticking something together, maybe some files or documents...\n";
            }
            else if ((command == "use tape") && (find(player.inventory.begin(),player.inventory.end(),"tape")) != end(player.inventory)
                                           && (find(player.inventory.begin(),player.inventory.end(),"Part D")) != end(player.inventory)
                                           && (find(player.inventory.begin(),player.inventory.end(),"Part D")) != end(player.inventory)
                                           && (find(player.inventory.begin(),player.inventory.end(),"Part D")) != end(player.inventory)
                                           && (find(player.inventory.begin(),player.inventory.end(),"Part D")) != end(player.inventory)){
                cout<<"You finish collecting all the docs and remember that the note at the beginning mentioned that the docs would be useful for your escape.\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"You stick the docs together and a converted ASCII number series is then shown between the edge of each docs.\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"You affirm that the series should be used for the pager… “055 050 049 056 051 049”\n";
            }
            else if ((command == "lookat Part D") && (find(player.inventory.begin(),player.inventory.end(),"Part D")) != end(player.inventory)){
                cout<<"You look at the document and find that it is just like a section of a whole uncensored context.\n";
                this_thread::sleep_for (chrono::seconds(7));
                cout<<"“Seems that more documents are required to figure out what actually it is…”\n";
            }
            else if (command != " "){
                cout<<"Seems it doesn't work properly. Try again.\n";
            }
        }



  return 0;
}


void StartNewGame(Player& player, Puzzle& puzzle){
  srand(time(NULL));
  //Initialise Inventory, puzzle
  puzzle.pencode = "oleg";
  puzzle.rooma = "kramer";
  puzzle.roombclock = 161059;
  puzzle.roomb = rand() % 900000 + 100000;
  puzzle.roomc = 896424;
  puzzle.roomd = 810364;
  puzzle.roomblock = false;
  puzzle.roomclock = false;
  puzzle.roomdlock = false;

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
  string confirm;
  cout<< "Commands:\n"
      << "grab <item>\n"
      << "lookat <item>\n"
      << "use <item>\n"
      << "use <item> <keyword/number/item>\n"
      << "moveto <room>\n"
      << "{ Remember to grab the object into the inventory before looking at it … }\n"

      << "Location \n"
      << "Inventory\n"
      << "Savegame\n"
      << "Loadgame\n"
      << "Listcommands\n"
      << "Type \"next\" to proceed.\n";
  cin >> confirm;
  while (confirm != "next"){
    cout<< "Type \"next\" to proceed.\n";
    cin>>confirm;
  }
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
      cout<<player.inventory[i]<<endl;
    }
  }
  else{
    cout<<"You have no item in your list now. Use \"grab\" command to grab something!\n";
  }
}

void Beginning(Player player){
  cout << "You find your[self] in a sealed room named [room "<<player.location<<"].\n" ;
  this_thread::sleep_for (chrono::seconds(6));
  cout << "Earthworms and cockroaches are stretching their legs.\n" ;
  this_thread::sleep_for (chrono::seconds(6));
  cout << "You have to leave this place as soon as possible.\n" ;
}
void LockPassword(Puzzle &puzzle){
  cout<<"Please enter your password: _ _ _ _ _ _"
  cin << pw ;
  if (pw == puzzle.rooma){
      puzzle.roomblock = true
  }
  else if (pw == puzzle.roomb){
      puzzle.roomclock = true
  }
  else if (pw == puzzle.roomc){
      puzzle.roomdlock = true
  }
  else if (pw == puzzle.roomd){
      puzzle.pagerlock = true
  }
}
void RoomMove(Player player,Puzzle puzzle,string command){
  if(command == "A"){
      player.location = "A";
  }
  else if(puzzle.roomblock && command == "B"){
       player.location = "B";
  }
  else if(puzzle.roomclock && command == "C"){
       player.location = "C";
  }
  else if(puzzle.roomdlock && command == "D"){
       player.location = "D";
  }
}
