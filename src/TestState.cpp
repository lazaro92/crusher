#include "TestState.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


TestState::TestState(StateStack& stack, Context context)
: State(stack, context)
, mPlayer(*context.player)
, mTextures()
{
	mTextures.load(Textures::EntitiesSheet, "Media/Textures/spritesheet.png");

	mTexture = mTextures.get(Textures::EntitiesSheet);
	mSprite = sf::Sprite(mTexture, sf::IntRect(0, 0, 32, 32));

}

void TestState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	window.draw(mSprite);
}

bool TestState::update(sf::Time dt)
{
	return false;
}

bool TestState::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		requestStateClear();

	return false;
}
