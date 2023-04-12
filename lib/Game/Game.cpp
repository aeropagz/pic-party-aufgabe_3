#include <iostream>
#include <algorithm>
#include <sstream>
#include "Game.hpp"
#include <string>
#include "HumanPlayer.hpp"
#include "ComputerPlayer.hpp"
#include "ConsoleUtil.hpp"

using game::Game;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::move;

void Game::Start()
{
    logger.init("log.txt");
    deck_.initDeck();
    logger << "Kartendeck erstellen...\n";
}

void Game::addPlayer(shared_ptr<HumanPlayer> &player)
{
    unique_ptr<AbstractCard> card = move(deck_.draw());
    player->addCard(move(card));
    hooman_player = player;
}

void Game::addPlayer(shared_ptr<ComputerPlayer> &player)
{

    unique_ptr<AbstractCard> card = move(deck_.draw());
    player->addCard(move(card));
    computer_player = player;
}

bool Game::makeTurn()
{

    if (deck_.getDeckSize() <= 0)
    {
        logger << "Deck leer\n";
        return true;
    }

    lastTurnIndex_++;
    unique_ptr<AbstractCard> card = move(deck_.draw());
    shared_ptr<Player> player;

    if (lastTurnIndex_ % 2)
    {
        player = computer_player;
        currentPlayer = "computer";
    }
    else
    {
        player = hooman_player;
        currentPlayer = "hooman";
    }

    logger << player->getName() << "'s Zug.\n";
    logger << player->getName() << " zieht eine Karte.\n\n\n";

    player->addCard(move(card));

    player->action(*this);

    if (hooman_won_ || computer_won_)
    {
        return true;
    }

    logger << player->getName() << " beendet seinen Zug.\n";

    return false;
}

int Game::getLastTurnIndex()
{
    return lastTurnIndex_;
}
string Game::nextTurnName()
{
    int turn = getLastTurnIndex();
    std::stringstream sstm;
    sstm << "Game Turn: " << turn;
    string name = sstm.str();
    return name;
}

void Game::executeCard(unique_ptr<AbstractCard> card)
{
    logger << card->getName() << " gespielt\n";

    if (checkIfProtected())
        return;

    if (card->getName() == "Wächter")
    {
        executeGuard();
    }
    else if (card->getName() == "Priester")
    {
        // Zeige Gegner Karte, Tauno
        executePriest();
    }
    else if (card->getName() == "Baron")
    {
        executeBaron();
    }
    else if (card->getName() == "Zofe")
    {
        executeMaid();
    }
    else if (card->getName() == "Prinz")
    {
        // Gegner muss Karte ablegen
        if (currentPlayer == "hooman")
        {
            unique_ptr<AbstractCard> card = computer_player->playCard(1);
            logger << computer_player->getName() << " wirft " << card->getName() << " ab!\n\n";
            if (card->getName() == "Prinzessin")
            {
                logger << "Die Prinzessin wurde abgeworfen!\n";
                hooman_won_ = true;
                return;
            }

            computer_player->addCard(deck_.draw());
        }
        else
        {
            unique_ptr<AbstractCard> card = hooman_player->playCard(1);
            logger << hooman_player->getName() << "wirft " << card->getName() << "ab!\n";
            if (card->getName() == "Prinzessin")
            {
                logger << "Die Prinzessin wurde abgeworfen!\n";
                computer_won_ = true;
                return;
            }

            hooman_player->addCard(deck_.draw());
        }
    }
    else if (card->getName() == "König")
    {
        executeKing();
    }
    else if (card->getName() == "Gräfin")
    {
        // Passiert nichts;
        return;
    }
    else if (card->getName() == "Prinzessin")
    {
        executePrincess();
    }
}

