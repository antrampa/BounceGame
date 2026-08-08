#include "Ball.h"

#include <numbers>
#include <cmath>

#include "Random.h"

Ball::Ball() :
    shape_(10),
    speed_(250)
{
    shape_.setFillColor(sf::Color::Cyan);
    shape_.setOrigin(shape_.getGeometricCenter());
    shape_.setPosition({600 * 0.50f, 800 * 0.25f});

    float angle = gRandom.GetFloat(0, 2 * std::numbers::pi_v<float>);
    direction_ = { std::cos(angle), std::sin(angle) };
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

sf::FloatRect Ball::GetGlobalBounds() const 
{
    return shape_.getGlobalBounds();
}

sf::Vector2f Ball::GetDirection() const 
{
    return direction_;
}

void Ball::Bounce()
{
    direction_.y *= -1;
}

bool Ball::IsOutside() const 
{
    return shape_.getPosition().y - shape_.getRadius() >  800;
}