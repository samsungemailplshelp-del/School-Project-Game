
// THIS HEADER IS MADE SO THAT WE CAN RUN THE MAIN MENU EASILY WITHIN THE MAIN PROGRAM THAT WILL RUN THE GAME WITHOUT MAKING IT VERY VERY LONG !!!

#ifndef GAMESTART_H_INCLUDED
#define GAMESTART_H_INCLUDED
#include <iostream>
#include <thread>

void mainMenu()
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
                     system("cls");
                     break;

                     //Quitting
                case 2:
                    system("cls");
                    std::cout<<"\nQuitting . . .";
                    std::this_thread::sleep_for(std::chrono::seconds(5));
                    system("cls");
                    std::cout<<"\nSuccessfully quit\n\n";
                    mainMenu0 = false;
                    break;

                    //False Input Error
                default:
                    std::cout<<"\nTry again!";
                    break;

            } //Main Menu Answer

        } //Main Menu Question

    } //mainMenu Loop

} //mainMenu function

#endif // GAMESTART_H_INCLUDED
