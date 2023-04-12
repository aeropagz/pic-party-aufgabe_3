#pragma once
#include "Player.hpp"

namespace game
{
    class HumanPlayer;
}

class game::HumanPlayer : public Player
{
public:
    explicit HumanPlayer(const string &name);
    void action(Game &game) override;
    string chooseCardName(const vector<string> &names) override;
};