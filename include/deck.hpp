#pragma once
#include <vector>
#include <memory>
#include "rank.hpp"
#include "suit.hpp"
#include "card.hpp"

class Deck
{
private:
    std::vector<std::unique_ptr<Card>> cards;

public:
    Deck();

    std::size_t size() const noexcept;

    std::unique_ptr<Card> draw_top() noexcept;

    void shuffle() noexcept;
};