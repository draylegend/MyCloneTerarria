#pragma once

#include <SFML/Graphics.hpp>
#include <Transform.h>
#include <TextureManager.h>


class Background {
    Transform transform;
    TextureManager& textureManager;
    sf::Sprite sprite;

public:
    Background(const Transform& transform, TextureManager& textureManager);
    void init();
    void setTexture();
    void draw(sf::RenderWindow& window);
};
