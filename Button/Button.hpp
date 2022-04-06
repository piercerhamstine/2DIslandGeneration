#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <iostream>
#include <functional>
#include "SFML/Graphics.hpp"

class Button : public sf::Drawable
{
public:
    Button(float width,  float height);

    bool PointIntersects(const sf::Vector2f& point);

    // Setters
    void SetSize(const sf::Vector2f& size);
    void SetFont(const sf::Font& font);
    void SetText(const sf::String text);
    void SetForeground(const sf::Color c);
    void SetPosition(const sf::Vector2f pos);
    void SetCallback(std::function<void(void)> func);

    // Getters
    sf::Text& GetText();

    virtual void OnEvent(const sf::Event& event);
    virtual void OnMousePressed();
private:
    void UpdateTextPos();
    virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates rStates) const;

    std::function<void(void)> buttonCallback;

    sf::Vector2f buttonSize;
    sf::Text buttonText;
    sf::Vector2f buttonPosition;
    sf::VertexArray vertices;
};

#endif