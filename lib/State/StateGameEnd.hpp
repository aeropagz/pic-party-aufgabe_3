#pragma once
#include <iostream>

#include "State.hpp"
#include "Context.hpp"

namespace state
{
    class StateGameEnd;
};

class state::StateGameEnd : public state::State
{
public:
    explicit StateGameEnd(const string &name);
    void next() override;
};