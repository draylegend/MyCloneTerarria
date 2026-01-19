#include <Background.h>
#include <TextureManager.h>
#include <SFML/Graphics.hpp>
#include <Transform.h>


Background::Background(const Transform& transform, TextureManager& tm) : transform(transform), textureManager(tm) {}

void Background::init() {
    setTexture();
}

void Background::setTexture() {
    auto& texture = textureManager.get("background");
    sprite.setTexture(texture);
    auto size = texture.getSize();
    sprite.setScale(transform.size.x / size.x, transform.size.y / size.y);
    sprite.setPosition(transform.position.x, transform.position.y);
}

void Background::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
