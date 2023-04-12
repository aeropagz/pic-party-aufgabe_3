#pragma once

#include "Card.hpp"

namespace game
{
    class GuardCard;
}

class game::GuardCard : public game::AbstractCard
{
public:
    GuardCard();
     
    virtual void display() override;
};