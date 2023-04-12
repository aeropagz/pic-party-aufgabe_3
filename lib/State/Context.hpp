#pragma once

#include <memory>
#include <typeinfo>
#include <iostream>
#include "Game.hpp"

using game::Game;

namespace state
{
    class Context;
    class State;
};

using std::shared_ptr;

class state::Context
{
    shared_ptr<State> state_;

public:
    Game game;
    explicit Context(shared_ptr<State> state);
    void TransitionTo(shared_ptr<State> state);
    void trigger();
};
