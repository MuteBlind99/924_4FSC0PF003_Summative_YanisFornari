//
// Created by forna on 16.07.2025.
//
#include "render_manager.h"
void Render_Manager::Render(sf::RenderWindow window_, const GameSpriteManager &sprite_manager_, sf::Text info_text_,sf::Text instructions_text_ ) {
    window_.clear(sf::Color(30, 30, 50)); // Fond bleu foncé

    // Dessiner les sprites
    sprite_manager_.Draw(window_);

    // Dessiner l'interface
    window_.draw(info_text_);
    window_.draw(instructions_text_);

    window_.display();
}