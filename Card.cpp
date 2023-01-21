#include "Card.h"

#include <string>
using namespace std;

Card::Card(){
    
    color = "";
}

Card::Card(string color){
    
    this->color = color;
}

string Card::GetColor(){
    
    return color;
    
}

void Card::SetColor(string color){
    
    this->color = color;
    
}

int Card::GetNumber(){
    return -1;
}

string Card::GetActionName(){
    return "[UNDEF]";
}

void Card::ActivateCardPower(Player * player, Player * target, Deck deck){
    
    
}

Card::~Card(){
    
}