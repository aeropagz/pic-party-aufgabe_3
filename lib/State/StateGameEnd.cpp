#include <memory>
#include "StateGameEnd.hpp"
#include "ComputerPlayer.hpp"
#include "HumanPlayer.hpp"

using state::StateGameEnd;
using std::cout;
using std::endl;
using std::shared_ptr;

StateGameEnd::StateGameEnd(const string &name) : State{name} {}

void StateGameEnd::next()
{
    string winner;
    if (context_->game.hasComputerWon())
        winner = context_->game.computer_player->getName();
    else
        winner = context_->game.hooman_player->getName();

    context_->game.logger << "Der Spieler " << winner << " hat gewonnen!\n";
    exit(0);
}