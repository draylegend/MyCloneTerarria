#pragma once

#include <player.h>


class PhysicsSystem {

    const float gravity = 9.8;

    Player& player;

public:
    PhysicsSystem(Player& player);
    void update();
};
