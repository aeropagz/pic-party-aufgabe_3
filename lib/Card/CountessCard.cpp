#include "CountessCard.hpp"

using game::CountessCard;
using std::cout;
using std::endl;

static const string CountessFont = "\u001b[1m \e[1;34m";

CountessCard::CountessCard() : AbstractCard{"Gräfin", 7, "Du musst die Karte spielen wenn du einen Prinzen oder König hast"} {}



void CountessCard::display(){
    
    std::cout 
    << CountessFont
    << getName()
    << "\n"
    << getRank() 
    << "\n"
    << getEffect() 
    << colorOff
    << "\n" 
    <<  std::endl;
}

