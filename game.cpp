#include "game.hpp"

Game::Game()
{


    set_values();
}

Game::~Game()
{

}

void Game::set_values()
{


    font->loadFromFile("BaedarRefular.otf");

    for (int i=0; i<2; i++)
    {
        linex[i].setOutlineThickness(0);
        liney[i].setOutlineThickness(0);
        linex[i].setSize(sf::Vector2f(1, 902));
        liney[i].setSize(sf::Vector2f(902, 1));
        linex[i].setPosition(300+301*i, 0);
        liney[i].setPosition(0, 300+301*i);
    }

}

void Game::draw_game()
{
    for (int i=0; i<2; i++)
    {
        window->draw(linex[i]);
        window->draw(liney[i]);
    }


}