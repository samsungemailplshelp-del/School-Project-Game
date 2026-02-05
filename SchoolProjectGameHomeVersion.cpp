#include <iostream>
#include <string>
#include <random>
#include <thread>
#include <fstream>
using std::endl;
using std::string;


class Player {
    public:
        string name;
        int Maxhp;
        float hp;
        float attack;
        float defense;
        int level;
        int exp;
        int gold;
        int status;
}; //Player class

class NPC {
    public:
        string npcname;
        int Maxhp;
        float hp;
        float attack;
        float defense;
        int level;
        int status;
}; //NPC class

Player player;
NPC basicEnemy;

void fight() {
    bool Playerturn = true;
    bool Enemyturn = false;
    bool SomeoneRun = false;
    bool Playerdefending = false;
    while(player.hp > 0 && basicEnemy.hp > 0 && SomeoneRun == false) {
        float Fdmgdlt = (player.attack / basicEnemy.defense);
        if(Playerturn) {
            int playerchoice;
            std::cout<<"choose your action: "<<endl;
            std::cout<<"1. Attack"<<endl;
            std::cout<<"2. Defend"<<endl;
            std::cout<<"3. Run"<<endl;
            std::cin>>playerchoice;

            switch(playerchoice) {
                case 1: //Attack
                    basicEnemy.hp -= Fdmgdlt;
                    std::cout<<"you dealt "<<Fdmgdlt<<" damage to "<<basicEnemy.npcname<<"."<<endl;
                    std::cout<<"Enemy HP: "<<basicEnemy.hp<<endl;
                    Playerturn = false;
                    Enemyturn = true;
                    break;
                case 2: //Defend
                    std::cout<<"You brace yourself for the next attack."<<endl;
                    Playerdefending = true;
                    Playerturn = false;
                    Enemyturn = true;
                    break;
                case 3: //Run
                    std::cout<<"You fled from the battle!"<<endl;
                    SomeoneRun = true;
                    break;
                default:
                    std::cout<<"Invalid choice, try again!"<<endl;
                    break;
        }//PlayerTurn switch
    }//Playerturn
        if(Enemyturn){
            if(Playerdefending){
                float Edmgdlt = (basicEnemy.attack / player.defense) / 2; //Defending reduces damage by half
                player.hp -= Edmgdlt;
                std::cout<<basicEnemy.npcname<<" dealt "<<Edmgdlt<<" damage to you."<<endl;
                std::cout<<"Your HP: "<<player.hp<<endl;
                Playerdefending = false; //Reset defending status after enemy turn
                Enemyturn = false;
                Playerturn = true;
            }//Enemy Attack (DEFEND)
            else {
                float Edmgdlt = (basicEnemy.attack / player.defense);
                player.hp -= Edmgdlt;
                std::cout<<basicEnemy.npcname<<" dealt "<<Edmgdlt<<" damage to you."<<endl;
                std::cout<<"Your HP: "<<player.hp<<endl;
                Enemyturn = false;
                Playerturn = true;
            }//Enemy Attack (NORMAL)
        }//Enemyturn
    } //while fight
    if (player.hp <= 0 ) {
        std::cout<<"You have been defeated..."<<endl;
        player.status = 0;
    } //Game Over
    else if (basicEnemy.hp <= 0) {
        std::cout<<"You have defeated "<<basicEnemy.npcname<<"!"<<endl;
        player.exp += 20;
        player.gold += 10;
        std::cout<<"You gained 20 EXP and 10 Gold."<<endl;
    } //Victory
    std::this_thread::sleep_for(std::chrono::seconds(3));
    system("cls");
} //fight

int main() {
    bool gameIsRunning = true; //game loop control variable

    while(gameIsRunning) {
             //Variables Necessary for the Game's Main Menu
    bool mainMenu0 = true; //game loop
    bool WelcomeMSG = true; //welcome message pop-up
    bool MainMenuQuestion = true; //start|quit question
    int MainMenuChoice; //start|quit answer

    //Game Start
    while(mainMenu0 == true)
    {
        if(WelcomeMSG == true)
        {
            std::cout<<"Welcome to [Placeholder]!!!";
            WelcomeMSG = false;
        }//welcome message

        if(MainMenuQuestion == true)
        {
            std::cout<<"\n================================\n\n";
            std::cout<<" 1. Start\n 2. Quit\n\n Answer(1 or 2):\t";
            std::cin>>MainMenuChoice;

            if(std::cin.fail())
            {
                std::cout<<"\nFalse Input! STOP messing with my code.. its fragile >:("; //Error message lol
                std::cin.clear(); // FOR MYKOLA: this clears any input given by the user
            }//cin.fail() route | if

            std::cin.ignore(1000, '\n');
                                         /*
                                            FOR MYKOLA: this basically removes any input that isnt a number from the variable
                                            (bc the variable type that saves the answer is "int"
                                            it removes anything that wouldnt be considered an "int" typa answer)
                                         */

            //Main Menu Answer Operation
            switch(MainMenuChoice)
            {
                    //Starting the game
                case 1:
                     system("cls");
                     std::cout<<"\nGame Starting . . .";
                     std::this_thread::sleep_for(std::chrono::seconds(5));
                     MainMenuQuestion = false;
                     mainMenu0 = false; //stops the main menu cycle
                     system("cls");
                     break;

                     //Quitting
                case 2:
                    system("cls");
                    std::cout<<"\nQuitting . . .";
                    std::this_thread::sleep_for(std::chrono::seconds(5));
                    system("cls");
                    std::cout<<"\nSuccessfully quit\n\n";
                    mainMenu0 = false; //stops the main menu cycle
                    gameIsRunning = false; //ENDS THE GAME!!!
                    return 0; //HARD EXIT BC continue; DIDN'T WORK!

                    //False Input Error
                default:
                    std::cout<<"\nTry again!";
                    break;

            } //Main Menu Answer

        } //Main Menu Question

    } //mainMenu Loop

        if(MainMenuChoice == 1)
        {
            std::cout<<"Presenting [PLACEHOLDER] by Mykola & Stylianos\n"; //Intro
        }

        //SETTING UP CLASS INFO HERE MANUALLY!!!
            //basicEnemy
        basicEnemy.npcname = "Goblin";
        basicEnemy.Maxhp = 50;
        basicEnemy.hp = 50.0f;
        basicEnemy.attack = 5.0f;
        basicEnemy.defense = 1.0f;
        basicEnemy.level = 1;

            //player
        player.Maxhp = 100;
        player.hp = 100.0f;
        player.attack = 10.0f;
        player.defense = 1.0f;
        player.level = 1;
        player.exp = 0;
        player.gold = 0;

        //game combat test & start
        std::cout<<"choose your character name: ";
        std::cin>>player.name;
        std::cout<<"hello, "<<player.name<<", good luck on your adventure!"<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("cls");
        fight();
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("cls");
    }//gameloop

    return 0; //end
} //main