#include "Players/HumanPlayer.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>

using namespace std;

HumanPlayer::HumanPlayer(Cell symbol, std::string name)
    : m_symbol(symbol), m_name(name){}

Move HumanPlayer::getMove(const sf::RenderWindow& window){
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    int col = mousePos.x / 200;
    int row = mousePos.y / 200;

    return {row, col};
}

Cell HumanPlayer::getSymbol() const{
    return m_symbol;
}

std::string HumanPlayer::getName() const{
    return m_name;
}