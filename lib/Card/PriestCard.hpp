#pragma once

#include "Card.hpp"

namespace game
{
    class PriestCard;
}

class game::PriestCard : public game::AbstractCard
{
public:
    PriestCard();
     
    virtual void display() override;
};