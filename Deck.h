#ifndef DECK_H
#define DECK_H

//#include "StandardCard.h"
//#include "ActionCard.h"

#include <string>
using namespace std;

class Card;

class Deck{
  protected:
    //Variables
    static int deckSize;
    static Card** deck;
    static Card * LastPlayedCard;
    
  public:
    //Constructor
    Deck();
    
    //Setters & Getters
    void SetDeck();
    Card** GetDeck();
    int GetDeckSize();
    
    
    //Picks a possible card from the deck thats avaliable
    Card * ChoseRandomCard();
    
    //Sets and gets the last played Card
    void SetLastPlayedCard(Card * card);
    Card* GetLastPlayedCard();
    
    //Deconstructor
    ~Deck();
};

#endif // DECK_H