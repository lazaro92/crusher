#include "Npc.hpp"


Npc::Npc(sf::Sprite& sprite)
:mSprite(sprite) {

}

void Npc::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform(); // getTransform() is defined by sf::Transformable
    target.draw(m_vertices, states);
}
