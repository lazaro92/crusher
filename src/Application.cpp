#include "Application.hpp"

#include <SFML/Window/Event.hpp>


const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);


Application::Application()
:mWindow(sf::VideoMode(256, 224), "Crusher", sf::Style::Close) {
    mWindow.setFramerateLimit(60);
	mWindow.setKeyRepeatEnabled(false);

}

void Application::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen()) {
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;

			processInput();
			update(TimePerFrame);
		}

        render();
	}
}

void Application::processInput() {
	sf::Event event;
	while (mWindow.pollEvent(event)) {
        // TODO add input processing

		if (event.type == sf::Event::Closed) {
			mWindow.close();
        }
	}
}

void Application::update(sf::Time dt) {
    // TODO add update functionality
}

void Application::render()
{
    // TODO complete render functionality

	mWindow.clear();

	mWindow.display();
}
