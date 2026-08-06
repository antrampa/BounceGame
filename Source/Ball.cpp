#include "Ball.h"

Ball::Ball() :
    shape_(10),
    speed_(100)
{
    shape_.setFillColor(sf::Color::Cyan);
    shape_.setOrigin(shape_.getGeometricCenter());
    shape_.setPosition({600 * 0.50f, 800 * 0.25f});

    direction_ = {0, -1};
}

void Ball::Draw(sf::RenderWindow& window) const 
{
    window.draw(shape_);
}

void Ball::Move(float deltaTime)
{
    shape_.move(direction_ * speed_ * deltaTime);
}