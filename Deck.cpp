#include "Deck.h"
#include "StandardCard.h"
#include "Draw2.h"
#include "WildCard.h"

#include <string>
using namespace std;

int Deck::deckSize = 45;
Card ** Deck::deck;
Card * Deck::LastPlayedCard;

Deck::Deck(){
    //size of a typical Uno deck, but only with non-action cards
    //https://en.wikipedia.org/wiki/Uno_(card_game)
    SetDeck();
    
    LastPlayedCard = ChoseRandomCard();
    
}

int Deck::GetDeckSize(){
    return deckSize;
}

void Deck::SetDeck(){
    
    deck = new Card*[deckSize];
    
    /*
    From wikipedia: 'The deck consists of 108 cards:
    Four each of "Wild" and "Wild Draw Four",
    25 each of four different colors (red, yellow, green, blue).
    Each color consists of one zero, two each of 1 through 9,
    and two each of "Skip," "Draw Two," and "Reverse".
    
    I'll be using just the non-action cards currnetly.
    */
    
    //Instead of checking the exact amount of cards are in the deck, just pick a random card
    //This will initilised all possible non-action cards
    
    for (int i = 0; i < deckSize; i++){
        
        if (i <= 9)
            deck[i] = new StandardCard("Yellow",i);
        
        if (i > 9 && i <= 19)
            deck[i] = new StandardCard("Red",i - 10);
        
        if (i > 19 && i <= 29)
            deck[i] = new StandardCard("Green",i - 20);
        
        if (i > 29 && i <= 39)
            deck[i] = new StandardCard("Blue",i -30);
        if (i == 39){
            deck[i] = new Draw2("Yellow");
            deck[i+1] = new Draw2("Yellow");
            deck[i+2] = new Draw2("Yellow");
            deck[i+3] = new Draw2("Yellow");
        }
        //i == 40 to i == 43 have been skipped, as they have been reserved above
          
        if (i == 44)
            deck[i] = new WildCard("Black");
    }
}

Card** Deck::GetDeck(){
    
    return deck;
}

//Picks a possible card from the deck thats avaliable
Card * Deck::ChoseRandomCard(){
    
    //generate a percentage of normal cards to power cards
    int x = rand() % 100 + 1; // Picks a random number between 0 to 100
    
    int i; // Card selector
    
    // 80% of the time, pick a standard card
    if (x < 80){
        i = rand() % 39; // Picks a random Standard Card
    }
    // 15% of the time, pick a Draw 2
    else if (x >= 80 && x < 95){
        i = rand() % 3; // Picks a random Draw 2 Card
        i += 39;
    }
    
    // 5% of the time, give a Wild Card
    else{
        i = 44;
    }

    return deck[i]; 
    
}

void Deck::SetLastPlayedCard(Card * card){
    LastPlayedCard = card;
}

Card* Deck::GetLastPlayedCard(){
    return LastPlayedCard;
}

// StandardCard* Deck::GetLastPlayedStandardCard(){
//     return LastPlayedCard;
// }
// ActionCard* Deck::GetLastPlayedActionCard(){
//     return LastPlayedCard;
// }

//Deconstructor
Deck::~Deck(){
    
    /*This shouldn't be commented. However, for some god forsaken reason, it causes a "double free or corruption (!prev)". I have no idea why. Regardless, I rather have a small memory leak, than to deal with that s***.
    Don't belive me? try uncommenting it below, compile UnitTest, then run the wildcard.cpp test TWICE. You'll see the error*/
    //delete[] deck;
}