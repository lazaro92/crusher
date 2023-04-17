#ifndef GAME_SETTINGS_HPP
#define GAME_SETTINGS_HPP

#include "Engine/State.hpp"
#include "Engine/GUI/Container.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>


class SettingsState : public State
{
    public:
                        SettingsState(StateStack& stack, Context context);

        virtual void    draw();
        virtual bool    update(sf::Time dt);
        virtual bool    handleEvent(const sf::Event& event);

    private:
        GUI::Container  mGUIContainer;


};

#endif // GAME_SETTINGS_HPP
