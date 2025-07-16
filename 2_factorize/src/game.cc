#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.h"

#include "key_manager.h"
#include "text_manager.h"

Game::Game() : window_(sf::VideoMode({1200, 800}), "Jeu de Sprites SFML", sf::Style::Close),
               sprite_manager_(window_.getSize()),
               info_text_(font_),
               instructions_text_(font_), key_manager_(), render_manager_(), event_manager_(), text_manager_() {
    window_.setFramerateLimit(60);

    // Chargement de la police (optionnel - utilise la police par défaut si échec)
    if (!font_.openFromFile("_assets/fonts/arial.ttf")) {
        std::cout << "Police arial.ttf non trouvée, utilisation de la police par défaut" << std::endl;
    }

    std::cout << "=== JEU DE SPRITES SFML ===" << std::endl;
    std::cout << "Contrôles :" << std::endl;
    std::cout << "- ESPACE : Ajouter un sprite à une position aléatoire" << std::endl;
    std::cout << "- CLIC GAUCHE : Ajouter un sprite à la position de la souris" << std::endl;
    std::cout << "- C : Effacer tous les sprites" << std::endl;
    std::cout << "- ÉCHAP : Quitter le jeu" << std::endl;
    std::cout << "================================" << std::endl;
}

void Game::Run() {
    text_manager_.SetupText(font_, info_text_,instructions_text_);

    while (window_.isOpen()) {
        event_manager_.HandleEvents();
        Update();
        Render();
    }
}

// void Game::SetupText() {
//     // Texte d'informations
//     info_text_.setFont(font_);
//     info_text_.setCharacterSize(20);
//     info_text_.setFillColor(sf::Color::White);
//     info_text_.setPosition({10, 10});
//
//     // Texte d'instructions
//     instructions_text_.setFont(font_);
//     instructions_text_.setCharacterSize(16);
//     instructions_text_.setFillColor(sf::Color::Yellow);
//     instructions_text_.setPosition({10, static_cast<float>(window_.getSize().y - 80)});
//     instructions_text_.setString(
//         "ESPACE: Sprite aléatoire | CLIC GAUCHE: Sprite à la souris | C: Effacer | S: Stats | ÉCHAP: Quitter");
// }


void Game::HandleKeyPress(const sf::Keyboard::Key key) {
    key_manager_.KeyPress(key);
}

void Game::Update() {
    const float deltaTime = clock_.restart().asSeconds();
    sprite_manager_.Update(deltaTime);
}

void Game::Render() {
    render_manager_.Render(std::move(window_), sprite_manager_, info_text_, instructions_text_);
}
