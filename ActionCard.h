#ifndef ACTIONCARD_H
#define ACTIONCARD_H

#include "Card.h"
#include "Player.h"
#include "Deck.h"

#include <string>
#include <vector>
using namespace std;

class ActionCard : public Card{
    protected:
        //Variables
        string actionName;
        
    public:
        //Constructor
        ActionCard();
        
        ActionCard(string color, string actionName);
        
        //Getter & Setter
        string GetActionName();
        void SetActionName(string actionName);
        
        //Abstract Class
        virtual void ActivateCardPower(Player * player, Player * target, Deck deck) = 0;
        
        //Deconstructor
        ~ActionCard();
};

#endif // ACTIONCARD_H