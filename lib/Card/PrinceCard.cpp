#include "PrinceCard.hpp"

using game::PrinceCard;

static const std::string PrinceFont = "\u001b[1m  \e[1;93m";

PrinceCard::PrinceCard() : AbstractCard{"Prinz", 5, "Wähle einen Spieler zum Ablegen seiner Handkarte"} {}



void PrinceCard::display(){
    std::cout 
    << PrinceFont
    << getName()
    << "\n"
    << getRank() 
    << "\n"
    << getEffect() 
    << colorOff
    << "\n" 
    <<  std::endl;
}