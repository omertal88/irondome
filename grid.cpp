#include <iostream>
#include "grid.hpp"
#include "entity.hpp"
#include "cannon.hpp"

namespace irondome
{
Grid::Grid() 
{
}

//============================================================================//

void Grid::draw() 
{
    for (int i = GRID_ROWS - 1; i >= 0; --i)
    {
        for (int j = 0; j < GRID_COLUMNS; ++j)
        {
            std::cout << m_grid[i][j];
        }
        std::cout << std::endl;
    }
}

//============================================================================//

void Grid::refresh() 
{
    forEveryPixel([this](int row, int col)
    {
        m_grid[row][col] = ' ';
    });

    for (auto entity : m_entities)
    {
        entity->drawOnGrid(*this);
    }
}

//============================================================================//

bool Grid::drawPixel(uint16_t row, uint16_t col, char pixel) 
{
    if (row >= 0 && row < rows() && col >= 0 && col < columns() && pixel != ' ')
    {
        m_grid[row][col] = pixel;
        return true;
    }
    return false;
}

//============================================================================//

void Grid::forEveryPixel(std::function<void(int row, int col)> function) 
{
    for (int i = 0; i < GRID_ROWS; ++i)
    {
        for (int j = 0; j < GRID_COLUMNS; ++j)
        {
            function(i, j);
        }
    }
}

//============================================================================//

uint16_t Grid::checkHits() 
{
    std::list<std::shared_ptr<Entity>> entitiesToDelete;

    uint16_t hits = 0;
    for (auto interceptor : m_entities)
    {
        if (interceptor->type() == EntityType::INTERCEPTOR)
        {
            for (auto plate : m_entities)
            {
                if (plate->type() == EntityType::PLATE)
                {
                    if (intersects(interceptor, plate))
                    {
                        // Hit
                        entitiesToDelete.push_back(interceptor);
                        entitiesToDelete.push_back(plate);

                        ++hits;
                    }
                }
            }

        }
    }

    for (auto entity : entitiesToDelete)
    {
        m_entities.remove(entity);
    }

    return hits;
}

//============================================================================//

bool Grid::intersects(std::shared_ptr<Entity> first, std::shared_ptr<Entity> second) 
{
    BoundingBox bbox1 = first->boundingBox();
    BoundingBox bbox2 = second->boundingBox();

    return contains(bbox1, bbox2.p1) || 
           contains(bbox1, bbox2.p2) ||
           contains(bbox1, bbox2.lowerRight()) ||
           contains(bbox1, bbox2.upperLeft());
}

//============================================================================//

BoundingBox Entity::boundingBox() 
{
    BoundingBox bbox;
    bbox.p1 = pos();
    bbox.p2.x = pos().x + width - 1;
    bbox.p2.y = pos().y + height - 1;

    return bbox;
}

//============================================================================//

bool Grid::contains(BoundingBox bbox, Pos point)
{
    return (point.x >= bbox.p1.x && point.x <= bbox.p2.x &&
            point.y >= bbox.p1.y && point.y <= bbox.p2.y);
}

}