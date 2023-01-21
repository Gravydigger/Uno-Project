#ifndef WILDCARD_H
#define WILDCARD_H

#include "ActionCard.h"
#include "Player.h"
#include "Deck.h"

#include <string>
#include <vector>
using namespace std;

class WildCard : public ActionCard{
    protected:
        //static string * wildCardColor;
        static Card * wildCardColor;
    
    public:
        //Constructor
        WildCard();
        WildCard(string color);
        
        //Setter
        //void SetColor(string color);
        
        //Abstract Class
        virtual void ActivateCardPower(Player * player, Player * target, Deck deck) override;
        
        void PickNewColor(Deck deck);
        
        //Deconstructor
        ~WildCard();
};

#endif // WILDCARD_H