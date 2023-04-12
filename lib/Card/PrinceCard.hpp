#pragma once

#include "Card.hpp"

namespace game
{
    class PrinceCard;
}

class game::PrinceCard : public game::AbstractCard
{
public:
    PrinceCard();
     
    virtual void display() override;
};