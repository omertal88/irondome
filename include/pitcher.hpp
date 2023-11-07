#pragma once

#include "entity.hpp"

namespace irondome
{
struct Pitcher : public Entity
{
    Pitcher();
    ~Pitcher() = default;

    void drawOnGrid(Grid &grid) override;
    EntityType type() override { return EntityType::PITCHER; }
    bool isStatic() { return true; }
};

}