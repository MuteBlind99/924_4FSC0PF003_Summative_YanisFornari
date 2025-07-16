//
// Created by forna on 16.07.2025.
//

#ifndef KEY_MANAGER_H
#define KEY_MANAGER_H
#include <SFML/Graphics/RenderWindow.hpp>

#include "game_sprite_manager.h"

class KeyManager {
public:
    sf::RenderWindow window_;
    GameSpriteManager sprite_manager_;
    void KeyPress(sf::Keyboard::Key key);

};
#endif //KEY_MANAGER_H
