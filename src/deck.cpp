#include <random>
#include <memory>
#include <vector>
#include <algorithm>

#include "rank.hpp"
#include "suit.hpp"
#include "card.hpp"
#include "deck.hpp"

Deck::Deck()
{
    for (Suit s : {Suit::hearts, Suit::diamonds, Suit::spades, Suit::clubs})
    {
        for (int i = 1; i <= 13; i++)
        {
            Rank rank = static_cast<Rank>(i);
            cards.push_back(std::make_unique<Card>(rank, s));
        }
    }
}

std::size_t Deck::size() const noexcept
{
    return cards.size();
}

std::unique_ptr<Card> Deck::draw_top() noexcept
{
    if (cards.empty())
    {
        return nullptr;
    }
    std::unique_ptr<Card> card = std::move(cards.back());
    cards.pop_back();
    return card;
}

void Deck::shuffle() noexcept
{
    std::shuffle(cards.begin(), cards.end(), std::random_device());
}