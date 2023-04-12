#include "Card.hpp"

using game::AbstractCard;

AbstractCard::AbstractCard(const string &name, const int rank, const string &effect) : name_{name}, rank_{rank}, effect_{effect} {}

string AbstractCard::getEffect()
{
    return effect_;
}

string AbstractCard::getName()
{
    return name_;
}

int AbstractCard::getRank()
{
    return rank_;
}

void AbstractCard::display()
{
    std::cout << getName()
              << "\n"
              << getRank()
              << "\n"
              << getEffect()
              << "\n"
              << std::endl;

    return;
}