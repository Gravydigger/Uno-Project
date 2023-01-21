#ifndef STANDARDCARD_H
#define STANDARDCARD_H

#include "Card.h"

#include <string>
using namespace std;

class StandardCard : public Card{
  protected:
    //Variables
    int number;
  
  public:
    //Constructor
    StandardCard();
    StandardCard(string color,int number);
    
    //Getters & Setters
    int GetNumber();
    void SetNumber(int number);
    
    //Deconstructor
    ~StandardCard();
};

#endif // STANDARDCARD_H