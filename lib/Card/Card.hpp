#pragma once

#include <string>
#include <memory>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

static const string colorOff = "\033[0m";

namespace game
{
    class AbstractCard;
}

class game::AbstractCard
{
protected:
    int rank_;
    string name_;
    string effect_;

public:
    AbstractCard() = delete;
    AbstractCard(const string &name, const int rank, const string &effect);
    virtual ~AbstractCard() = default;
    virtual int getRank();
    virtual string getName();
    virtual string getEffect();
    virtual void display();
};
