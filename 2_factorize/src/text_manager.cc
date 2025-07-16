//
// Created by forna on 16.07.2025.
//
#include "text_manager.h"

#include <SFML/Graphics/Color.hpp>

void SetupText(sf::Font font_, sf::Text info_text_, sf::Text instructions_text_) {
    sf::RenderWindow window_;
    // Texte d'informations
    info_text_.setFont(font_);
    info_text_.setCharacterSize(20);
    info_text_.setFillColor(sf::Color::White);
    info_text_.setPosition({10, 10});

    // Texte d'instructions
    instructions_text_.setFont(font_);
    instructions_text_.setCharacterSize(16);
    instructions_text_.setFillColor(sf::Color::Yellow);
    instructions_text_.setPosition({10, static_cast<float>(window_.getSize().y - 80)});
    instructions_text_.setString(
        "ESPACE: Sprite aléatoire | CLIC GAUCHE: Sprite à la souris | C: Effacer | S: Stats | ÉCHAP: Quitter");
}
