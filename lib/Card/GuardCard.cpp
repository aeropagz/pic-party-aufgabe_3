#include "GuardCard.hpp"

using game::GuardCard;

static const std::string GuardFont = "\u001b[1m  \e[1;33m ";

GuardCard::GuardCard() : AbstractCard{"Wächter", 1, "Rate die Karte eines Spielers (!Wächter)"} {}

void GuardCard::display()
{
    std::cout
        << GuardFont
        << getName()
        << "\n"
        << getRank()
        << "\n"
        << getEffect()
        << colorOff
        << "\n"
        << std::endl;
}