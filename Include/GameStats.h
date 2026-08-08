#pragma once 

#include <SFML/Graphics.hpp>

class GameStats
{
    private:
        sf::Font font_;

        sf::Text scoreText_;
        sf::Text livesText_;

        int score_;
        int lives_;

    public:
        GameStats();

        void Draw(sf::RenderWindow& window) const;

        void SetScore(int score);
        void SetLives(int lives);

        int GetScore() const;
        int GetLives() const;

        void Reset();
};
