#pragma once

#include "Card.hpp"

namespace game
{
    class KingCard;
}

class game::KingCard : public game::AbstractCard
{
public:
    KingCard();
     
    virtual void display() override;
};