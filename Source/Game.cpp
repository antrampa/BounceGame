#include "Game.h"

#include <iostream>

Game::Game() : 
    window_(sf::VideoMode({600, 800}), "My SFML Bounce Game")
{
    window_.setFramerateLimit(60);
}

bool Game::IsRunning() const
{
    return window_.isOpen();
}

void Game::ProcessEvents() 
{
    while (std::optional<sf::Event> event = window_.pollEvent())
    {
        if(event->is<sf::Event::Closed>())
        {
            window_.close();
        }
    }
}

void Game::Update()
{
    float deltaTime = clock_.restart().asSeconds();

    paddle_.Move(deltaTime);
    ball_.Move(deltaTime);

    HandleCollisions();
}

void Game::Render() 
{
    window_.clear();

    paddle_.Draw(window_);
    ball_.Draw(window_);

    window_.display();
}

void Game::HandleCollisions() 
{
    sf::FloatRect ballBounds = ball_.GetGlobalBounds();
    sf::FloatRect paddleBounds = paddle_.GetGlobalBounds();

    bool isColliding = ballBounds.findIntersection(paddleBounds).has_value();

    if(isColliding)
    {
        std::cout << "Collision" << std::endl;
    }
}

