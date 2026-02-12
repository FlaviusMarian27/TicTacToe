#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Core/Board.hpp"
#include "Graphics/Renderer.hpp"
#include "Players/Player.hpp"
#include "Graphics/MenuButton.hpp"

enum class GameMode{
    Menu,
    Easy,
    Medium,
    Hard,
    WithFriend
};

class GameEngine{
private:
    void processEvents();
    void update();
    void render();
    void initMenu();
    void initGame();

    sf::RenderWindow m_window;
    Board m_board;
    Renderer m_renderer;
    sf::Font m_font;
    sf::Text m_welcomeText;

    // Managementul meniului
    GameMode m_currentMode;
    std::vector<MenuButton> m_menuButtons;
    float m_animationOffset; // Pentru glisarea butoanelor

    // Jucătorii (se vor inițializa după alegerea din meniu)
    std::unique_ptr<Player> m_player1;
    std::unique_ptr<Player> m_player2;
    bool m_isPlayer1Turn;
    bool m_isGameOver;

public:
    GameEngine();
    void run();
};