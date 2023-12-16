#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Game
{

    sf::RenderWindow * window;
    sf::Font * font;

    std::vector<sf::RectangleShape> linex;
    std::vector<sf::RectangleShape> liney;


    protected:
        void set_values();


    public:
        void draw_game();
        Game();
        ~Game();

};