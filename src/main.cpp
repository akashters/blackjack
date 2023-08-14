#include <iostream>

#include "game.hpp"
#include "outcome.hpp"
#include "action.hpp"

int main()
{
    Game game;

    int wager;
    std::cout << "Enter the wager:\n";
    std::cin >> wager;
    game.bet(wager);

    Outcome outcome = Outcome::game_ongoing;

    while (outcome == Outcome::game_ongoing)
    {
        game.print_dealers_hand();
        game.print_players_hand();

        char player_choice;
        std::cout << "(H)it / (S)tand / (D)ouble down:\n";
        std::cin >> player_choice;

        Action player_action;
        switch (player_choice)
        {
        case 'H':
            player_action = Action::hit;
            break;
        case 'S':
            player_action = Action::stand;
            break;
        case 'D':
            player_action = Action::double_down;
            break;
        default:
            continue;
        }

        outcome = game.player_turn(player_action);
        if (outcome == Outcome::player_yield)
        {
            outcome = game.dealer_turn();
        }
    }

    game.print_dealers_hand();
    game.print_players_hand();

    switch (outcome)
    {
    case Outcome::player_bust:
        std::cout << "Hey Buddy!! Your ass is busted!";
        break;
    case Outcome::dealer_bust:
        std::cout << "Shit, I'm busted! I'm gonna call the security buddy to escort your ass out!";
        break;
    case Outcome::player_win:
        std::cout << "You win. But remember buddy money DOESN'T matter!";
        break;
    case Outcome::dealer_win:
        std::cout << "I win. Fair game. But, life is unfair buddy.";
        break;
    case Outcome::tie_dealer_win:
        std::cout << "Buddy, it's a tie. But I take everything because I'm a Gangsta!";
        break;
    case Outcome::player_black_jack:
        std::cout << "Buddy, you got a black jack. Did you bring your own cards?";
        break;
    case Outcome::dealer_black_jack:
        std::cout << "I got black jack. Do you know I invented this game back in my days using Windows 10?";
        break;
    default:
        std::cout << "What did just happen? Did you eat some cards?";
        break;
    }

    std::cout << std::endl;
    return 0;
}
