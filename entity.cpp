#include "entity.hpp"

namespace irondome
{

Pos Entity::pos() 
{
    if (isStatic())
    {
        return trajectory.initialState.pos;
    }
    else
    {
        return trajectory.calculatePosition();
    }
}

}