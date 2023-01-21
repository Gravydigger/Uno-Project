#include "ActionCard.h"

#include <string>
using namespace std;

ActionCard::ActionCard() : Card(""){
    //Default constructor of color ""
    actionName = "[UNDEF]";
}

ActionCard::ActionCard(string color, string actionName) : Card(color){
    
    this->actionName = actionName;
    
}

string ActionCard::GetActionName(){
    
    return actionName;
    
}
void ActionCard::SetActionName(string name){
    
    actionName = name;
    
}

ActionCard::~ActionCard(){
    
}