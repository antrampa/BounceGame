#pragma once 

#include <SFML/Graphics.hpp>

class Paddle 
{
    private:
        sf::RectangleShape shape_;

    public:
        Paddle();

        void Draw(sf::RenderWindow& window) const;
};