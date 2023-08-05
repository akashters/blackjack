#include <iostream>
#include "player.hpp"
#include "card.hpp"
#include "rank.hpp"
#include "suit.hpp"

void Player::deal_card(std::unique_ptr<Card> card)
{
    hand.push_back(std::move(card));
}

int Player::evaluate() const noexcept
{
    int sum = 0;
    int aces = 0;
    for (const auto &card : hand)
    {
        if (card->rank == Rank::ace)
        {
            aces++;
        }
        else
        {
            int val = static_cast<int>(card->rank);
            sum += (val > 10) ? 10 : val;
        }
    }

    while (aces--)
    {
        sum += ((sum + 11) > 21) ? 1 : 11;
    }

    return sum;
}

void Player::print_hand() const noexcept
{
    for (const auto &card : hand)
    {
        switch (card->rank)
        {
        case Rank::ace:
            std::cout << "Ace";
            break;
        case Rank::jack:
            std::cout << "Jack";
            break;
        case Rank::queen:
            std::cout << "Queen";
            break;
        case Rank::king:
            std::cout << "King";
            break;

        default:
            std::cout << static_cast<int>(card->rank);
            break;
        }

        std::cout << " of ";

        switch (card->suit)
        {
        case Suit::hearts:
            std::cout << "Hearts";
            break;
        case Suit::diamonds:
            std::cout << "Diamonds";
            break;
        case Suit::clubs:
            std::cout << "Clubs";
            break;
        case Suit::spades:
            std::cout << "Spades";
            break;
        default:
            break;
        }

        std::cout << "\n";
    }
}