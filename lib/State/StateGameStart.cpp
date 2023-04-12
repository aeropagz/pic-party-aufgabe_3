#include <memory>
#include "StateGameStart.hpp"
#include "StateGamePlayer.hpp"
#include "ConsoleUtil.hpp"

using state::StateGamePlayer;
using state::StateGameStart;
using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;

StateGameStart::StateGameStart(const string &name) : State{name} {}

void StateGameStart::next()
{
    cout << CLEAR_SCREEN << endl;
    cout << "Möchtest du ein Spiel Loveletter spielen?" << endl;
    context_->game.Start();
    shared_ptr<StateGamePlayer> player_state = std::make_shared<StateGamePlayer>("Choose Playername");
    context_->TransitionTo(player_state);
}
