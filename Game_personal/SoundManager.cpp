#include "SoundManager.h"
#include <iostream>

bool SoundManager::load(const char* fileName, std::string id, int type)
{
	//type1 = music, type2 =sfx
	if (type == 1) {
		Mix_Music* music = Mix_LoadMUS(fileName);
		if (music == nullptr) {
			std::cout << Mix_GetError() << std::endl;
			return false;
		}
		s_mMusic[id] = music;
		return true;
	}
	else if (type == 0) {
		Mix_Chunk* chunk = Mix_LoadWAV(fileName);
		if (chunk == nullptr) {
			std::cout << Mix_GetError() << std::endl;
			return false;
		}
		s_mSfxs[id] = chunk;
		return true;
	}
	return false;
}

void SoundManager::playSound(std::string id, int loop, int ms)
{
	if (Mix_FadeInChannel(-1, s_mSfxs[id], loop, ms) == -1) {
		std::cout << Mix_GetError() << std::endl;
	}
}

void SoundManager::playMusic(std::string id, int loop, int ms)
{
	if (Mix_FadeInMusic(s_mMusic[id], loop, ms) == -1) {
		std::cout << Mix_GetError() << std::endl;
	}
}

int SoundManager::changeVolume(int change)
{
	//int currentVolume = Mix_Volume(-1, -1);
	int currentVolume = Mix_VolumeMusic(-1);
	std::cout << "Current volume level: " << currentVolume << std::endl;
	if (currentVolume != 0 || currentVolume != MIX_MAX_VOLUME) currentVolume += change*MIX_MAX_VOLUME/10;
	//Mix_Volume(-1, currentVolume);
	Mix_VolumeMusic(currentVolume);
	return 0;
}

int SoundManager::changeVolumeSFX(int change)
{
	//int currentVolume = Mix_Volume(-1, -1);
	int currentVolume = Mix_Volume(-1,-1);
	//std::cout << "Current volume level: " << currentVolume << std::endl;
	if (currentVolume != 0 || currentVolume != MIX_MAX_VOLUME) currentVolume += change * MIX_MAX_VOLUME / 10;
	//Mix_Volume(-1, currentVolume);
	Mix_Volume(-1,currentVolume);
	return 0;
}

void SoundManager::pauseOrPlay()
{
	if (Mix_PausedMusic() == false) {
		Mix_PauseMusic();
	}
	else Mix_ResumeMusic();

}

void SoundManager::pauseOrPlaySFX()
{
	if (Mix_Paused(-1) == false) {
		Mix_Pause(-1);
	}
	else Mix_Resume(-1);
}

void SoundManager::SetMusicPosition(double pos)
{
	Mix_SetMusicPosition(pos);
	/*if (Mix_SetMusicPosition(pos) == 0) {
		Mix_PauseMusic();
	}
	else Mix_ResumeMusic();*/
}

SoundManager::SoundManager() {
	if (Mix_OpenAudio(48000, AUDIO_S16SYS, 2, 4096) == -1) {
		std::cout << Mix_GetError() << std::endl;
	}
}

SoundManager* SoundManager::s_mInstance = 0;

