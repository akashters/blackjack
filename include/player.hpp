#pragma once

#include <vector>
#include <memory>

#include "card.hpp"

class Player
{
private:
    std::vector<std::unique_ptr<Card>> hand;

public:
    void deal_card(std::unique_ptr<Card> card);

    int evaluate() const noexcept;

    void print_hand() const noexcept;

    bool is_black_jack() const noexcept;
};