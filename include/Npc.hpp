#ifndef NPC_HPP
#define NPC_HPP

#include "Engine/State.hpp"
#include "Engine/Player.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

/**
* State that is for playing the game 
*/
class Npc
{
	public:
							TestState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		Player&				mPlayer;
};

#endif // NPC_HPP
