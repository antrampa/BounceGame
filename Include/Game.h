#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "Paddle.h"
#include "Ball.h"

class Game 
{
    private:
        sf::RenderWindow window_;
        sf::Clock clock_;

        Paddle paddle_;
        std::vector<Ball> balls_;
        sf::Clock ballSpawnClock_;

    public:
        Game();

        bool IsRunning() const;

        void ProcessEvents();
        void Update();
        void Render();

    private:
        void HandleCollisions();
};