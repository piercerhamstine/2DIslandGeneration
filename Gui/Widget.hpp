#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>

namespace ui
{
enum State
{
    DefaultState,
    HoveredState,
    PressedState
};

class Widget : public sf::Drawable
{
public:
    Widget();

    void SetPosition(sf::Vector2f pos);

    virtual void OnStateChange(State state);
    virtual void OnMousePressed();
    virtual void OnMouseReleased();
private:
    sf::Vector2f position;
    sf::Vector2f size;
};
}

#endif