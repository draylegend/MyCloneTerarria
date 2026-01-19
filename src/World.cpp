#include <World.h>
#include <SFML/Graphics.hpp>
#include <TextureManager.h>
#include <player.h>
#include <Transform.h>
#include <config.h>
#include <InputManager.h>


World::World(TextureManager& textureManager)
    : textureManager(textureManager),
    player(Transform{{100.f, 200.f}, {50.f, 65.f}}, textureManager),
    background(Transform{{0.f, 0.f}, {Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT}}, textureManager),
    camera(sf::Vector2f(Config::SCREEN_WIDTH/2, Config::SCREEN_HEIGHT/2), sf::Vector2f(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT)){}

void World::init() {
    player.init();
    background.init();
}

void World::update(InputManager& input, float dt) {
    player.update(input, dt);
    camera.update(player.getPosition());
}


void World::render(sf::RenderWindow& window) {
    //window.setView(window.getDefaultView());
    background.draw(window);
    window.setView(camera.getView());
    player.draw(window);
}
