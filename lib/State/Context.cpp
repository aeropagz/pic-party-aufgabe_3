#include "Context.hpp"
#include "State.hpp"
#include <memory>

using state::Context;
using state::State;
using std::cout;
using std::endl;

Context::Context(shared_ptr<State> state)
{
    this->TransitionTo(state);
}

void Context::TransitionTo(shared_ptr<State> state)
{
    cout << endl
         << endl
         << endl
         << "Next Phase: " << state->getName() << endl;
    state_ = state;
    state_->set_context(this);
}

void Context::trigger()
{
    state_->next();
}