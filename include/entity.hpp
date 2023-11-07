#pragma once

#include "config.hpp"
#include "grid.hpp"
#include "trajectory.hpp"

namespace irondome
{
enum EntityType
{
    NONE,
    PITCHER,
    CANNON,
    PLATE,
    INTERCEPTOR,
    EXPLOSION
};

struct Entity
{
    Trajectory trajectory;

    virtual EntityType type() { return EntityType::NONE; }

    Pos pos();

    uint16_t width = 0;
    uint16_t height = 0;
    
    BoundingBox boundingBox();
    virtual bool isStatic() = 0;
    
    // virtual const char **getShape();
    // bool validateAndDrawOnGrid(Grid &grid, uint16_t row, uint16_t col);


public:
    virtual void drawOnGrid(Grid &grid) = 0;
};
}