#pragma once

#include <iostream>
#include <thread>

#include "grid.hpp"
#include "cannon.hpp"
#include "pitcher.hpp"
#include "plate.hpp"
#include "interceptor.hpp"


namespace irondome
{
struct Game
{
    Game();
    ~Game() = default;

    void play();
    void keyboardListener();
    Grid grid;

    void spawnPlate();

    bool isShotFired = false;
    bool gameIsActive = false;

    // Statistics
    uint16_t platesFired = 0;
    uint16_t platesHit   = 0;
    uint16_t shotsFired  = 0;
};

}