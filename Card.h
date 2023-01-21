#ifndef CARD_H
#define CARD_H

#include "Player.h"
#include "Deck.h"

class Player;
class Deck;

#include <string>
using namespace std;

class Card{
  protected:
    //Variables
    string color;
  
  public:
    //Constructor
    Card();
    Card(string color);
    
    //Getters & Setters
    string GetColor();
    virtual void SetColor(string color);
    
    virtual int GetNumber();
    virtual string GetActionName();
    
    //This should be an abstract, but I don't know how to contain both action cards and standard cards in a single array, so it stays
    virtual void ActivateCardPower(Player * player, Player * target, Deck deck);
    //Deconstructor
    ~Card();
};

#endif // CARD_H