#ifndef GAME_SOLEAUSTATE_HPP
#define GAME_SOLEAUSTATE_HPP

#include "Engine/State.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>


class SoleauState : public State
{
    public:
                            SoleauState(StateStack& stack, Context context);

        virtual void        draw();
        virtual bool        update(sf::Time dt);
        virtual bool        handleEvent(const sf::Event& event);


    private:
        sf::Sprite          mBackgroundSprite;
        sf::Time            mLogoOpacityEffectTime;

        int                 mLogoAlphaChannel;
        int                 mFading;

};

#endif // GAME_SOLEAUSTATE_HPP
