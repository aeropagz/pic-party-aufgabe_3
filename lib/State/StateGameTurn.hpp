#pragma once

#include "State.hpp"
#include "Context.hpp"

namespace state
{
    class StateGameTurn;
};

class state::StateGameTurn : public state::State
{
public:
    explicit StateGameTurn(const string &name);
    void next() override;
};