#pragma once

#include "entity.hpp"

namespace irondome
{
struct Interceptor : public Entity
{
    Interceptor();
    ~Interceptor() = default;

    void drawOnGrid(Grid &grid) override;

    EntityType type() override { return EntityType::INTERCEPTOR; }

    bool isStatic() { return false; }

};

}