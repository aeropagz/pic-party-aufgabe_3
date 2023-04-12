#include "KingCard.hpp"

using game::KingCard;

static const std::string KingFont = "\u001b[1m  \e[1;92m";

KingCard::KingCard() : AbstractCard{"König", 6, "Tausche deine Handkarte mit der eines Spielers"} {}



void KingCard::display()
{
    std::cout
        << KingFont
        << getName()
        << "\n"
        << getRank()
        << "\n"
        << getEffect()
        << colorOff
        << "\n"
        << std::endl;
}