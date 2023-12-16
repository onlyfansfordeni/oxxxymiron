#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Window
{
    int pos;

    sf::RenderWindow * window;
    sf::RectangleShape * shape;
    sf::Font * font;

    std::vector<const char *> options;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<std::size_t> sizes;

    protected:
        void set_values();
        void loop_events();
        void draw_all();

    public:
        Window();
        ~Window();
        void run_menu();
};