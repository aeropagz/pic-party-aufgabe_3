#pragma once
#include <vector>
#include <memory>
#include <map>
#include "Card.hpp"

using std::map;
using std::unique_ptr;
using std::vector;

namespace game
{
    class Deck;
};

class game::Deck
{
    vector<unique_ptr<game::AbstractCard>> stack;
    map<string, int> deckConfig{
        {"Wächter", 5},
        {"Priester", 2},
        {"Baron", 2},
        {"Zofe", 2},
        {"Prinz", 2},
        {"König", 1},
        {"Gräfin", 1},
        {"Prinzessin", 1},
    };

public:
    void initDeck();

    unique_ptr<AbstractCard> draw();
    int getDeckSize();
};