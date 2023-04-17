#ifndef NPC_HPP
#define NPC_HPP


#include <SFML/Graphics/Sprite.hpp>


class Npc : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
    public:
                        Npc(sf::Sprite& sprite);

    private:
        virtual void    draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::Sprite&     mSprite;
};

#endif // NPC_HPP
