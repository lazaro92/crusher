#ifndef GAME_MUSICPLAYER_HPP
#define GAME_MUSICPLAYER_HPP

#include "Engine/ResourceHolder.hpp"
#include "Engine/ResourceIdentifiers.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/Music.hpp>

#include <map>
#include <string>

/**
* Player to reproduce the music in another thread.
*/
class MusicPlayer : private sf::NonCopyable
{
	public:
									MusicPlayer();

		void						play(Music::ID theme);
		void						stop();

		void						setPaused(bool paused);
		void						setVolume(float volume);


	private:
		sf::Music							mMusic;
		std::map<Music::ID, std::string>	mFilenames;
		float								mVolume;
};

#endif // GAME_MUSICPLAYER_HPP
