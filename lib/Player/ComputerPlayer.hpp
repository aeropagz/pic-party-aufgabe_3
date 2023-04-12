#pragma once

#include "Player.hpp"

namespace game
{
    class ComputerPlayer;
}

class game::ComputerPlayer : public Player
{
public:
    ComputerPlayer(const string &name);
    void action(Game &game);
    string chooseCardName(const vector<string> &names) override;
    int randomDecision(int start, int end);
};