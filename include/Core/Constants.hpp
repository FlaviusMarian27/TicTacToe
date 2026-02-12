#pragma once
#include <SFML/Graphics/Color.hpp>

const sf::Color BG_COLOR = sf::Color(25,25,25);
const sf::Color GRID_COLOR = sf::Color(0,255,255);
const sf::Color X_COLOR = sf::Color(255,220,0);
const sf::Color O_COLOR = sf::Color(255,100,50);

//starea unei celule
enum class Cell{
    Empty,
    X,
    O
};

//dimensiunea pentru interfata
const int WINDOW_SIZE = 600;
const int CELL_SIZE = WINDOW_SIZE / 3;