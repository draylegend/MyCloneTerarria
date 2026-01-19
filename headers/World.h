#pragma once

#include <player.h>
#include <config.h>
#include <Background.h>
#include <TextureManager.h>
#include <Camera.h>
#include <InputManager.h>


class World {

    TextureManager& textureManager;
    Player player;
    Background background;
    Camera camera;

public:
    explicit World(TextureManager& textureManager);
    void init();
    void update(InputManager& input, float dt);
    void render(sf::RenderWindow& window);
};
