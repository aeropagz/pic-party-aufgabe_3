#include <boost/test/unit_test.hpp>
#include <memory>
#include <vector>

#include "Deck.hpp"

using game::Deck;
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::vector;

BOOST_AUTO_TEST_SUITE(state_test)

BOOST_AUTO_TEST_CASE(read_file_test)
{
    Deck deck;
    BOOST_TEST(deck.getDeckSize() == 0);

    deck.initDeck();
    BOOST_TEST(deck.getDeckSize() == 16);

    deck.draw();
    BOOST_TEST(deck.getDeckSize() == 15);
}

BOOST_AUTO_TEST_SUITE_END()
