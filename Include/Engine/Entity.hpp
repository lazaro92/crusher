#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP

#include <limits>

using Entity = std::uint32_t;
using Index  = std::uint32_t;

static constexpr auto InvalidIndex = std::numeric_limits<Index>::max();

#endif // GAME_ENTITY_HPP
