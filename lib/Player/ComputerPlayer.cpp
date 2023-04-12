#include <random>
#include "ComputerPlayer.hpp"
#include "Game.hpp"

using game::ComputerPlayer;

ComputerPlayer::ComputerPlayer(const string &name) : Player{name} {}

void ComputerPlayer::action(Game &game)
{
    int choice = randomDecision(1, 2);
    game.executeCard(playCard(choice));
}

int ComputerPlayer::randomDecision(int start, int end)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(start, end);
    return dist6(rng);
}

string ComputerPlayer::chooseCardName(const vector<string> &names)
{
    return names.at(randomDecision(0, names.size() - 1));
}
