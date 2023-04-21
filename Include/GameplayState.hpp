#ifndef GAME_PLAYSTATE_HPP
#define GAME_PLAYSTATE_HPP

#include "Engine/State.hpp"
#include "Engine/Player.hpp"

#include "Engine/ResourceHolder.hpp"
#include "Engine/ResourceIdentifiers.hpp"


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class GameplayState : public State
{
	public:
							GameplayState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		Player&				mPlayer;

};

#endif // GAME_PLAYSTATE_HPP
