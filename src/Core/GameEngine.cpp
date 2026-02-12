#include "Core/GameEngine.hpp"
#include "Players/HumanPlayer.hpp"
#include "Players/EasyBot.hpp"
#include "Players/MediumBot.hpp"
#include "Players/HardBot.hpp"

GameEngine::GameEngine()
    : m_window(sf::VideoMode(WINDOW_SIZE, 750), "TicTacToe - Menu",sf::Style::Titlebar | sf::Style::Close),
      m_renderer(m_window),
      m_currentMode(GameMode::Menu),
      m_animationOffset(800.f), // incepem cu butoanele "sub" ecran
      m_isPlayer1Turn(true),
      m_isGameOver(false)
{
    // 1. incarcare Font
    if (!m_font.loadFromFile("assets/fonts/font.ttf")) {
        // Daca crapa aici, verifica calea fisierului!
    }

    // 2. Configurare Titlu "Welcome!" (Galben Neon)
    m_welcomeText.setFont(m_font);
    m_welcomeText.setString("Welcome!");
    m_welcomeText.setCharacterSize(80);
    m_welcomeText.setFillColor(sf::Color::Yellow);
    m_welcomeText.setStyle(sf::Text::Bold);

    // Centrare titlu
    sf::FloatRect titleRect = m_welcomeText.getLocalBounds();
    m_welcomeText.setOrigin(titleRect.left + titleRect.width / 2.0f, 0);
    m_welcomeText.setPosition(WINDOW_SIZE / 2.0f, 50.f);

    // 3. Creare Butoane conform imaginii tale
    initMenu();
}

void GameEngine::initMenu() {
    float startX = WINDOW_SIZE / 2.0f;
    m_menuButtons.clear();

    // Culorile sunt mapate după imaginea image_4d7073.jpg
    m_menuButtons.emplace_back("EASY BOT",    sf::Vector2f(startX, 220), sf::Color::Yellow, m_font);
    m_menuButtons.emplace_back("MEDIUM BOT",  sf::Vector2f(startX, 320), sf::Color(255, 165, 0), m_font); // Portocaliu
    m_menuButtons.emplace_back("HARD BOT",    sf::Vector2f(startX, 420), sf::Color::Yellow, m_font);
    m_menuButtons.emplace_back("WITH FRIEND", sf::Vector2f(startX, 520), sf::Color(255, 127, 80), m_font); // Coral/Portocaliu
    m_menuButtons.emplace_back("QUIT GAME",   sf::Vector2f(startX, 620), sf::Color::Red, m_font);
}

void GameEngine::run() {
    while (m_window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void GameEngine::processEvents() {
    sf::Event event;
    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed){
            m_window.close();
        }

        if (m_isGameOver && event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::R) {
                initGame(); // Reincepe meciul actual
            }
            if (event.key.code == sf::Keyboard::M) {
                m_currentMode = GameMode::Menu;
                m_animationOffset = 800.f; // Resetam animatia pentru meniu
            }
        }

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (m_currentMode == GameMode::Menu) {
                // Detectăm ce buton a fost apăsat
                if (m_menuButtons[0].isClicked(mousePos)){
                    m_currentMode = GameMode::Easy;
                    initGame();
                }else if (m_menuButtons[1].isClicked(mousePos)){
                    m_currentMode = GameMode::Medium;
                    initGame();
                }else if (m_menuButtons[2].isClicked(mousePos)){
                    m_currentMode = GameMode::Hard;
                    initGame();
                }else if (m_menuButtons[3].isClicked(mousePos)){
                    m_currentMode = GameMode::WithFriend;
                    initGame();
                }else if (m_menuButtons[4].isClicked(mousePos)){
                    m_window.close();
                }
            }else if (!m_isGameOver && m_isPlayer1Turn) {
                // Logica de click pe tabla de joc
                Move m = m_player1->getMove(m_window);
                if (m_board.makeMove(m.row, m.col, m_player1->getSymbol())) {
                    m_isPlayer1Turn = false;
                }
            }else if (!m_isGameOver && !m_isPlayer1Turn && m_currentMode == GameMode::WithFriend) {
                Move m = m_player2->getMove(m_window);
                if (m_board.makeMove(m.row, m.col, m_player2->getSymbol())) {
                    m_isPlayer1Turn = true;
                }
            }
        }
    }
}

