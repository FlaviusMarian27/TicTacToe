#include "Graphics/Renderer.hpp"
#include "Core/Constants.hpp"
#include <iostream>

using namespace std;

Renderer::Renderer(sf::RenderWindow& window) : m_window(window){}

void Renderer::drawGrid(){
    m_window.clear(BG_COLOR);

    sf::RectangleShape line(sf::Vector2f(WINDOW_SIZE,8.f)); //grosime linii
    line.setFillColor(GRID_COLOR);

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
                sf::RectangleShape line1(sf::Vector2f(CELL_SIZE * 0.7f, 10.f));
                line1.setFillColor(X_COLOR); // culoare galbena
                line1.setOrigin(line1.getSize().x / 2, line1.getSize().y / 2);
                line1.setPosition(xPos, yPos);
                line1.setRotation(45);
                m_window.draw(line1);

                sf::RectangleShape line2 = line1;
                line2.setRotation(-45);
                m_window.draw(line2);
            }else if (state == Cell::O){
                sf::CircleShape circle(CELL_SIZE * 0.35f);
                circle.setOrigin(circle.getRadius(), circle.getRadius());
                circle.setPosition(xPos, yPos);
                circle.setFillColor(sf::Color::Transparent);
                circle.setOutlineThickness(10.f); // O mai gros
                circle.setOutlineColor(O_COLOR); // culoare portocalie
                m_window.draw(circle);
            }
        }
    }
}