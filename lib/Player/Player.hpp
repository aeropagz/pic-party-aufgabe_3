#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Card.hpp"

using std::string;
using std::unique_ptr;
using std::vector;

namespace game
{
    class Player;
    class Game;
    class AbstractCard;
};

class game::Player
{
protected:
    string name_;
    vector<unique_ptr<AbstractCard>> hand_;
    bool safeNextRound_{false};

public:
    explicit Player(const string &name);
    Player() = delete;
    virtual ~Player() = default;
    virtual string getName();
    virtual bool isProtected();
    virtual void protect();
    virtual void unprotect();
    virtual void addCard(unique_ptr<AbstractCard> card);
    virtual unique_ptr<AbstractCard> playCard(int card_number);
    virtual void action(Game &game) = 0;
    virtual string chooseCardName(const vector<string> &names) = 0;
    virtual string showCard();
    virtual bool guessHand(const string &cardName);
    virtual bool checkForCountess();
};