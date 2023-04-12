#include "State.hpp"
#include "Context.hpp"

using state::Context;
using state::State;

State::State() {}

State::State(const string &name) : name_{name} {};

void State::set_context(Context *context)
{
    context_ = context;
}

string State::getName()
{
    return name_;
}