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
    for (int row = 0; row < 3; row = row + 1){
        for (int col = 0; col < 3; col = col + 1){
            Cell state = board.getCell(row, col);
            float xPos = col * 200 + 100;
            float yPos = row * 200 + 100;

            if (state == Cell::X){
                sf::RectangleShape line1(sf::Vector2f(150.f,5.f));
                line1.setOrigin(sf::Vector2f(75.f,2.5f));
                line1.setPosition(xPos,yPos);
                line1.setRotation(45);
                m_window.draw(line1);

                sf::RectangleShape line2 = line1;
                line2.setRotation(-45);
                m_window.draw(line2);
            }else if (state == Cell::O){
                sf::CircleShape circle(70.f);
                circle.setOrigin(70.f,70.f);
                circle.setPosition(xPos,yPos);
                circle.setFillColor(sf::Color::Transparent);
                circle.setOutlineThickness(5.f);
                circle.setOutlineColor(sf::Color::Red);
                m_window.draw(circle);
            }
        }
    }
}