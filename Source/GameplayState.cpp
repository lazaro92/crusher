#include "GameplayState.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


GameplayState::GameplayState(StateStack& stack, Context context)
: State(stack, context)
, mPlayer(*context.player)
{
}

void GameplayState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

}

bool GameplayState::update(sf::Time dt)
{
	return false;
}

bool GameplayState::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		requestStackPush(States::Pause);

	return false;
}
