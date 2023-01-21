#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "GameManager.h"

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main(){
    //sets the seed of the random number generator
    srand (time(NULL));
    
    //Inisalise & set global Variables
    Deck deck;
    
    GameManager * GM;
    
    Player * p1;
    Player * p2;
    
    GameManager gameManager(p1, p2);
    Player player1(1,GM,deck);
    Player player2(2,GM,deck);
    
    GM = &gameManager;
    p1 = &player1;
    p2 = &player2;
    
    // Makes the players pick up 7 starting cards
    p1->PickUpCard(7);
    p2->PickUpCard(7);
    
    //These variables are for the loop below
    bool hasPlayerWon = false;
    bool player1Turn = true;
    Player * currentPlayer;
    Player * nextPlayer;
    
    cout << "Welcome to Uno!" << endl;
    //Exits the loop is a player has won
    while(!hasPlayerWon){
        
        //Sees who's turn it is
        cout << "Player ";
        if (player1Turn){
            cout << "1";
            currentPlayer = p1;
            nextPlayer = p2;
        }
        else{
            cout << "2";
            currentPlayer = p2;
            nextPlayer = p1;
        }
        cout << ": Your Turn!" << endl << endl;
        
        Card * playedCard = deck.GetLastPlayedCard();
        
        bool optionSelected = false;
        while (!optionSelected){
            
            //Outputs the possible options to the player
            cout << "Played card: " << playedCard->GetColor() << " ";
            
            if (playedCard->GetNumber() < 0){
                
                cout << playedCard->GetActionName();
                
            }
            else{
                
                cout << playedCard->GetNumber();
                
            }
            
            cout << endl;
            
            cout << "What do you want to do?" << endl;
            cout << "0: Forfit game." << endl;
            cout << "1: Pick up 1 card." << endl;
            
            vector<Card *> currentPlayerCard = currentPlayer->GetHand();
            
            for (int i = 0; i < currentPlayer->GetHandSize(); i++){
                
                cout << i + 2 << ": Play the card: [" << currentPlayerCard.at(i)->GetColor() << " ";
                
                if (currentPlayerCard.at(i)->GetNumber() < 0){
                    
                    cout << currentPlayerCard.at(i)->GetActionName();
                    
                }
                else{
                    
                    cout << currentPlayerCard.at(i)->GetNumber();
                    
                }
                cout << "]." << endl;
            }
            
            cout << "Please type the number of the option you want picked." << endl;
            int selectedOption = -1;
            cin >> selectedOption;
            
            //Sees if the input was valid
            if (!cin){
                cin.clear();
                cin.ignore();
                cout << "Invalid input! Please try again with a number!" << endl;
                
            }
            else{
                
                //Forfit option
                if (selectedOption == 0){
                    // currentPlayer->TakeTurn(selectedOption);
                    GM->Forfit(currentPlayer);
                    hasPlayerWon = true;
                    optionSelected = true;
                }
                //if the player wants to pick up a card
                else if (selectedOption == 1){
                    
                    currentPlayer->PickUpCard(1);
                    
                }
                // sees if the inputed value is greater that zero, and the size of the players deck (+2 for the other 2 options)
                else if (selectedOption >= 2 && selectedOption <= currentPlayer->GetHandSize() + 2){
                    
                    //Checks to see if the card is an action card
                    if (currentPlayerCard.at(selectedOption - 2)->GetNumber() < 0){
                        
                        currentPlayerCard.at(selectedOption - 2)->ActivateCardPower(currentPlayer, nextPlayer, deck);
                        
                    }
                    
                    //Exits the while loop, and executes the turn
                    optionSelected = currentPlayer->TakeTurn(selectedOption - 2);
                }
                else{
                    cout << "Invalid option! Please try again." << endl;
                }
                
            }
            
        }
        
        if (currentPlayer->GetHandSize() <= 0){
            GM->GameWon(currentPlayer);
            hasPlayerWon = true;
        }
        else if (hasPlayerWon == true){
            //empty else if statment for the forfit option
        }
        else if (!player1Turn){
            GM->ClearConsole();
            player1Turn = true;
        }
        else{
            GM->ClearConsole();
            player1Turn = false;
        }
    }
    
    return 0;
}