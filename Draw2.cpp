#include "Draw2.h"

#include <string>
using namespace std;


Draw2::Draw2() : ActionCard("[UNDEF]","[DRAW 2]"){

}

Draw2::Draw2(string color) : ActionCard(color,"[DRAW 2]"){

}

//Abstract Class
void Draw2::ActivateCardPower(Player * player, Player * target, Deck deck){
    
    
    target->PickUpCard(2);
    
}

Draw2::~Draw2(){
    
}