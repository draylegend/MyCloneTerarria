#include <PhysicsSystem.h>
#include <player.h>
#include <Vector2.h>
#include <iostream>
#include <GameTime.h>


void PhysicsSystem::update(Player& player) {

    player.reduceVelocityX(friction);

    //auto playerPos = player.getPosition();
    //if (playerPos.y < 800) {
    //    player.reduceVelocityY(gravity * GameTime::deltaTimeSeconds);
    //}
}
