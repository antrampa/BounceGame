#include "Ball.h"

Ball::Ball() :
    shape_(10),
    speed_(100)
{
    shape_.setFillColor(sf::Color::Cyan);
    shape_.setOrigin(shape_.getGeometricCenter());
    shape_.setPosition({600 * 0.50f, 800 * 0.25f});

    direction_ = {1, 0};
}

void Ball::Draw(sf::RenderWindow& window) const 
{
    window.draw(shape_);
}

void Ball::Move(float deltaTime)
{
    sf::Vector2 lastPosition = shape_.getPosition();

    shape_.move(direction_ * speed_ * deltaTime);

    if(shape_.getPosition().x < shape_.getRadius() ||
        shape_.getPosition().x >= 600 - shape_.getRadius()
    )
    {
        shape_.setPosition(lastPosition);
        direction_.x *= -1;
    }

    if(shape_.getPosition().y < shape_.getRadius()) 
    {
        shape_.setPosition(lastPosition);
        direction_.y *= -1;
    }
}