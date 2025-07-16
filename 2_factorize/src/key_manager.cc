#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "key_manager.h"

#include "game.h"
//
// Created by forna on 16.07.2025.
//

void KeyManager::KeyPress(const sf::Keyboard::Key key) {
    switch (key) {

        case sf::Keyboard::Key::Space:
            sprite_manager_.AddSpriteAtRandomPosition();
            break;

        case sf::Keyboard::Key::C:
            sprite_manager_.ClearAllSprites();
            std::cout << "Tous les sprites ont été effacés !" << std::endl;
            break;

        case sf::Keyboard::Key::Escape:
          window_.close();
            break;

        default:
            break;
    }
}
