#ifndef BOX_HPP
#define BOX_HPP

#include <SFML/Graphics.hpp>

class Box : public sf::Drawable
{
public:
    Box();
    void SetPosition(sf::Vector2f pos);
    void SetSize(sf::Vector2f size);
private:
    virtual void draw(sf::RenderTarget& rTarget, sf::RenderStates states) const;
};

#endif