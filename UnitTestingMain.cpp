#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "GameManager.h"
#include "ActionCard.h"
#include "StandardCard.h" 
#include "WildCard.h"
#include "Draw2.h"

#include <iostream>
#include <string>

using namespace std;

int main(){
    //sets the seed of the random number generator to be 1
    srand (1);
    
    int test = -1;
    
    while (test != 0){
        test = -1;
        cout << "0: exit | 1: StandardCard.cpp | 2: Deck.cpp | 3: Player.cpp | 4: GameManager.cpp | 5: Draw2.cpp | 6: WildCard.cpp "<< endl;
        cin >> test;
        
        //cout << "[Debug] 1" << endl;
        
        if (test == 0)
            return 0;
        
        
        /*Card.cpp Unit Testing*/
        if (test == 1){
        cout << "Card.cpp Testing Starting" << endl;
        
        StandardCard card1;
        //Card card2 = Card("Red",5);
        
        //cout << "Card1: " << card1.GetColor() << " " << card1.GetNumber() << endl;
        //cout << "Card2: " << card2.GetColor() << " " << card2.GetNumber() << endl;
        
        string colour;
        int number;
        
        cin >> colour;
        cin >> number;
        
        card1.SetColor(colour);
        card1.SetNumber(number);
        
        cout << "Card1 (modified): " << card1.GetColor() << " " << card1.GetNumber() << endl;
        
        cout << "Card.cpp Testing Finished" << endl << endl;
        }
        
        /*Deck.cpp Unit Testing*/
        if (test == 2){
            cout << "Deck.cpp Testing Starting" << endl;
            Deck deck1; //Also runs SetDeck()
            
            cout << "SetDeck():" << endl;
            
            //This makes sure SetDeck() is working correctly, as wells as GetDeck()
            for (int i = 0; i < deck1.GetDeckSize(); i++){
            
            cout << deck1.GetDeck()[i]->GetColor() << " " << deck1.GetDeck()[i]->GetNumber() << endl;
            
            }
            
            cout << "Deck size: " << deck1.GetDeckSize() << endl;
            
            //20 tests should be enough for ChoseRandomCard()
            cout << "Random Card Test" << endl;
            
            Card * cardTest;
            
            for (int i = 0; i < 20; i++){
                
                cardTest = deck1.ChoseRandomCard();
                //Output Random Cards
                cout << "Card " << i+1 << ": " << cardTest->GetColor() << " " << cardTest->GetNumber() << endl;
            }
            
            cout << "GetLastPlayedCard: " << deck1.GetLastPlayedCard()->GetColor() << " " << deck1.GetLastPlayedCard()->GetNumber() << endl;
            
            StandardCard standardCard = StandardCard("Yellow", 4);
            
            Card * card = &standardCard;
            
            deck1.SetLastPlayedCard(card);
            
            cout << "GetLastPlayedCard (modified): " << deck1.GetLastPlayedCard()->GetColor() << " " << deck1.GetLastPlayedCard()->GetNumber() << endl;
            
            cout << "Deck.cpp Testing Finished" << endl << endl;
        }
        
        /*Player.cpp Unit Testing*/
        if (test == 3){
            
            GameManager * GM;
            Deck d;
            
            cout << "Player.cpp Testing Starting" << endl;
            
            Player player1 = Player(1, GM, d);
            
            cout << "[DEBUG] 1" << endl;
            
            //Get player number and size of their hand
            cout << "Player " << player1.GetPlayerNum() << " | Deck size: " << player1.GetHandSize() << endl;
            
            
            //pick up 7 cards
            player1.PickUpCard(7);
            
            cout << "Player " << player1.GetPlayerNum() << " | Deck size(modified): " << player1.GetHandSize() << endl;
            
            //See cards in hand
            cout << "Iterating through hand:" << endl;
            for (int i = 0; i < player1.GetHandSize(); i++){
                
                cout << "Card " << i+1 << ": " << player1.GetHand().at(i)->GetColor() << " " << player1.GetHand().at(i)->GetNumber() << endl;
            }
            
        }
        
        /*GameManager.cpp Unit Testing*/
        if (test == 4){
            
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
            
            cout << "ClearConsole()" << endl;
            GM->ClearConsole();
            
            cout << "GameManager.cpp Testing Starting" << endl;
            
            cout << "GameWon()" << endl;
            GM->GameWon(p1);
            GM->GameWon(p2);
            
            cout << "Forfit()" << endl;
            GM->Forfit(p1);
            GM->Forfit(p2);
            
            
        }
        
        /*Draw2.cpp Unit Testing*/
        if (test == 5){
            
            Draw2 d2;
            
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
            
            
            cout << "Draw2.cpp Testing Starting" << endl;
            
            cout << d2.GetColor() << " " << d2.GetActionName() << endl;
            
            cout << "Player hand size before" << endl;
            cout << p2->GetHandSize() << endl;
            
            d2.ActivateCardPower(p1, p2, deck);
            
            cout << "Player hand size after" << endl;
            cout << p2->GetHandSize() << endl;
        }
        
        //cout << "[Debug] 2" << endl;
        
        /*WildCard.cpp Unit Testing*/
        if (test == 6){
            
            WildCard wc;
            
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
            
            StandardCard sc = StandardCard("Yellow", 4);
            Card * card = &sc;
            
            deck.SetLastPlayedCard(card);
            
            cout << "WildCard.cpp Testing Starting" << endl;
            
            //cout << "[Debug] 3" << endl;
            
            cout << "Last Played Card: " << deck.GetLastPlayedCard()->GetColor() << " " << deck.GetLastPlayedCard()->GetNumber() << endl;
            
            wc.ActivateCardPower(p1, p2, deck);
            
            cout << "Last Played Card (modified): " << deck.GetLastPlayedCard()->GetColor() << " " << deck.GetLastPlayedCard()->GetActionName() << endl;
            //cout << "[Debug] 4" << endl;
        }
    }
    
    return 0;
}