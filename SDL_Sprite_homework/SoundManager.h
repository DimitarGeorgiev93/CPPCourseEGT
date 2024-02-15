#pragma once

#include "Game.h"
#include<map>
#include <string>

class SoundManager
{
public:
	static SoundManager* Instance() {
		if (s_mInstance == 0) {
			s_mInstance = new SoundManager();
			return s_mInstance;
		}
		else return s_mInstance;
	}
	bool load(const char* fileName, std::string id, int type);
	void playSound(std::string id, int loop, int ms = 0);
	void playMusic(std::string id, int loop, int ms = 0);
	int changeVolume(int change);
	int changeVolumeSFX(int change);
	void pauseOrPlay();
	void pauseOrPlaySFX();
	void SetMusicPosition(double pos);

private:
	static SoundManager* s_mInstance;
	std::map<std::string, Mix_Chunk*> s_mSfxs; // sound files
	std::map<std::string, Mix_Music*> s_mMusic; // music files
	SoundManager();
	~SoundManager();
};

