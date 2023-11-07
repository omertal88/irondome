#include <iostream>
#include <random>
#include <memory>
#include <math.h>

#include "game.hpp"

#define DEG_TO_RAD(x)   (x * 0.0174533)

namespace irondome
{

Game::Game() 
{

    grid.addEntity(std::make_shared<irondome::Cannon>());
    grid.addEntity(std::make_shared<irondome::Pitcher>());
}

//============================================================================//

void Game::keyboardListener() 
{

    while (gameIsActive)
    {
        char c;
        c = getchar();
        isShotFired = true;
    }
}

//============================================================================//

void Game::play() 
{
    gameIsActive = true;

    std::chrono::steady_clock::time_point t0 = std::chrono::steady_clock::now();
    std::thread keyboardThread(&Game::keyboardListener, this);

    std::chrono::steady_clock::time_point lastTimeRefreshed = std::chrono::steady_clock::now();

    while (true)
    {
        if (isShotFired)
        {
            isShotFired = false;
            grid.addEntity(std::make_shared<irondome::Interceptor>());
            ++shotsFired;
        }

        if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - lastTimeRefreshed).count() > RENDER_FRAME_MS)
        {
            system("clear");
            grid.refresh();
            grid.draw();
            
            lastTimeRefreshed = std::chrono::steady_clock::now();
        }

        platesHit += grid.checkHits();

        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        auto gameTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - t0).count();
        if (gameTime > 60)
        {
            break;
        }
        else if (gameTime / 2 > platesFired)
        {
            spawnPlate();
            ++platesFired;
        }
    }

    std::cout << "Game over. Total hits: " << platesHit << ". Total shots fired: " << shotsFired << std::endl;
    std::cout << "Accuracy " << (float)platesHit /  shotsFired * 100 << "%" << std::endl;
    keyboardThread.join();
}

//============================================================================//

void Game::spawnPlate() 
{
    static constexpr int ANGLE = 120;

    int firePower = std::rand() % 15 + 30;
    Velocity velocity;
    velocity.x = std::cos(DEG_TO_RAD(ANGLE)) * firePower;
    velocity.y = std::sin(DEG_TO_RAD(ANGLE)) * firePower;
    grid.addEntity(std::make_shared<Plate>(velocity));
}

}