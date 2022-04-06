#include "Button.hpp"

Button::Button(float width, float height)
{
    buttonSize = sf::Vector2f(width, height);

    vertices.setPrimitiveType(sf::PrimitiveType::Quads);
    vertices.resize(4);

    SetPosition(sf::Vector2f(0,0));
    SetForeground(sf::Color::White);

    buttonText.setFillColor(sf::Color::Black);
};

bool Button::PointIntersects(const sf::Vector2f& point)
{
    if((point.x > buttonPosition.x && point.x < (buttonPosition.x+buttonSize.x)) && (point.y > buttonPosition.y && point.y < buttonPosition.y+buttonSize.y))
    {
        return true;
    };

    return false;
};

void Button::SetSize(const sf::Vector2f& size)
{
    buttonSize.x = size.x;
    buttonSize.y = size.y;

    // Top left
    vertices[0].position = sf::Vector2f(buttonPosition.x, buttonPosition.y);
    // Top right
    vertices[1].position = sf::Vector2f(buttonPosition.x+buttonSize.x, buttonPosition.y);
    // Bottom Right
    vertices[2].position = sf::Vector2f(buttonPosition.x+buttonSize.x, buttonPosition.y+buttonSize.y);
    // Bottom Left
    vertices[3].position = sf::Vector2f(buttonPosition.x, buttonPosition.y+buttonSize.y);
}

void Button::SetFont(const sf::Font& font)
{
    buttonText.setFont(font);
};

void Button::SetText(const sf::String text)
{
    sf::FloatRect b = buttonText.getLocalBounds();

    buttonText.setString(text);
    SetSize(sf::Vector2f(buttonText.getLocalBounds().width, buttonText.getLocalBounds().height));
    UpdateTextPos();
}

void Button::SetForeground(const sf::Color c)
{
    vertices[0].color = vertices[1].color = vertices[2].color = vertices[3].color = c;
};

void Button::SetPosition(const sf::Vector2f pos)
{
    buttonPosition = pos;

    // Top left
    vertices[0].position = sf::Vector2f(pos.x, pos.y);
    // Top right
    vertices[1].position = sf::Vector2f(pos.x+buttonSize.x, pos.y);
    // Bottom Right
    vertices[2].position = sf::Vector2f(pos.x+buttonSize.x, pos.y+buttonSize.y);
    // Bottom Left
    vertices[3].position = sf::Vector2f(pos.x, pos.y+buttonSize.y);

    
    buttonText.setPosition(pos);
};

void Button::SetCallback(std::function<void(void)> func)
{
    buttonCallback = func;
};

sf::Text& Button::GetText()
{
    return buttonText;
}

void Button::OnEvent(const sf::Event& event)
{
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left)
    {
        sf::Vector2f mPos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
        if(PointIntersects(mPos))
        {
            OnMousePressed();
        }
    }
};

void Button::OnMousePressed()
{
    if(buttonCallback)
    {
        buttonCallback();
    }
};

void Button::UpdateTextPos()
{
    buttonText.setPosition(buttonPosition.x, (buttonPosition.y + buttonSize.y/2) - (buttonText.getLocalBounds().height));
};

void Button::draw(sf::RenderTarget& rTarget, sf::RenderStates rStates) const
{
    rTarget.draw(vertices, rStates);
    rTarget.draw(buttonText, rStates);
};