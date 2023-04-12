#pragma once

#include "Card.hpp"

namespace game
{
    class BaronCard;
}

class game::BaronCard : public game::AbstractCard
{
public:
    BaronCard();
     
    void display() override;
};