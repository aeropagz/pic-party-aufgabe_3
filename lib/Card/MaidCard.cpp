#include "MaidCard.hpp"

using game::MaidCard;

static const std::string MaidFont = "\u001b[1m  \e[1;96m";

MaidCard::MaidCard() : AbstractCard{"Zofe", 4, "Du bist zu deinem nächsten Zug geschützt"} {}


void MaidCard::display(){
    std::cout 
    << MaidFont
    << getName()
    << "\n"
    << getRank() 
    << "\n"
    << getEffect() 
    << colorOff
    << "\n" 
    <<  std::endl;
}