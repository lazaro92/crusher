#include "TitleState.hpp"

#include "Engine/Utility.hpp"
#include "Engine/GUI/Button.hpp"
#include "Engine/ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


TitleState::TitleState(StateStack& stack, Context context)
: State(stack, context)
, mText()
, mShowText(true)
, mShowMenu(false)
, mTextEffectTime(sf::Time::Zero)
, mGUIContainer()
{
	sf::RenderWindow& window = *getContext().window;

	mMainLogoSprite.setTexture(context.textures->get(Textures::CrusherLogo));
	mMainLogoSprite.setOrigin(mMainLogoSprite.getGlobalBounds().width / 2, mMainLogoSprite.getGlobalBounds().height / 2);
	mMainLogoSprite.setPosition(window.getSize().x / 2, window.getSize().y / 3);

	mText.setFont(context.fonts->get(Fonts::Pixel));
	mText.setString("Press any key to start");
	mText.setOrigin(mText.getGlobalBounds().width / 2, mText.getGlobalBounds().height / 2);
	mText.setPosition(window.getSize().x / 2, (window.getSize().y * 2) / 3);


	//mGuiContainer
	auto playButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	playButton->setPosition(window.getSize().x / 2, 250);
	playButton->setText("Play");
	playButton->setCallback([this] ()
	{
		requestStackPop();
		requestStackPush(States::Gameplay);
	});

	auto settingsButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	settingsButton->setPosition(window.getSize().x / 2, 300);
	settingsButton->setText("Settings");
	settingsButton->setCallback([this] ()
	{
		requestStackPush(States::Settings);
	});

	auto exitButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	exitButton->setPosition(window.getSize().x / 2, 350);
	exitButton->setText("Exit");
	exitButton->setCallback([this] ()
	{
		requestStackPop();
	});

	mGUIContainer.pack(playButton);
	mGUIContainer.pack(settingsButton);
	mGUIContainer.pack(exitButton);
}

void TitleState::draw()
{
    sf::RenderWindow& window = *getContext().window;

	window.draw(mMainLogoSprite);

	if (!mShowMenu)
	{
		if (mShowText)
			window.draw(mText);
	}
	else
	{
		window.draw(mGUIContainer);	
	}
}

bool TitleState::update(sf::Time dt)
{
	if (!mShowMenu)
	{
		mTextEffectTime += dt;

		if (mTextEffectTime >= sf::seconds(0.5f))
		{
			mShowText = !mShowText;
			mTextEffectTime = sf::Time::Zero;
		}
	}

	return true;
}

bool TitleState::handleEvent(const sf::Event& event)
{
	if (!mShowMenu)
	{
		if (event.type == sf::Event::KeyReleased)
		{
			mShowMenu = true;
		}
	}
	else
	{
		mGUIContainer.handleEvent(event);
	}

	return true;
}
