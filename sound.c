#include "SDL2/SDL_mixer.h"

#include "sound.h"

static Mix_Music* tetris;
static Mix_Chunk* sfx[4];

void initSound()
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    tetris = Mix_LoadMUS("sfx/tetris.wav");

    sfx[MOVEMENT] = Mix_LoadWAV("sfx/movement.wav");
    sfx[ROTATION] = Mix_LoadWAV("sfx/rotation.wav");
    sfx[HARD_DROP] = Mix_LoadWAV("sfx/hard_drop.wav");
    sfx[LINE_CLEAR] = Mix_LoadWAV("sfx/line_clear.wav");
    sfx[PAUSE] = Mix_LoadWAV("sfx/pause.wav");
    sfx[GAME_OVER] = Mix_LoadWAV("sfx/game_over.wav");
}

void playMusic()
{
    Mix_VolumeMusic(15);
    Mix_PlayMusic(tetris, -1);
}

void playSound(SoundEffect sound)
{
    if (sound == GAME_OVER) {
        Mix_HaltMusic();
        Mix_PlayChannel(-1, sfx[sound], 0);
        SDL_Delay(3000);
    }
    else
        Mix_PlayChannel(-1, sfx[sound], 0);
}
