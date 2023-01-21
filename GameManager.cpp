#include "GameManager.h"
#include "Player.h"
#include "Deck.h"

#include <string>
#include <iostream>
using namespace std;

GameManager::GameManager(Player * p1, Player * p2){
    
    players[0] = p1;
    players[1] = p2;
    
}

//Triggers if a player has won the game
bool GameManager::GameWon(Player * player){
    
    cout << "Player " << player->GetPlayerNum() << " has won the game!" << endl;
    return true;
}

//Triggers if a player forfits
void GameManager::Forfit(Player * player){
    
    cout << "Player " << player->GetPlayerNum() << " has forfited the game!" << endl; 
    
    if (player->GetPlayerNum() == 1){
        cout << "Player 2 has won the game!" << endl;
    }
    else{
        cout << "Player 1 has won the game!" << endl;
    }
}

//Clears the console of text to prevent cheating
void GameManager::ClearConsole(){
    system("clear");
    system("clear");
}

GameManager::~GameManager(){
    
}