#include "Graphics/MenuButton.hpp"

MenuButton::MenuButton(const std::string& textStr, sf::Vector2f position, sf::Color textColor, sf::Font& font)
    : m_baseTextColor(textColor), m_isHovered(false) {

    // Configurare Text
    m_text.setFont(font);
    m_text.setString(textStr);
    m_text.setCharacterSize(35);
    m_text.setFillColor(textColor);

    // centrare text in interiorul butonului
    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);

    // configurare forma buton (dreptunghiul cu margini verzi)
    m_shape.setSize(sf::Vector2f(350.f, 70.f));
    m_shape.setFillColor(sf::Color(40, 40, 40)); // gri inchis ca in imagine
    m_shape.setOutlineThickness(3.f);
    m_shape.setOutlineColor(sf::Color(0, 255, 127)); // verdele neon din poza ta
    m_shape.setOrigin(m_shape.getSize().x / 2.0f, m_shape.getSize().y / 2.0f);

    m_shape.setPosition(position);
    m_text.setPosition(position);
}

void MenuButton::update(sf::Vector2i mousePos) {
    // verificam daca mouse ul este deasupra butonului
    if (m_shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        if (!m_isHovered) {
            m_isHovered = true;
            m_shape.setOutlineThickness(5.f); // se ingroasa marginea
            m_shape.setScale(1.05f, 1.05f);   // creste putin in dimensiune
        }
    } else {
        m_isHovered = false;
        m_shape.setOutlineThickness(3.f);
        m_shape.setScale(1.0f, 1.0f);
    }
}

void MenuButton::draw(sf::RenderWindow& window, float animationOffset) {
    // aplicam offset ul pentru animatia de intrare (glisare pe axa Y)
    sf::Vector2f originalPos = m_shape.getPosition();
    m_shape.setPosition(originalPos.x, originalPos.y + animationOffset);
    m_text.setPosition(originalPos.x, originalPos.y + animationOffset);

    window.draw(m_shape);
    window.draw(m_text);

    //rsesetam pozitia pentru a nu "fugi" de pe ecran la urmatorul frame
    m_shape.setPosition(originalPos);
    m_text.setPosition(originalPos);
}

bool MenuButton::isClicked(sf::Vector2i mousePos) const {
    return m_shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}