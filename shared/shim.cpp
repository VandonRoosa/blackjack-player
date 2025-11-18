#include "shim.hpp"
#include "black_jack_solver.hpp"
#include "deffinitions.hpp"

// Fuffill the interface defined in shim.hpp
extern "C"
{
bjalgo_ptr_t algorithm_create(
    uint64_t number_of_decks,
    float reshuffle_percentage,
    uint64_t number_of_rounds,
    chip_t chips,
    chip_t table_min,
    chip_t table_max)
{
    return new BlackJackSolver(number_of_decks, reshuffle_percentage, number_of_rounds, chips, table_min, table_max);
}

void algorithm_destroy(bjalgo_ptr_t ptr_)
{
    BlackJackSolver* ptr = reinterpret_cast<BlackJackSolver*>(ptr_);
    delete ptr;
}

BlackJackAction algorithm_compute(
    bjalgo_ptr_t ptr_,
    Card dealer_up_card,
    const Card* cards,
    size_t num_cards,
    BlackJackHandStatus status)
{
    BlackJackSolver* ptr = reinterpret_cast<BlackJackSolver*>(ptr_);
    return ptr->handle_hand(dealer_up_card, std::span<const Card>(cards, num_cards), status);
}

chip_t algorithm_get_bet(bjalgo_ptr_t ptr_)
{
    BlackJackSolver* ptr = reinterpret_cast<BlackJackSolver*>(ptr_);
    return ptr->get_bet();
}

void algorithm_get_payout(bjalgo_ptr_t ptr_, chip_t chips, const Card* cards, size_t num_cards)
{
    BlackJackSolver* ptr = reinterpret_cast<BlackJackSolver*>(ptr_);
    ptr->take_payout(chips, std::span(cards, num_cards));
}

void algorithm_on_reshuffle(bjalgo_ptr_t ptr_)
{
    BlackJackSolver* ptr = reinterpret_cast<BlackJackSolver*>(ptr_);
    ptr->on_reshuffle();
}

}  // end EXTERN C
