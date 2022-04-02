#include "Button.hpp"

Button::Button(float width, float height)
{
    buttonSize = sf::Vector2f(width, height);

    vertices.setPrimitiveType(sf::PrimitiveType::Quads);
    vertices.resize(4);

    SetPosition(sf::Vector2f(0,0));
    SetForeground(sf::Color::White);
};

bool Button::PointIntersects(sf::Vector2f point)
{
    // Find if the point intersects the button.

    // TODO
    return false;
};

void Button::SetText(sf::String text)
{
    buttonText.setString(text);
}

void Button::SetForeground(sf::Color c)
{
    vertices[0].color = vertices[1].color = vertices[2].color = vertices[3].color = c;
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

sf::Text& Button::GetText()
{
    return buttonText;
}

void Button::OnMousePressed()
{
    // default button pressed.
};

void Button::draw(sf::RenderTarget& rTarget, sf::RenderStates rStates) const
{
    rTarget.draw(vertices, rStates);
};