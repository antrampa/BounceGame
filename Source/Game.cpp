#include "Game.h"

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

    if(ballSpawnClock_.getElapsedTime().asSeconds() > 2)
    {
        balls_.emplace_back();
        ballSpawnClock_.restart();
    }

    paddle_.Move(deltaTime);
    for(Ball& ball : balls_)
    {
        ball.Move(deltaTime);
    }
    
    HandleCollisions();
}

void Game::Render() 
{
    window_.clear();

    paddle_.Draw(window_);

    for(const Ball& ball : balls_)
    {
        ball.Draw(window_);
    }

    window_.display();
}

void Game::HandleCollisions() 
{
    sf::FloatRect paddleBounds = paddle_.GetGlobalBounds();
    
    for(Ball& ball : balls_)
    {
        sf::FloatRect ballBounds = ball.GetGlobalBounds();

        bool isColliding = ballBounds.findIntersection(paddleBounds).has_value();

        if(isColliding && ball.GetDirection().y > 0) 
        {
            ball.Bounce();
        }
    }
}

