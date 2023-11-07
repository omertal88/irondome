#pragma once

#include <functional>
#include <list>
#include <memory>

#include "config.hpp"
#include "trajectory.hpp"

namespace irondome
{

struct Entity;


struct BoundingBox
{
    Pos p1;
    Pos p2;

    Pos upperLeft() {
        Pos p;
        p.x = p1.x;
        p.y = p2.y;
        return p;
    }

    Pos lowerRight() {
        Pos p;
        p.x = p2.x;
        p.y = p1.y;
        return p;
    }
};

class Grid
{
public:
    Grid();
    ~Grid() = default;

    void draw();
    void refresh();

    uint16_t rows() { return GRID_ROWS; }
    uint16_t columns() { return GRID_COLUMNS; }

    bool drawPixel(uint16_t row, uint16_t col, char pixel);

    void addEntity(std::shared_ptr<Entity> entity) { m_entities.push_back(entity); }

    uint16_t checkHits();

private:
    void forEveryPixel(std::function<void(int row, int col)> function) ;

    char m_grid[GRID_ROWS][GRID_COLUMNS];

    std::list<std::shared_ptr<Entity>> m_entities;

    static bool intersects(std::shared_ptr<Entity> first, std::shared_ptr<Entity> second);

    static bool contains(BoundingBox bbox, Pos point);
};
}