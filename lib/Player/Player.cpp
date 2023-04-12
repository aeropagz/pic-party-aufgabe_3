#include "Player.hpp"

using game::Player;
using std::move;

Player::Player(const string &name) : name_{name} {};
string Player::getName()
{
    return name_;
}

bool Player::isProtected()
{
    return safeNextRound_;
}

void Player::addCard(unique_ptr<AbstractCard> card)
{
    hand_.push_back(move(card));
}
unique_ptr<game::AbstractCard> Player::playCard(int card_number)
{
    int index = card_number - 1;
    unique_ptr<AbstractCard> card = move(hand_.at(index));
    hand_.erase(hand_.begin() + index);
    return card;
}

string Player::showCard()
{
    return hand_.at(0)->getName();
}

bool Player::guessHand(const string &cardName)
{
    string onwCard{hand_.at(0)->getName()};
    return onwCard == cardName;
}

void Player::protect()
{
    safeNextRound_ = true;
}

void Player::unprotect()
{
    safeNextRound_ = false;
}

bool Player::checkForCountess()
{
    for (int i{0}; i < hand_.size(); i++)
    {
        if (hand_[i]->getName() == "Gräfin")
        {
            for (int j{0}; j < hand_.size(); j++)
            {
                if (hand_[j]->getName() == "Prinz" || hand_[j]->getName() == "König")
                    return true;
            }
        }
    }
    return false;
}