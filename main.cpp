#include <iostream>
#include <memory>
#include "Context.hpp"
#include "ConsoleUtil.hpp"
#include "StateGameStart.hpp"

using state::Context;
using state::StateGameStart;
using std::cin;
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::string;

int main(int ac, char *av[])
{
    cout << CLEAR_SCREEN << endl;
    string input;
    Context context = state::Context(make_shared<StateGameStart>("GameStart"));

    context.trigger();
    do
    {
        cout << "Weiter Mit 'c'" << endl;
        cout << "Abbruch mit 'exit'" << endl;
        cin >> input;
        if (input == "c")
        {
            cout << CLEAR_SCREEN << endl;
            context.trigger();
        }
    } while (input != "exit");

    return 0;
}