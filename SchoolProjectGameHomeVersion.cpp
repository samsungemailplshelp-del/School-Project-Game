/*
    Dungeon RPG game - Text/Terminal/Console only! - LF6 Project
    By Mykola & Stylianos
    WI25
*/

//libraries
#include <iostream> //Standard input output stream MUST
#include <thread> //used for the sleep part of the code (Replacable)
#include <string> //used for string (Replacable)
#include <fstream> //used to check text files for information on the players Data & NPC Data

//headers
    /*-------------*/


//functions | voids
    /*-------------*/




int main() //Main
{
    //Variables
    bool gameIsRunning = true; //Game looping bool | if it turns to false the program ends

    //Classes
    class Player
    {
    public:
        std::string PlayerName;
        float maxhp;
        float hp;
        float basedmg;
        float dmg;
        float defense;
        int status;

            bool loadFromFile(const std::string& filename)
            {
                std::ifstream file(filename);

                if (!file.is_open()) //FOR MYKOLA: the '!' before the file.is_open() means if the file is NOT open!
                {
                    return false; //failed to open the file
                }

                std::getline(file, PlayerName);
                file >> maxhp;
                file >> hp;
                file >> basedmg;
                file >> dmg;
                file >> defense;
                file >> status;

                file.close();
                return true;
            }
    }; //Player class

    class Enemy
    {
    public:
        std::string EnemyName = Evil_Larry;
        float maxhp;
        float hp;
        float basedmg;
        float dmg;
        float defense;
        bool status;
    }; //Enemy class

    while(gameIsRunning)
    {
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
                    break;

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


        return 0; //return 0

    }//gameIsRunning conditions + loop start
} //main
