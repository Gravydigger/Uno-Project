#include "StandardCard.h"

#include <string>
using namespace std;

StandardCard::StandardCard() : Card(""){
    
    number = 0;
}

StandardCard::StandardCard(string color,int number) : Card(color){
    
    this->number = number;
}

int StandardCard::GetNumber(){
    
    return number;
    
}

void StandardCard::SetNumber(int number){
    
    this->number = number;
    
}

StandardCard::~StandardCard(){
    
}