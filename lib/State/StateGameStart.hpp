#pragma once

#include "State.hpp"
#include "Context.hpp"

namespace state
{
    class StateGameStart;
};

class state::StateGameStart : public state::State
{
public:
    explicit StateGameStart(const string &name);
    void next() override;
};