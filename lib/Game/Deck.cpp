#include <iostream>
#include <memory>
#include "RandomVector.hpp"
#include "Deck.hpp"
#include "Card.hpp"
#include "GuardCard.hpp"
#include "PriestCard.hpp"
#include "BaronCard.hpp"
#include "MaidCard.hpp"
#include "PrinceCard.hpp"
#include "KingCard.hpp"
#include "CountessCard.hpp"
#include "PrincessCard.hpp"

using game::Deck;
using std::cout;
using std::endl;
using std::make_unique;
using std::move;
using std::unique_ptr;

void Deck::initDeck()
{
    for (auto const &config : deckConfig)
    {
        auto name = config.first;
        auto amount = config.second;

        if (name == "Wächter")
        {
            for (int i{0}; i < amount; i++)
            {
                unique_ptr<GuardCard> guard = make_unique<GuardCard>();
                stack.push_back(move(guard));
            }
        }
        else if (name == "Priester")
        {
            for (int i{0}; i < amount; i++)
            {
                unique_ptr<PriestCard> priest = make_unique<PriestCard>();
                stack.push_back(move(priest));
            }
        }
        else if (name == "Baron")
        {
            for (int i{0}; i < amount; i++)
            {
                unique_ptr<BaronCard> baron = make_unique<BaronCard>();
                stack.push_back(move(baron));
            }
        }
        else if (name == "Zofe")
        {
            for (int i{0}; i < amount; i++)
            {
                unique_ptr<MaidCard> maid = make_unique<MaidCard>();
                stack.push_back(move(maid));
            }
        }
        else if (name == "Prinz")
        {
            for (int i{0}; i < amount; i++)
            {
                unique_ptr<PrinceCard> prince = make_unique<PrinceCard>();
                stack.push_back(move(prince));
            }
        }
        else if (name == "König")
        {
            for (int i{0}; i < amount; i++)
            {
                unique_ptr<KingCard> king = make_unique<KingCard>();
                stack.push_back(move(king));
            }
        }
        else if (name == "Gräfin")
        {
            for (int i{0}; i < amount; i++)
            {
                unique_ptr<CountessCard> countess = make_unique<CountessCard>();
                stack.push_back(move(countess));
            }
        }
        else if (name == "Prinzessin")
        {
            for (int i{0}; i < amount; i++)
            {
                unique_ptr<PrincessCard> princess = make_unique<PrincessCard>();
                stack.push_back(move(princess));
            }
        }
    }
}

unique_ptr<game::AbstractCard> Deck::draw()
{
    unique_ptr<AbstractCard> card = popRandom<AbstractCard>(stack);
    return card;
}

int Deck::getDeckSize()
{
    return stack.size();
}
