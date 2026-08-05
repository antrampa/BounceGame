#pragma once

#include <SFML/Graphics.hpp>

#include "Paddle.h"

class Game 
{
    private:
        sf::RenderWindow window_;

        Paddle paddle_;
        
    public:
        Game();

        bool IsRunning() const;

        void ProcessEvents();
        void Update();
        void Render();
};