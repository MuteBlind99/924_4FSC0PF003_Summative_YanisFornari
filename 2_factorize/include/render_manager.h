//
// Created by forna on 16.07.2025.
//

#ifndef RENDER_H
#define RENDER_H
#include <SFML/Graphics/RenderWindow.hpp>

#include "game_sprite_manager.h"

class Render_Manager {
public:
    sf::RenderWindow window_;
    GameSpriteManager sprite_manager_;
    void Render(sf::RenderWindow window, const GameSpriteManager &sprite_manager_, sf::Text info_text_,sf::Text instructions_text_ );
};
#endif //RENDER_H
