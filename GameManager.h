#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

//#include "Player.h"

#include <string>
#include <vector>
using namespace std;

class Player;

class GameManager{
    protected:
        Player * players[2];
        
    public:
    //Constructor
    //GameManager();
    
    GameManager(Player * p1, Player * p2);
    
    //Triggers if a player has won the game
    bool GameWon(Player * player);
    
    //Triggers if a player forfits
    void Forfit(Player * player);
    
    //Clears the console of text to prevent cheating
    void ClearConsole();
    
    //Deconstructor
    ~GameManager();
};

#endif // GAMEMANAGER_H