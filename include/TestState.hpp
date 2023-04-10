#ifndef GAME_TESTSTATE_HPP
#define GAME_TESTSTATE_HPP

#include "Engine/State.hpp"
#include "Engine/Player.hpp"

#include "Engine/ResourceHolder.hpp"
#include "Engine/ResourceIdentifiers.hpp"


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class TestState : public State
{
	public:
							TestState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		Player&				mPlayer;
		TextureHolder		mTextures;

		sf::Texture			mTexture;
		sf::Sprite          mSprite;
};

#endif // GAME_GAMESTATE_HPP
