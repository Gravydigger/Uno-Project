#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"

#include <string>
#include <vector>
using namespace std;

class GameManager;
class Card;

class Player{
    private:
        //Variables
        static int startingHandSize;
        
    protected:
        //Variables
        int playerNum;
        vector<Card*> hand;
        GameManager * gm;
        Deck d;
        
    public:
        //Constructor
        Player(int playerNum,GameManager * gm, Deck d);
        
        //Getters & Setters
        int GetPlayerNum();
        int GetHandSize();
        vector<Card*> & GetHand();
        
        //When a game begins, give the player "startingHandSize" cards
        void PickUpCard(int numOfCards);
        
        //Does various option depending on what was selected
        bool TakeTurn(int selectedOption);
        
        
        
        //Deconstructor
        ~Player();
};

#endif // PLAYER_H