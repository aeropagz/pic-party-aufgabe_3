#pragma once
#include <vector>
#include <memory>
#include <string>

#include "Logger.hpp"
#include "Deck.hpp"

using logger::Logger;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::vector;

namespace game
{
    class Game;
    class ComputerPlayer;
    class HumanPlayer;
    class Deck;
};

class game::Game
{

    Deck deck_;
    int lastTurnIndex_{1};
    bool computer_won_ = false;
    bool hooman_won_ = false;

public:
    shared_ptr<ComputerPlayer> computer_player;
    shared_ptr<HumanPlayer> hooman_player;
    string currentPlayer;

    const vector<string> cardNames{
        "Wächter",
        "Priester",
        "Baron",
        "Zofe",
        "Prinz",
        "König",
        "Gräfin",
        "Prinzessin",
    };

    Logger logger;

    void Start();
    void addPlayer(shared_ptr<ComputerPlayer> &player);
    void addPlayer(shared_ptr<HumanPlayer> &player);
    bool makeTurn();
    int getLastTurnIndex();
    string nextTurnName();
    void executeCard(unique_ptr<AbstractCard> card);

    bool hasComputerWon();
    bool checkIfProtected();
    void executeGuard();
    void executePriest();
    void executeMaid();
    void executePrincess();
    void executeBaron();
    void executeKing();
    int getIndexOfName(const string &name);
};