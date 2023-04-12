#include "BaronCard.hpp"

using game::BaronCard;
using std::cout;
using std::endl;

static const std::string BaronFont = "\e[1m  \e[1;95m";

BaronCard::BaronCard() : AbstractCard{"Baron", 3, "Vergleiche deine Handkarte mit der eines Spielers"} {}

void BaronCard::display()
{
    std::cout
        << BaronFont
        << getName()
        << "\n"
        << getRank()
        << "\n"
        << getEffect()
        << colorOff
        << "\n"
        << std::endl;
}