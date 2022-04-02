#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "SFML/Graphics.hpp"

class Button : public sf::Drawable
{
public:
    Button(float width,  float height);

    bool PointIntersects(sf::Vector2f point);

    // Setters
    void SetText(sf::String text);
    void SetForeground(sf::Color);
    void SetPosition(sf::Vector2f pos);

    // Getters
    sf::Text& GetText();

    virtual void OnMousePressed();
private:
    virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates rStates) const;
    sf::Vector2f buttonSize;
    sf::Text buttonText;
    sf::Vector2f buttonPosition;
    sf::VertexArray vertices;
};

#endif