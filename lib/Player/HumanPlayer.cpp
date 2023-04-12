#include "HumanPlayer.hpp"
#include "ConsoleUtil.hpp"
#include <iostream>
#include <sstream>
#include <memory>
#include <limits>
#include "Game.hpp"

using game::HumanPlayer;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::move;
using std::stringstream;

HumanPlayer::HumanPlayer(const string &name) : Player{name} {}

void HumanPlayer::action(Game &game)
{
    game.logger << "Deine Hand: \n";
    for (int i{0}; i < hand_.size(); i++)
    {
        hand_.at(i)->display();
    }

    string choice;
    game.logger << "Wähle eine Karte aus:\n";
    while (true)
    {

        game.logger << "1 oder 2: ";
        cin >> choice;
        if (choice == "1")
        {
            if (checkForCountess() && (hand_[0]->getName() != "Gräfin"))
            {
                cout << "Es muss die Gräfin gespielt werden!" << endl;
            }
            cout << CLEAR_SCREEN;
            game.executeCard(playCard(1));
            return;
        }
        else if (choice == "2")
        {
            if (checkForCountess() && (hand_[1]->getName() != "Gräfin"))
            {
                cout << "Es muss die Gräfin gespielt werden!" << endl;
            }
            cout << CLEAR_SCREEN;
            game.executeCard(playCard(2));
            return;
        }
    }
}

string HumanPlayer::chooseCardName(const vector<string> &names)
{
    for (int i{0}; i < names.size(); i++)
    {
        stringstream sstm;
        sstm << i + 1 << ". " << names.at(i) << endl;
        cout << sstm.str() << endl;
    }

    cout << "Wähle einen Kartentypen" << endl;
    while (true)
    {
        cout << "1 bis " << names.size() << ":" << endl;
        int choice;
        cin >> choice;
        if ((choice >= 1) && (choice <= names.size()))
        {
            return names.at(choice - 1);
        }
        std::cin.clear(); // clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
