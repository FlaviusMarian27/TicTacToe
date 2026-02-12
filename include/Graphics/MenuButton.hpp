#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Core/Constants.hpp"

class MenuButton {
public:
    // Constructor care primeste textul, pozitia si culoarea textului
    MenuButton(const std::string& textStr, sf::Vector2f position, sf::Color textColor, sf::Font& font);

    // Actualizeaza starea (hover/click)
    void update(sf::Vector2i mousePos);

    // Deseneaza butonul pe ecran
    void draw(sf::RenderWindow& window, float animationOffset);

    // Verifică daca butonul a fost apasat
    bool isClicked(sf::Vector2i mousePos) const;

private:
    sf::RectangleShape m_shape;
    sf::Text m_text;
    sf::Color m_baseTextColor;
    bool m_isHovered;
};