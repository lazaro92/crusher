#include "PhoenixState.hpp"
#include "Engine/ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


PhoenixState::PhoenixState(StateStack& stack, Context context)
: State(stack, context)
, mLogoOpacityEffectTime(sf::Time::Zero)
, currentStatus(Status::fadeIn)
, mLogoAlphaChannel(0)
{
    mBackgroundSprite.setTexture(context.textures->get(Textures::PhoenixLogo));

	sf::RenderWindow& window = *getContext().window;
	mBackgroundSprite.setOrigin(mBackgroundSprite.getGlobalBounds().width / 2, mBackgroundSprite.getGlobalBounds().height / 2);
	mBackgroundSprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	mBackgroundSprite.setColor(sf::Color(255, 255, 255, mLogoAlphaChannel));

}

void PhoenixState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	window.draw(mBackgroundSprite);
}

bool PhoenixState::update(sf::Time dt)
{
	mLogoOpacityEffectTime += dt;

	if (currentStatus == Status::fadeIn && mLogoOpacityEffectTime >= sf::seconds(0.05f))
	{	
		if (mLogoAlphaChannel < 250)
			mLogoAlphaChannel += 10;
		else 
		{
			mLogoAlphaChannel = 255;
			currentStatus = Status::wait;
		}
		mBackgroundSprite.setColor(sf::Color(255, 255, 255, mLogoAlphaChannel));
		mLogoOpacityEffectTime = sf::Time::Zero;
	}
	else if (currentStatus == Status::wait && mLogoOpacityEffectTime >= sf::seconds(3.0f))
	{
		currentStatus = Status::fadeOut;
		mLogoOpacityEffectTime = sf::Time::Zero;
	}
	else if (currentStatus == Status::fadeOut && mLogoOpacityEffectTime >= sf::seconds(0.05f))
	{
		if (mLogoAlphaChannel > 11)
			mLogoAlphaChannel -= 10;
		else 
		{
			mLogoAlphaChannel = 0;
			requestStackPop();
			requestStackPush(States::Title);
		}
		mBackgroundSprite.setColor(sf::Color(255, 255, 255, mLogoAlphaChannel));
		mLogoOpacityEffectTime = sf::Time::Zero;
	}
return false;
}

bool PhoenixState::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased && currentStatus != Status::fadeOut)
		currentStatus = Status::fadeOut;
	return false;
}
