#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "SFML/Graphics.hpp"

class Button : public sf::Drawable
{
public:
    Button(float width,  float height);

    bool pointIntersects(sf::Vector2f point);

    // Setters
    void SetText(sf::String text);
    void SetForeground(sf::Color);

    // Getters
    sf::Text& GetText();

    virtual void OnMousePressed();
private:
    virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates rStates) const;
    sf::Vector2u buttonSize;
    sf::Text buttonText;
};

#endif