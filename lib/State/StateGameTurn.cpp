#include <memory>
#include <iostream>
#include "StateGameTurn.hpp"
#include "StateGameEnd.hpp"

using state::StateGameEnd;
using state::StateGameTurn;
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;

StateGameTurn::StateGameTurn(const string &name) : State{name} {}

void StateGameTurn::next()
{
    bool isOver = context_->game.makeTurn();
    if (!isOver)
    {
        string name = context_->game.nextTurnName();
        shared_ptr<StateGameTurn> next_state = make_shared<StateGameTurn>(name);
        context_->TransitionTo(next_state);
    }
    else
    {
        cout << "Spiel zu Ende" << endl;
        shared_ptr<StateGameEnd> end_state = make_shared<StateGameEnd>("GameOver");
        context_->TransitionTo(end_state);
    }
}