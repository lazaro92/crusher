#ifndef GAME_TITLESTATE_HPP
#define GAME_TITLESTATE_HPP

#include "Engine/State.hpp"
#include "Engine/GUI/Container.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>


class TitleState : public State
{
    public:
                        TitleState(StateStack& stack, Context context);

        virtual void    draw();
        virtual bool    update(sf::Time dt);
        virtual bool    handleEvent(const sf::Event& event);

    private:
        sf::Sprite      mMainLogoSprite;
        sf::Text        mText;

        bool            mShowText;
        bool            mShowMenu;
        sf::Time        mTextEffectTime;
        GUI::Container  mGUIContainer;


};

#endif // GAME_TITLESTATE_HPP
