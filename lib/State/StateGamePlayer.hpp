#pragma once

#include "State.hpp"
#include "Context.hpp"

namespace state
{
    class StateGamePlayer;
};

class state::StateGamePlayer : public state::State
{
public:
    explicit StateGamePlayer(const string &name);
    void next() override;
};