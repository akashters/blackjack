#pragma once

#include "deck.hpp"
#include "player.hpp"
#include "outcome.hpp"
#include "action.hpp"

class Game
{
private:
    Player player;
    Player dealer;

    Deck deck;
    int wager;

public:
    Game();

    void bet(int _wager);

    void print_dealers_hand() const noexcept;
    void print_players_hand() const noexcept;
    Outcome player_turn(Action action) noexcept;
    Outcome dealer_turn() noexcept;
};