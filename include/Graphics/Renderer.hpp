#pragma once
#include <SFML/Graphics.hpp>
#include <Core/Board.hpp>

//We need to create a new class that gets our table and renders it on the screen.

class Renderer{
private:
    sf::RenderWindow& m_window;//referinta catre adresa din main

public:
    Renderer(sf::RenderWindow& window);

    //desenam liniile tabelei
    void drawGrid();

    //desenam simbolul X si O
    void drawMarkers(const Board& board);
};