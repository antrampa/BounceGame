#pragma once

#include <SFML/Graphics.hpp>

#include "Paddle.h"
#include "Ball.h"

class Game 
{
    private:
        sf::RenderWindow window_;
        sf::Clock clock_;

        Paddle paddle_;
        Ball ball_;

    public:
        Game();

        bool IsRunning() const;

        void ProcessEvents();
        void Update();
        void Render();

    private:
        void HandleCollisions();
};