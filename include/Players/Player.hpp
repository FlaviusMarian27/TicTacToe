#pragma once
#include "Core/Board.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

//structura pentru stoca fiecare mutare
struct Move{
    int row;
    int col;
};

//clasa abstracta pura (interfata)
class Player{
public:
    virtual ~Player() = default;

    //metoda pe care o vor implementat Om, Bot, Network
    virtual Move getMove(const sf::RenderWindow& window) = 0;

    virtual Cell getSymbol() const = 0;
    virtual std::string getName() const = 0;
};