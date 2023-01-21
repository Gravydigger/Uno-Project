#include "WildCard.h"
#include "Card.h"
#include "Deck.h"

#include <string>
#include <iostream>
using namespace std;

Card * WildCard::wildCardColor;

WildCard::WildCard() : ActionCard("[UNDEF]","[WILDCARD]"){

}

WildCard::WildCard(string color) : ActionCard(color,"[WILDCARD]"){

}

//Abstract Class
void WildCard::ActivateCardPower(Player * player, Player * target, Deck deck){
    
    PickNewColor(deck);
    
}

void WildCard::PickNewColor(Deck deck){
    
    string color;
    string setColor;
    
    cout << "What colour do you pick? (Y, G, R, B)" << endl;
    cin >> color;
    
    //cout << "[DEBUG] 1" << endl;
    
    if (!cin){
        cin.clear();
        cin.ignore();
        cout << "Invalid input! Please try again with a number!" << endl;
        return;
    }
    
    //Figures out which colour the player picked
    if (color == "Y" || color == "y"){
        //wildCardColor = WildCard("Yellow");
        setColor = "Yellow";
    }
    
    else if (color == "G" || color == "g"){
        //wildCardColor = WildCard("Green");
        setColor = "Green";
    }
    
    else if (color == "R" || color == "r"){
       // wildCardColor = WildCard("Red");
       setColor = "Red";
    }
    
    else if (color == "B" || color == "b"){
       // wildCardColor = WildCard("Blue");
       setColor = "Blue";
    }
    
    else{
        cout << "Invalid Selection!" << endl;
        return;
    }
    
    wildCardColor = new WildCard(setColor);
    
    deck.SetLastPlayedCard(wildCardColor);
}

WildCard::~WildCard(){
    delete wildCardColor;
}