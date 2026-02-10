#include "Graphics/Renderer.hpp"
#include <iostream>

using namespace std;

Renderer::Renderer(sf::RenderWindow& window) : m_window(window){}

void Renderer::drawGrid(){
    sf::RectangleShape line(sf::Vector2f(WINDOW_SIZE,5.f));
    line.setFillColor(sf::Color::White);

    //liniile orizontale
    line.setPosition(0,CELL_SIZE);
    m_window.draw(line);
    line.setPosition(0,CELL_SIZE * 2);
    m_window.draw(line);

    // Liniile verticale (le rotim la 90 de grade)
    line.setSize(sf::Vector2f(5.f,WINDOW_SIZE));
    line.setPosition(CELL_SIZE,0);
    m_window.draw(line);
    line.setPosition(CELL_SIZE * 2,0);
    m_window.draw(line);
}

void Renderer::drawMarkers(const Board& board){
    // Aici vom desena X și O. Pentru început, lăsăm metoda goală
    // sau desenăm un mic cerc de test dacă vrei.
}