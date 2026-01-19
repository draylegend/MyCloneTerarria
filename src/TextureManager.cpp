#include <TextureManager.h>
#include <SFML/Graphics.hpp>


void TextureManager::load(const std::string &id, const std::string &fileName) {

    auto& tex = textures[id];

    if (!tex.loadFromFile(fileName)) {
        throw std::runtime_error("Failed to load texture: " + fileName);
    }
}

const sf::Texture& TextureManager::get(const std::string &id) const {
    return textures.at(id);
}
