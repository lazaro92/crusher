#include "Engine/Application.hpp"
#include "Engine/State.hpp"
#include "Engine/StateIdentifiers.hpp"

#if _DEBUG
#include <iostream>
#endif

// INCLUDE STATES
#include "TestState.hpp"


const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application()
: mWindow(sf::VideoMode(256, 224), "Crusher", sf::Style::Close)
, mTextures()
, mFonts()
, mPlayer()
, mMusic()
, mSounds()
, mStateStack(State::Context(mWindow, mTextures, mFonts, mPlayer, mMusic, mSounds))
#if _DEBUG
, mStatisticsText()
#endif
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
{
    mWindow.setFramerateLimit(60);
	mWindow.setKeyRepeatEnabled(false);

    // LOAD fonts
    mFonts.load(Fonts::Main, "Media/Sansation.ttf");

    // LOAD Button Textures and Title Screen Texture
	// mTextures.load(Textures::TitleScreen,		"Media/Textures/Title_screen.png");

    #if _DEBUG
        mStatisticsText.setFont(mFonts.get(Fonts::Main));
        mStatisticsText.setPosition(5.f, 5.f);
        mStatisticsText.setCharacterSize(14u);
    #endif

	registerStates();
    
    // PUSH STATES
    mStateStack.pushState(States::Test);

    // SET MUSIC VOLUME
    // mMusic.setVolume(25.f);
}

void Application::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processInput();
			update(TimePerFrame);

			// Check inside this loop, because stack might be empty before update() call
			if (mStateStack.isEmpty())
            {
                #if _DEBUG
                std::cout << "INFO: State Stack is empty" << std::endl;
                #endif
				mWindow.close();
            }
		}
        #if _DEBUG
		updateStatistics(dt);
        #endif
		render();
	}
}

void Application::processInput()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		mStateStack.handleEvent(event);

		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

void Application::update(sf::Time dt)
{
	mStateStack.update(dt);
}

void Application::render()
{
	mWindow.clear();

	mStateStack.draw();

	mWindow.setView(mWindow.getDefaultView());
    #if _DEBUG
	mWindow.draw(mStatisticsText);
    #endif

	mWindow.display();
}

#if _DEBUG
void Application::updateStatistics(sf::Time dt)
{
	mStatisticsUpdateTime += dt;
	mStatisticsNumFrames += 1;
	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString("FPS: " + std::to_string(mStatisticsNumFrames));

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}
#endif

void Application::registerStates()
{
	mStateStack.registerState<TestState>(States::Test);
}
