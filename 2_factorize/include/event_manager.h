//
// Created by forna on 16.07.2025.
//

#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "key_manager.h"

class Event_Manager {
public:
    KeyManager key_manager_;
    sf::RenderWindow window_;
    GameSpriteManager sprite_manager_;
    void HandleEvents();
    void HandleMousePressed(const sf::Event::MouseButtonPressed *mousePressed);
};
#endif //EVENT_MANAGER_H
