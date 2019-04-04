#include <iostream>
#include <string>
#include <stdlib.h>
#include "gameengine.h"
//Included Libraries
// #include "restoran.h"
// #include <ncurses.h>

using namespace std;




int main(){
    std::cout << "Rika's Farm" <<std::endl;
    std::cout << "A Game build with C++ using Object Oriented Paradigm" <<std::endl;
    std::cout << "========================================================" <<std::endl;
    std::cout << "Lukas Kurnia Jonathan / 13517006" <<std::endl;
    std::cout << "Eginata Kasan / 13517030" <<std::endl;
    std::cout << "Vivianni / 13517060" <<std::endl;
    std::cout << "Gardahadi / 13517144" <<std::endl;
    std::cout << "Rika Dewi / 13517147" <<std::endl;
    std::string command;
    cout << "Silahkan Input sesuatu untuk mulai" << endl;
    cin >> command;

    /*****************************
    Inisialisasi Objek-objek Game
    *****************************/
    bool gameOver = false; 
    GameEngine G;
    string Message = "Welcome To Engi's Kitchen, click HELP for a list of commands";

    while(!gameOver){

        //Clear Screen and print Map
        system("clear");        
        G.printMap();
        std::cout<< "Message : ";
        G.printMessage(Message);
        std::cout<< "Command : " ;
        std::cin >> command;
        if(command.compare("TALK")==0){

        }
        else if(command.compare("GROW")==0){
            
        }
        else if(command.compare("KILL")==0){
            
        }
        else if(command.compare("INTERACT")==0){
            
        }
        else if(command.compare("GL")==0){
            
        }
        else if(command.compare("GD")==0){
            
        }
        else if(command.compare("GU")==0){
            
        }
        else if(command.compare("GR")==0){
            
        }
        else if (command.compare("EXIT") == 0) {
            gameOver = true;
        }
        
    }

    return 0;
}