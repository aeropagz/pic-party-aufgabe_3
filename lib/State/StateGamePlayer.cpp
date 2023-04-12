#include <memory>
#include <sstream>
#include "StateGamePlayer.hpp"
#include "StateGameTurn.hpp"
#include "ComputerPlayer.hpp"
#include "HumanPlayer.hpp"

using game::ComputerPlayer;
using game::HumanPlayer;
using state::StateGamePlayer;
using state::StateGameTurn;
using std::cin;
using std::cout;
using std::endl;
using std::make_shared;
using std::make_unique;
using std::move;
using std::shared_ptr;
using std::string;
using std::unique_ptr;

StateGamePlayer::StateGamePlayer(const string &name) : State{name} {}

void StateGamePlayer::next()
{
    string playerName;
    cout << "Gebe bitte einen Spielernamen ein:" << endl;
    cin >> playerName;
    cout << endl;

    shared_ptr<HumanPlayer> guest = make_shared<HumanPlayer>(playerName);
    shared_ptr<ComputerPlayer> pc = make_shared<ComputerPlayer>("Computer Gegner");
    cout << pc->getName() << " vs. " << guest->getName() << endl;

    context_->game.addPlayer(guest);
    context_->game.addPlayer(pc);

    string name = context_->game.nextTurnName();

    shared_ptr<StateGameTurn> turn_state = std::make_shared<StateGameTurn>(name);
    context_->TransitionTo(turn_state);
}
