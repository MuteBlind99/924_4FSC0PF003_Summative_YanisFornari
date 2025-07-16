#include "event_manager.h"

#include <optional>
#include <SFML/Window/Event.hpp>

#include "key_manager.h"
//
// Created by forna on 16.07.2025.
//
void Event_Manager::HandleEvents() {
    while (const std::optional event = window_.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window_.close();
        }

        if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
           key_manager_.KeyPress(keyPressed->code);
        }

        if (const auto *mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
            HandleMousePressed(mousePressed);
        }
    }
}

void Event_Manager::HandleMousePressed(const sf::Event::MouseButtonPressed *mousePressed) {
    if (mousePressed->button == sf::Mouse::Button::Left) {
        sprite_manager_.AddSpriteAtMouse({
            static_cast<float>(mousePressed->position.x),
            static_cast<float>(mousePressed->position.y)
        });
    }
}
