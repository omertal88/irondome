#include "interceptor.hpp"

namespace irondome
{
Interceptor::Interceptor()
{
    trajectory.initialState.pos.x = 5;
    trajectory.initialState.pos.y = 3;
    trajectory.initialState.velocity.x = 150;
    trajectory.initialState.velocity.y = 40;

    width   = 2;
    height  = 2;
}

//============================================================================//

void Interceptor::drawOnGrid(Grid &grid)
{
    auto col = pos().x;
    auto row = pos().y;

    grid.drawPixel(row, col,   '*');
    grid.drawPixel(row, col+1, '*');

    grid.drawPixel(row+1, col  , '*');
    grid.drawPixel(row+1, col+1, '*');
}

}