#pragma once

#include "Card.hpp"

namespace game
{
    class MaidCard;
}

class game::MaidCard : public game::AbstractCard
{
public:
    MaidCard();
     
    virtual void display() override;
};