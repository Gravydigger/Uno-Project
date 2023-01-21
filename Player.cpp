#include "Player.h"
#include "GameManager.h"
#include "Card.h"

#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int Player::startingHandSize;


Player::Player(int playerNum, GameManager * gm, Deck d){
    
    this->playerNum = playerNum;
    this->gm = gm;
    this->d = d;
    startingHandSize = 7;
}

int Player::GetPlayerNum(){
    return playerNum;
    
}
int Player::GetHandSize(){
    return hand.size();
    
}
vector<Card*> & Player::GetHand(){
    return hand;
    
}

//When a game begins, give the player "startingHandSize" cards
void Player::PickUpCard(int numOfCards){
    
    //Number less than 1, give starting deck.
    if (numOfCards <= 0)
        numOfCards = startingHandSize;
    
    for (int i = 0; i < numOfCards; i++){
        
        //create a reference of a new card at random
        Card *card = d.ChoseRandomCard();
        
        //place reference into ther players hand
        hand.push_back(card);
        
    }
    
}

//Does various option depending on what was selected, and says if it was successful
bool Player::TakeTurn(int selectedOption){
    
    //0 -> forfit
    //1 -> pickup card & restart turn
    //2 - infinity -> card selection
    
    //Finds the card the player has selected, remove the card from their hand, and place it on the discard pile

    //Sees if the card can be played
    
    if (d.GetLastPlayedCard()->GetColor() == GetHand().at(selectedOption)->GetColor() ||
        d.GetLastPlayedCard()->GetNumber() == GetHand().at(selectedOption)->GetNumber() ||
        d.GetLastPlayedCard()->GetActionName() == GetHand().at(selectedOption)->GetActionName()){
        
        //Stets the card on the discard pile
        d.SetLastPlayedCard(GetHand().at(selectedOption));
        
        //removes card from hand
        GetHand().erase(GetHand().cbegin() + selectedOption);
        return true;
    }
    
    else{
        
        cout << "Selected card cannot be played!" << endl; 
        return false;
    }

    
    cout << "[DEBUG]Selected card cannot be played!" << endl; 
    return false;
}

//Deconstructor
Player::~Player(){

}
