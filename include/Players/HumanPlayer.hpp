#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "Player.hpp"

class HumanPlayer : public Player{
private:
    Cell m_symbol;
    std::string m_name;

public:
    HumanPlayer(Cell symbol, std::string name);

    //metoda getMove pentru click-ul mouse ului
    Move getMove(const sf::RenderWindow& window) override;

    Cell getSymbol() const override;
    std::string getName() const override;
};