#include "PriestCard.hpp"

using game::PriestCard;

static const std::string PriestFont = "\u001b[1m  \e[1;91m";

PriestCard::PriestCard() : AbstractCard{"Priester", 2, "Schaue dir die Handkarte eines Spielers an"} {}



void PriestCard::display(){
    std::cout 
    << PriestFont
    << getName()
    << "\n"
    << getRank() 
    << "\n"
    << getEffect() 
    << colorOff
    << "\n" 
    <<  std::endl;
}
