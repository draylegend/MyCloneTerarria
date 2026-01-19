#include <SFML/Graphics.hpp>
#include <iostream>
#include <player.h>
#include <config.h>
#include <Transform.h>
#include <TextureManager.h>
#include <utility>
#include <InputManager.h>


Player::Player(const Transform& transform, TextureManager& textureManager)
    : transform(transform),
      textureManager(textureManager) {}

void Player::init() {
    setTexture();
}

void Player::setTexture() {
    auto& texture = textureManager.get("player");
    sprite.setTexture(texture);
    auto size = texture.getSize();
    sprite.setScale(transform.size.x / size.x, transform.size.y / size.y);
    sprite.setPosition(transform.position.x, transform.position.y);

}

void Player::update(InputManager& input, float dt) {
    control(input);
    sprite.setPosition(transform.position.x, transform.position.y);

    transform.position.x += physics.velocity.x * dt;
    transform.position.y += physics.velocity.y * dt;
}

void Player::control(InputManager& input) {
    if (input.left) {physics.velocity.x = -0.001;}
    if (input.right) {physics.velocity.x = 0.001;}

}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}


const sf::Vector2f Player::getPosition() const{
    return sf::Vector2f(transform.position.x, transform.position.y);
}

void Player::setVelocityX(float newVelX) {
    physics.velocity.x = newVelX;
}

void Player::setVelocityY(float newVelY) {
    physics.velocity.y = newVelY;
}
