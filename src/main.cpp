#include <SFML/Graphics.hpp>
#include "Core/Board.hpp"
#include "Graphics/Renderer.hpp"
#include <iostream>

#include "Players/HumanPlayer.hpp"

using namespace std;

int main(void){
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "TicTacToe Pro - Pasul 1");
    Board board;

    Renderer renderer(window); // initializam desenatorul
    HumanPlayer player1(Cell::X,"Player 1");

    std::cout << "Sistemul de logica a fost initializat cu succes!" << std::endl;
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed){
                Move m = player1.getMove(window);
                board.makeMove(m.row,m.col,player1.getSymbol());
            }
        }

        window.clear(sf::Color(30,30,30));//1

        renderer.drawGrid();//2

        renderer.drawMarkers(board);//3

        window.display();//1
    }

    return 0;
}