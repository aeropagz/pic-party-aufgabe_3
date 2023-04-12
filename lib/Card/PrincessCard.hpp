#pragma once

#include "Card.hpp"

namespace game
{
    class PrincessCard;
}

class game::PrincessCard : public game::AbstractCard
{
public:
    PrincessCard();
     
    virtual void display() override;
};