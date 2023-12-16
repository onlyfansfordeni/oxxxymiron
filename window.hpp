#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

enum class State
{
    GAME,
    AUTHORS,
    LEADERBOARD,
    EXIT
};

State currentState{State::EXIT};

class Window
{
    sf::RenderWindow * window;
    sf::RectangleShape * shape;
    sf::Font * font;

    std::vector<const char *> options;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<std::size_t> sizes;

    protected:
        // Pisya
        void set_values()
        {
            window ->create(sf::VideoMode(902, 902), "Hueta");
            window->setPosition(sf::Vector2i(0, 0));

            font->loadFromFile("BaedarRegular.otf");

            options = {"Play game", "Authors", "Leaderboard", "Exit"};
            texts.resize(4);
            coords = {{50, 150}, {50, 300}, {50, 450}, {50, 600}};
            sizes = {100, 100, 100, 100};

            for (std::size_t i{}; i<texts.size(); i++)
            {
                texts[i].setFont(*font);
                texts[i].setString(options[i]);
                texts[i].setCharacterSize(sizes[i]);
                texts[i].setFillColor(sf::Color::White);
                texts[i].setPosition(coords[i]);
            }


        }

        // Zalupa event
        void loop_events()
        {
            sf::Event event;
            while (window->pollEvent(event))
            {
                if (event.type==sf::Event::Closed)
                {
                    window->close();
                }

                for (int i=0; i<4; i++)
                {
                    if (event.mouseMove.x>=50 && event.mouseMove.x<=600 && event.mouseMove.y>=170+150*i && event.mouseMove.y<=270+150*i){
                        texts[i].setFillColor(sf::Color::Red);
                    }
                    else{
                        texts[i].setFillColor(sf::Color::White);
                    }
                }

                if (event.mouseMove.x>=50 && event.mouseMove.x<=600 && event.mouseMove.y>=170 && event.mouseMove.y<=270)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        currentState=State::GAME;
                        
                }

                if (event.mouseMove.x>=50 && event.mouseMove.x<=600 && event.mouseMove.y>=620 && event.mouseMove.y<=720)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        currentState=State::EXIT;
                }
            }
        }

        // Risovalka gamegovna
        void draw_game()
        {
            window->clear(sf::Color::Green);

            window->display();
        }

        // Risovka microsofta
        void draw_all()
        {
            window->clear(sf::Color::Cyan);

            sf::CircleShape shapehi(50);
            shapehi.setFillColor(sf::Color::Red);
            shapehi.setPosition(500, 200);
            sf::CircleShape shapeha(50);
            shapeha.setFillColor(sf::Color::Blue);

            for (const auto& t : texts)
            {
                window->draw(t);
            }

            switch (currentState)
            {
                case State::GAME:
                    window->draw(shapehi);
                    draw_game();
                    break;
                case State::EXIT:
                    window->draw(shapeha);
                    window->close();
                    break;
            }

            window->display();
        }

    public:
        Window(){
            window = new sf::RenderWindow();
            shape = new sf::RectangleShape();
            font = new sf::Font();

            set_values();
            std::cout<<"cheln";
        };

        ~Window(){
            delete window;
            delete shape;
            delete font;
        };

        void run_menu(){
            while (window->isOpen())
            {
                loop_events();
                draw_all();
            }
        }



    // protected:
    //     void set_values();
    //     void loop_events();
    //     void draw_all();

    // public:
    //     Window();
    //     ~Window();
    //     void run_menu();
    //     void draw_game();
};