void Game::executeGuard()
{
    if (currentPlayer == "hooman")
    {
        string cardName = hooman_player->chooseCardName(cardNames);
        logger << "Es wurde die Karte " << cardName << " gewählt.\n";
        bool match = computer_player->guessHand(cardName);
        if (match)
        {
            logger << "Treffer, richtig geraten!\n";
            hooman_won_ = true;
            return;
        }
        logger << "Leider falsch!\n";
    }
    else
    {
        string cardName = computer_player->chooseCardName(cardNames);
        logger << computer_player->getName() << " hat die Karte " << cardName << " gewählt.\n";
        bool match = hooman_player->guessHand(cardName);
        if (match)
        {
            logger << "Treffer, richtig geraten!\n";
            computer_won_ = true;
            return;
        }
        logger << "Leider falsch!\n";
    }
}

void Game::executePriest()
{
    if (currentPlayer == "hooman")
    {
        string computerPlayerCard = computer_player->showCard();
        logger << "Dein Gegner hat folgende Handkarte: "
               << computerPlayerCard
               << "\n";
    }
    else
    {
        logger << "Der Computergegner kann mit dem Priest (noch) nichts anfangen...\n";
    }
}

void Game::executeBaron()
{
    // Vergleich mit anderer Karte
    logger << "Vergleiche Karten:\n\n";
    string cardHooman = hooman_player->showCard();
    string cardComputer = computer_player->showCard();

    int indexHooman = getIndexOfName(cardHooman);
    int indexComput = getIndexOfName(cardComputer);
    logger << hooman_player->getName() << ": " << cardHooman << ", Rang: " << std::to_string(indexHooman + 1) << "\n";
    logger << computer_player->getName() << ": " << cardComputer << ", Rang: " << std::to_string(indexComput + 1) << "\n";

    if (indexHooman < indexComput)
    {
        logger << computer_player->getName() << " hat gewonnen!\n";
        computer_won_ = true;
    }
    else if (indexHooman > indexComput)
    {
        logger << hooman_player->getName() << " hat gewonnen!\n";
        hooman_won_ = true;
    }
    else
    {
        logger << "Unentschieden\n";
    }
}

void Game::executeMaid()
{
    if (currentPlayer == "hooman")
    {
        hooman_player->protect();
        logger << hooman_player->getName() << " ist für den nächsten Zug geschützt\n";
    }
    else
    {
        computer_player->protect();
        logger << computer_player->getName() << " ist für den nächsten Zug geschützt\n";
    }
}

void Game::executeKing()
{
    // Tausche Karten
    logger << "Die Hände werden getauscht!\n\n";
    unique_ptr<AbstractCard> hoomanCard = hooman_player->playCard(1);
    unique_ptr<AbstractCard> computerCard = computer_player->playCard(1);
    logger << hooman_player->getName() << " erhält " << computerCard->getName() << "\n";
    logger << computer_player->getName() << " erhält " << hoomanCard->getName() << "\n\n";

    hooman_player->addCard(move(computerCard));
    computer_player->addCard(move(hoomanCard));
}

void Game::executePrincess()
{
    if (currentPlayer == "hooman")
    {
        computer_won_ = true;
        logger << "Der Verlust der holden Maid bedeutet deine Niederlage...\n";
        return;
    }
    else
    {
        hooman_won_ = true;
        logger << "Die Maschine konnte das Herz der Hübschen nicht betören, du siegst!\n";
        return;
    }
}

int Game::getIndexOfName(const string &name)
{
    auto it = std::find(cardNames.begin(), cardNames.end(), name);
    return std::distance(cardNames.begin(), it);
}

bool Game::checkIfProtected()
{
    if (currentPlayer == "hooman" && computer_player->isProtected())
    {
        computer_player->unprotect();
        logger << computer_player->getName() << " ist geschütz, Effekt wird annuliert!\n";
        return true;
    }
    else if (currentPlayer == "computer" && hooman_player->isProtected())
    {
        hooman_player->unprotect();
        logger << hooman_player->getName() << " ist geschütz, Effekt wird annuliert!\n";
        return true;
    }
    return false;
}

bool Game::hasComputerWon()
{
    return computer_won_;
}