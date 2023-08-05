#pragma once

#include "rank.hpp"
#include "suit.hpp"

class Card
{
public:
    // rank, suit
    Rank rank;
    Suit suit;

    // constructor
    Card(Rank _rank, Suit _suit) : rank(_rank), suit(_suit) {}
};