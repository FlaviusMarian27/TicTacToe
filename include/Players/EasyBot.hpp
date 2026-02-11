#pragma once
#include "Players/Player.hpp"
#include <random>
#include <SFML/Graphics/RenderWindow.hpp>

class EasyBot : public Player{
private:
    Cell m_symbol;
    std::string m_name;

public:
    EasyBot(Cell symbol, std::string name);

    Move getMove(const sf::RenderWindow& window) override;

    //metoda pentru care primeste botul tabla
    Move getMoveFromBoard(const Board& board);

    Cell getSymbol() const override;
    std::string getName() const override;
};
