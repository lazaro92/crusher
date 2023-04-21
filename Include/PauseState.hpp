#ifndef GAME_PAUSESTATE_HPP
#define GAME_PAUSESTATE_HPP

#include "Engine/State.hpp"
#include "Engine/GUI/Container.hpp"

#include "Engine/ResourceHolder.hpp"
#include "Engine/ResourceIdentifiers.hpp"

#include <SFML/Graphics/Text.hpp>


class PauseState : public State
{
	public:
							PauseState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);


	private:
		sf::Text            mPauseText;
		GUI::Container      mGUIContainer;


};

#endif // GAME_PAUSESTATE_HPP
