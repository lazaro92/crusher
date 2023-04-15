#include "TitleState.hpp"
#include "Engine/Utility.hpp"

#include "Engine/ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


TitleState::TitleState(StateStack& stack, Context context)
: State(stack, context)
, mText()
, mShowText(true)
, mTextEffectTime(sf::Time::Zero)
{
	mText.setFont(context.fonts->get(Fonts::Pixel));
	mText.setString("Press any key to start");
	mText.setPosition(sf::Vector2f(context.window->getSize() / 2u));
}

void TitleState::draw()
{
    sf::RenderWindow& window = *getContext().window;

	if (mShowText)
		window.draw(mText);

}

bool TitleState::update(sf::Time dt)
{
	mTextEffectTime += dt;

	if (mTextEffectTime >= sf::seconds(0.5f))
	{
		mShowText = !mShowText;
		mTextEffectTime = sf::Time::Zero;
	}

	return true;
}

bool TitleState::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased)
	{
		requestStackPop();
	}

	return true;
}