void GameEngine::initGame() {
    m_board.resetBoard();
    m_isGameOver = false;
    m_isPlayer1Turn = true;
    m_player1 = std::make_unique<HumanPlayer>(Cell::X, "You");

    // Initializam Player 2 în functie de alegere
    switch (m_currentMode) {
        case GameMode::Easy:   m_player2 = std::make_unique<EasyBot>(Cell::O, "Easy Bot"); break;
        case GameMode::Medium: m_player2 = std::make_unique<MediumBot>(Cell::O, "Medium Bot"); break;
        case GameMode::Hard:   m_player2 = std::make_unique<HardBot>(Cell::O, "Hard Bot"); break;
        case GameMode::WithFriend: m_player2 = std::make_unique<HumanPlayer>(Cell::O, "Friend"); break;
        default: break;
    }
}

void GameEngine::update() {
    if (m_currentMode == GameMode::Menu) {
        // Animatia de intrare (glisare in sus)
        if (m_animationOffset > 0) {
            m_animationOffset -= 15.f; // Ajusteaza viteza aici
        }

        sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
        for (auto& btn : m_menuButtons) btn.update(mousePos);
    }
    else {
        if (m_isGameOver) return;

        // Logica de victorie
        if (m_board.checkWinner() != Cell::Empty || m_board.isFull()) {
            m_isGameOver = true;
            return;
        }

        // Randul Bot-ului (daca nu e meci local)
        if (!m_isPlayer1Turn && m_currentMode != GameMode::WithFriend) {
            Move m;
            if (m_currentMode == GameMode::Easy){
                m = dynamic_cast<EasyBot*>(m_player2.get())->getMoveFromBoard(m_board);
            } else if (m_currentMode == GameMode::Medium){
                m = dynamic_cast<MediumBot*>(m_player2.get())->getSmartMove(m_board);
            }else if (m_currentMode == GameMode::Hard){
                m = dynamic_cast<HardBot*>(m_player2.get())->getBestMove(m_board);
            }

            if (m_board.makeMove(m.row, m.col, m_player2->getSymbol())) {
                m_isPlayer1Turn = true;
            }
        }
    }
}

void GameEngine::render() {
    m_window.clear(sf::Color(30, 30, 30));

    if (m_currentMode == GameMode::Menu) {
        m_window.draw(m_welcomeText);
        for (auto& btn : m_menuButtons) {
            btn.draw(m_window, m_animationOffset);
        }
    } else {
        m_renderer.drawGrid();
        m_renderer.drawMarkers(m_board);

        if (m_isGameOver) {
            // 1. Logica pentru Rezultat (MIJLOC)
            sf::Text resultText;
            resultText.setFont(m_font);
            resultText.setCharacterSize(80);
            resultText.setStyle(sf::Text::Bold);

            Cell winner = m_board.checkWinner();
            if (winner == Cell::X) {
                resultText.setString("YOU WIN!");
                resultText.setFillColor(sf::Color::Green);
            } else if (winner == Cell::O) {
                resultText.setString("YOU LOSE!");
                resultText.setFillColor(sf::Color::Red);
            } else {
                resultText.setString("DRAW!");
                resultText.setFillColor(sf::Color::Yellow);
            }

            // Centrare Rezultat (in centrul tablei, approx y=300)
            sf::FloatRect resRect = resultText.getLocalBounds();
            resultText.setOrigin(resRect.left + resRect.width / 2.0f, resRect.top + resRect.height / 2.0f);
            resultText.setPosition(300.f, 300.f);

            // 2. Logica pentru Instructiuni (JOS)
            sf::Text hintText;
            hintText.setFont(m_font);
            hintText.setString("Press R: Rematch | Press M: Menu");
            hintText.setCharacterSize(30);
            hintText.setFillColor(sf::Color(200, 200, 200)); // Gri deschis pentru a nu distrage atenția

            // Centrare Instructiuni (aproape de marginea de jos, y=680)
            sf::FloatRect hintRect = hintText.getLocalBounds();
            hintText.setOrigin(hintRect.left + hintRect.width / 2.0f, hintRect.top + hintRect.height / 2.0f);
            hintText.setPosition(300.f, 680.f);

            // Desenam ambele texte
            m_window.draw(resultText);
            m_window.draw(hintText);
        }
    }

    m_window.display();
}