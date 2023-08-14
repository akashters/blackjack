#pragma once

enum class Outcome
{
    player_bust,
    dealer_bust,
    player_win,
    dealer_win,
    tie_dealer_win,
    player_black_jack,
    dealer_black_jack,
    player_yield,
    game_ongoing,
};