#pragma once
#include "Players/Player.hpp"

class HardBot : public Player{
public:
    HardBot(Cell symbol, std::string name);

    Move getMove(const sf::RenderWindow& window) override;

    Move getBestMove(Board& board);

    Cell getSymbol() const override;
    std::string getName() const override;

private:
    int minimax(Board& board, int depth, bool isMaximize);

    Cell m_symbol; // simbol bot
    Cell m_opponentSymbol; // simbolul tau
    std::string m_name;
};