#pragma once
#include "Players/Player.hpp"
#include <random>

class MediumBot : public Player{
public:
    MediumBot(Cell symbol, std::string name);
    Move getMove(const sf::RenderWindow& window);

    Move getSmartMove(Board& board);

    Cell getSymbol() const override;
    std::string getName() const override;

private:
    Cell m_symbol;
    std::string m_name;
    Cell m_opponentSymbol;
};