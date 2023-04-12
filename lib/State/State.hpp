#pragma once

#include <iostream>
#include <memory>

using std::shared_ptr;
using std::string;

namespace state
{
    class State;
    class Context;
};

class state::State
{

protected:
    Context *context_;
    string name_;

public:
    State();
    explicit State(const string &name);
    virtual ~State() = default;
    void set_context(Context *context);
    virtual void next() = 0;
    virtual string getName();
};