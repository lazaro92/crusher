#ifndef GAME_COMPONENT_HPP
#define GAME_COMPONENT_HPP

template<typename T, auto Type>
class Component
{
public:
    static constexpr auto type = static_cast<std::size_t>(Type);
};


// SEPARATE IN ANOTHER FILE

enum class ComponentType
{
    Position
};

struct Position: Component<Position, ComponentType::Position>
{
    float x;
    float y;
}


#endif // GAME_COMPONENT_HPP
