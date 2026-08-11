#include "GameSounds.h"
#include "GameConfig.h"

GameSounds::GameSounds() :
    music_("Content/Music.mp3"),
    bounceSoundBuffer_("Content/Bounce.mp3"),
    bounceSound_(bounceSoundBuffer_)
{
    music_.setVolume(gConfig.musicVolume);
    music_.setLooping(true);
    music_.play();

    bounceSound_.setVolume(gConfig.bounceSoundVolume);
}

void GameSounds::PlayBounceSound()
{
    bounceSound_.play();
}