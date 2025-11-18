#pragma once

#include <type_traits>

#include "deffinitions.hpp"

using bjalgo_ptr_t = void*;

using create_fn_t     = bjalgo_ptr_t (*)(uint64_t, float, uint64_t, chip_t, chip_t, chip_t);
using destroy_fn_t    = void (*)(bjalgo_ptr_t);
using solve_fn_t      = BlackJackAction (*)(bjalgo_ptr_t, Card, const Card*, size_t, BlackJackHandStatus);
using get_bet_fn_t    = chip_t (*)(bjalgo_ptr_t);
using get_payout_fn_t = void (*)(bjalgo_ptr_t, chip_t, const Card*, size_t);
using reshuffle_fn_t  = void (*)(bjalgo_ptr_t);

extern "C"
{
bjalgo_ptr_t algorithm_create(
    uint64_t number_of_decks,
    float reshuffle_percentage,
    uint64_t number_of_rounds,
    chip_t chips,
    chip_t table_min,
    chip_t table_max);

void algorithm_destroy(bjalgo_ptr_t ptr_);

BlackJackAction algorithm_compute(
    bjalgo_ptr_t ptr_,
    Card dealer_up_card,
    const Card* cards,
    size_t num_cards,
    BlackJackHandStatus status);

chip_t algorithm_get_bet(bjalgo_ptr_t ptr_);

void algorithm_get_payout(bjalgo_ptr_t ptr_, chip_t chips, const Card* cards, size_t num_cards);

void algorithm_on_reshuffle(bjalgo_ptr_t ptr_);
};

static_assert(std::is_same_v<decltype(&algorithm_create), create_fn_t>);
static_assert(std::is_same_v<decltype(&algorithm_destroy), destroy_fn_t>);
static_assert(std::is_same_v<decltype(&algorithm_compute), solve_fn_t>);
static_assert(std::is_same_v<decltype(&algorithm_get_bet), get_bet_fn_t>);
static_assert(std::is_same_v<decltype(&algorithm_get_payout), get_payout_fn_t>);
static_assert(std::is_same_v<decltype(&algorithm_on_reshuffle), reshuffle_fn_t>);
