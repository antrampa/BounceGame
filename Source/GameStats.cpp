#include "GameStats.h"

#include <format>

GameStats::GameStats() : 
    font_("Content/Montserrat-Regular.ttf"),
    scoreText_(font_),
    livesText_(font_)
{
    scoreText_.setPosition({10, 10});
    scoreText_.setFillColor(sf::Color::Cyan);
    SetScore(0);

    livesText_.setPosition({10, 60});
    livesText_.setFillColor(sf::Color::Red);
    SetLives(5);
}

void GameStats::Draw(sf::RenderWindow& window) const
{
    window.draw(scoreText_);
    window.draw(livesText_);
}

void GameStats::SetScore(int score)
{
    score_ = score;
    scoreText_.setString("Score: " + std::to_string(score_));
}

void GameStats::SetLives(int lives)
{
    lives_ = lives;
    //livesText_.setString("Lives: " + std::to_string(lives_));
    livesText_.setString(std::format("Lives: {}", lives_));
}

int GameStats::GetScore() const
{
    return score_;
}

int GameStats::GetLives() const 
{
    return lives_;
}

void GameStats::Reset() 
{
    SetScore(0);
    SetLives(5);
}
