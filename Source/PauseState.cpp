#include "PauseState.hpp"

#include "Engine/GUI/Button.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


PauseState::PauseState(StateStack& stack, Context context)
: State(stack, context)
, mPauseText()
, mGUIContainer()
{
	sf::RenderWindow& window = *getContext().window;
	mPauseText.setOrigin(mPauseText.getGlobalBounds().width / 2, mPauseText.getGlobalBounds().height / 2);
	mPauseText.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    mPauseText.setFont(context.fonts->get(Fonts::Pixel));
	mPauseText.setString("Pause");

	auto continueButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	continueButton->setPosition(window.getSize().x / 2, 250);
	continueButton->setText("Continue");
	continueButton->setCallback([this] ()
	{
        requestStackPop();
	});

	auto returnTitleButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	returnTitleButton->setPosition(window.getSize().x / 2, 300);
	returnTitleButton->setText("Return to title screen");
	returnTitleButton->setCallback([this] ()
	{
		requestStateClear();
        requestStackPush(States::Title);
	});

	mGUIContainer.pack(continueButton);
	mGUIContainer.pack(returnTitleButton);

}

void PauseState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.draw(mPauseText);
	window.draw(mGUIContainer);	

}

bool PauseState::update(sf::Time dt)
{
    return false;
}

bool PauseState::handleEvent(const sf::Event& event)
{
    mGUIContainer.handleEvent(event);
	return false;
}
