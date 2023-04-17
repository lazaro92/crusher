#ifndef GAME_PHOENIXSTATE_HPP
#define GAME_PHOENIXSTATE_HPP

#include "Engine/State.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>


class PhoenixState : public State
{
    public:
                            PhoenixState(StateStack& stack, Context context);

        virtual void        draw();
        virtual bool        update(sf::Time dt);
        virtual bool        handleEvent(const sf::Event& event);


    private:
        sf::Sprite          mBackgroundSprite;
        sf::Time            mLogoOpacityEffectTime;

        enum Status { fadeIn, wait, fadeOut };

        Status              currentStatus;
        int                 mLogoAlphaChannel;

};

#endif // GAME_PHOENIXSTATE_HPP
