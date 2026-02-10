#include <SFML/Graphics.hpp>
#include "Core/Board.hpp"
#include "Graphics/Renderer.hpp"
#include <iostream>

using namespace std;

int main(void){
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "TicTacToe Pro - Pasul 1");
    Board board;

    Renderer renderer(window); // initializam desenatorul

    std::cout << "Sistemul de logica a fost initializat cu succes!" << std::endl;
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear(sf::Color(30,30,30));

        renderer.drawGrid();

        window.display();
    }

    return 0;
}