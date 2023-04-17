#include "SettingsState.hpp"

#include "Engine/Utility.hpp"
#include "Engine/GUI/Button.hpp"
#include "Engine/ResourceHolder.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


SettingsState::SettingsState(StateStack& stack, Context context)
: State(stack, context)
, mGUIContainer()
{
	sf::RenderWindow& window = *getContext().window;

	//mGuiContainer
	auto playButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	playButton->setPosition(window.getSize().x / 2, 250);
	playButton->setText("Play");
	playButton->setCallback([this] ()
	{
        // TODO add code
	});

	mGUIContainer.pack(playButton);
}

void SettingsState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.draw(mGUIContainer);	
}

bool SettingsState::update(sf::Time dt)
{
	return true;
}

bool SettingsState::handleEvent(const sf::Event& event)
{
    mGUIContainer.handleEvent(event);
	return true;
}
