#include "PrincessCard.hpp"

using game::PrincessCard;

static const std::string PrincessFont = "\u001b[1m  \e[1;97m";

PrincessCard::PrincessCard() : AbstractCard{"Prinzessin", 8, "RIP wenn du die ablegst"} {}



void PrincessCard::display(){
    std::cout 
    << PrincessFont
    << getName()
    << "\n"
    << getRank() 
    << "\n"
    << getEffect() 
    << colorOff
    << "\n" 
    <<  std::endl;
}