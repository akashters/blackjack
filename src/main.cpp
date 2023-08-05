#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include <random>
#include "rank.hpp"
#include "suit.hpp"
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"

int main()
{
    Deck d;
    d.shuffle();

    Player player;
    Player dealer;
    player.deal_card(d.draw_top());
    player.deal_card(d.draw_top());

    dealer.deal_card(d.draw_top());
    dealer.deal_card(d.draw_top());

    std::cout << "Player's Hand (Total " << player.evaluate() << "):\n";
    player.print_hand();
    std::cout << "\nDealer's Hand (Total " << dealer.evaluate() << "):\n";
    dealer.print_hand();
    return 0;
}
