#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Core/Board.hpp"
#include "Graphics/Renderer.hpp"
#include "Players/Player.hpp"

class GameEngine{
private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow m_window;
    Board m_board;
    Renderer m_renderer;

    // Folosim smart pointers pentru polimorfism
    std::unique_ptr<Player> m_player1;
    std::unique_ptr<Player> m_player2;

    bool m_isPlayer1Turn;
    bool m_isGameOver;

public:
    GameEngine();
    void run();
};