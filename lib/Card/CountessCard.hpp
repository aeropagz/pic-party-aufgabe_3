#pragma once

#include "Card.hpp"

namespace game
{
    class CountessCard;
}

class game::CountessCard : public game::AbstractCard
{
public:
    CountessCard();
     
    virtual void display() override;
};