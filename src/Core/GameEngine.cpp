#include "Core/GameEngine.hpp"
#include "Players/HumanPlayer.hpp"
#include "Players/HardBot.hpp"

GameEngine::GameEngine()
    : m_window(sf::VideoMode(WINDOW_SIZE,WINDOW_SIZE),"TicTacToe vs HardBot"),
    m_board(),
    m_renderer(m_window),
    m_isPlayer1Turn(true),
    m_isGameOver(false){
    m_player1 = std::make_unique<HumanPlayer>(Cell::X, "You");
    m_player2 = std::make_unique<HardBot>(Cell::O, "Hard Bot");
}

void GameEngine::run(){
    while(m_window.isOpen()){
        processEvents();
        update();
        render();
    }
}

void GameEngine::processEvents(){
    sf::Event event;
    while(m_window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            m_window.close();
        }

        if (!m_isGameOver && m_isPlayer1Turn == true && event.type == sf::Event::MouseButtonPressed){
            Move m = m_player1->getMove(m_window);
            if (m_board.makeMove(m.row,m.col,m_player1->getSymbol())){
                m_isPlayer1Turn = false;
            }
        }
    }
}

void GameEngine::update(){
    if (m_isGameOver == true){
        return;
    }

    if (m_board.checkWinner() != Cell::Empty || m_board.isFull()){
        m_isGameOver = true;
        return;
    }

    if (m_isPlayer1Turn == false){
        auto bot = dynamic_cast<HardBot*>(m_player2.get());
        if (bot){
            Move m = bot->getBestMove(m_board);
            m_board.makeMove(m.row,m.col,bot->getSymbol());
            m_isPlayer1Turn = true;
        }
    }

    if (m_board.checkWinner() != Cell::Empty || m_board.isFull()){
        m_isGameOver = true;
    }
}

void GameEngine::render() {
    m_window.clear(sf::Color(30, 30, 30));
    m_renderer.drawGrid();
    m_renderer.drawMarkers(m_board);
    m_window.display();
}