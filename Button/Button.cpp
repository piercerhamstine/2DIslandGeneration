#include "Button.hpp"

Button::Button(float width, float height)
{
    buttonSize = sf::Vector2f(width, height);

    vertices.setPrimitiveType(sf::PrimitiveType::Quads);
    vertices.resize(4);
};

void Button::SetPosition(sf::Vector2f pos)
{
    buttonPosition = pos;

    // Top left
    vertices[0].position = sf::Vector2f(pos.x, pos.y);
    // Top right
    vertices[1].position = sf::Vector2f(pos.x*buttonSize.x, pos.y);
    // Bottom Right
    vertices[2].position = sf::Vector2f(pos.x*buttonSize.x, pos.y*buttonSize.y);
    // Bottom Left
    vertices[3].position = sf::Vector2f(pos.x, pos.y*buttonSize.y);
};

void Button::draw(sf::RenderTarget& rTarget, sf::RenderStates rStates) const
{
    rTarget.draw(vertices, rStates);
};