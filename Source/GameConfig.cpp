#include "GameConfig.h"

GameConfig::GameConfig() : 
    windowSize(600, 800),
    paddleSize(120, 20),
    paddleSpeed(750),
    ballSpeed(250),
    ballRadius(10),
    ballSpawnCooldown(2),
    musicVolume(5),
    bounceSoundVolume(10),
    startingLives(10)
{
}