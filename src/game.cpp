#include <iostream>
#include <thread>
#include <chrono>

#include "deck.hpp"
#include "player.hpp"
#include "game.hpp"
#include "action.hpp"
#include "outcome.hpp"

Game::Game()
{
    deck.shuffle();

    player.deal_card(deck.draw_top());
    player.deal_card(deck.draw_top());

    dealer.deal_card(deck.draw_top());
}

void Game::bet(int _wager) { wager = _wager; }

void Game::print_dealers_hand() const noexcept
{
    std::cout << "\nDealer's Hand (Total " << dealer.evaluate() << "):\n";
    dealer.print_hand();
}

void Game::print_players_hand() const noexcept
{
    std::cout << "Player's Hand (Total " << player.evaluate() << "):\n";
    player.print_hand();
}

Outcome Game::player_turn(Action action) noexcept
{
    switch (action)
    {
    case Action::hit:
        player.deal_card(deck.draw_top());
        break;
    case Action::stand:
        return Outcome::player_yield;
        break;
    case Action::double_down:
        wager += wager;
        player.deal_card(deck.draw_top());
        break;
    default:
        break;
    }

    if (player.is_black_jack())
    {
        return Outcome::player_black_jack;
    }
    if (player.evaluate() > 21)
    {
        return Outcome::player_bust;
    }
    return Outcome::game_ongoing;
}

Outcome Game::dealer_turn() noexcept
{
    // reveal the second card
    dealer.deal_card(deck.draw_top());

    while (dealer.evaluate() < 17)
    {
        dealer.deal_card(deck.draw_top());
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Dealer Hit \n";
        print_dealers_hand();
    }

    int dealer_total, player_total;
    dealer_total = dealer.evaluate();
    player_total = dealer.evaluate();

    if (dealer_total <= 21)
    {
        if (dealer.is_black_jack())
        {
            return Outcome::dealer_black_jack;
        }

        if (dealer_total > player_total)
        {
            return Outcome::dealer_win;
        }

        if (dealer_total == player_total)
        {
            return Outcome::tie_dealer_win;
        }

        if (dealer_total < player_total)
        {
            return Outcome::player_win;
        }
    }
    return Outcome::dealer_bust;
}
