#ifndef DRAW2_H
#define DRAW2_H

#include "ActionCard.h"

#include <string>
#include <vector>
using namespace std;

class Draw2 : public ActionCard{
    public:
        //Constructor
        Draw2();
        Draw2(string color);
        
        //Abstract Class
        virtual void ActivateCardPower(Player * player, Player * target, Deck deck) override;
        
        //Deconstructor
        ~Draw2();
};

#endif // DRAW2_H