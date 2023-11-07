#include "cannon.hpp"

namespace irondome
{
Cannon::Cannon()
{
    trajectory.initialState.pos.x = 0;
    trajectory.initialState.pos.y = 0;

    width    = 7;
    height   = 4;
}

//============================================================================//

void Cannon::drawOnGrid(Grid &grid)
{
    auto col = pos().x;
    auto row = pos().y;

    grid.drawPixel(row, col,   '|');
    grid.drawPixel(row, col+1, '_');
    grid.drawPixel(row, col+2, '_');
    grid.drawPixel(row, col+3, '_');
    grid.drawPixel(row, col+4, '_');
    grid.drawPixel(row, col+5, '_');
    grid.drawPixel(row, col+6, '|');

    grid.drawPixel(row+1, col  , ' ');
    grid.drawPixel(row+1, col+1, '/');
    grid.drawPixel(row+1, col+2, '_');
    grid.drawPixel(row+1, col+3, '_');
    grid.drawPixel(row+1, col+4, '_');
    grid.drawPixel(row+1, col+5, '\\');
    grid.drawPixel(row+1, col+6, ' ');

    grid.drawPixel(row+2, col  , ' ');
    grid.drawPixel(row+2, col+1, ' ');
    grid.drawPixel(row+2, col+2, '/');
    grid.drawPixel(row+2, col+3, '\\');
    grid.drawPixel(row+2, col+4, ' ');
    grid.drawPixel(row+2, col+5, '/');
    grid.drawPixel(row+2, col+6, ' ');

    grid.drawPixel(row+3, col  , ' ');
    grid.drawPixel(row+3, col+1, ' ');
    grid.drawPixel(row+3, col+2, ' ');
    grid.drawPixel(row+3, col+3, ' ');
    grid.drawPixel(row+3, col+4, ' ');
    grid.drawPixel(row+3, col+5, ' ');
    grid.drawPixel(row+3, col+6, '/');
}

}