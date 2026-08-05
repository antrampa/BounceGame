#include "Paddle.h"

Paddle::Paddle() : 
    shape_({120, 20}) 
{
    shape_.setFillColor(sf::Color::Green);
    shape_.setOrigin(shape_.getGeometricCenter());
    shape_.setPosition({600 * 0.50f, 800 * 0.85f});
}

void Paddle::Draw(sf::RenderWindow& window) const 
{
    window.draw(shape_);
}