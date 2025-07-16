//
// Created by forna on 16.07.2025.
//

#ifndef TEXT_MANAGER_H
#define TEXT_MANAGER_H
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

class Text_Manager {
public:
    sf::RenderWindow window_;
    sf::Font font_;
    sf::Text info_text_;
    sf::Text instructions_text_;
    void SetupText(sf::Font font_, sf::Text info_text_, sf::Text instructions_text_);
};
#endif //TEXT_MANAGER_H
