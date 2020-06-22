#include <SFML/Graphics.hpp>
#include "head.h"
#include <vector>
#include <random>
#include <iostream>
#include "body.h"
#include "Apple.h"
#include "consts.h"


std::vector<Apple> apples;


int rand(int a){
    std::random_device rd;
    std::mt19937 mersenne(rd());
    int x = mersenne()%a;
    return x;

}

void create_apple(){
    int x = rand(FIELD_WIDTH);
    int y = rand(FIELD_LENGTH);
    Apple apple(x, y);
    apples.push_back(apple);
}

bool is_game_end(Head head)
{
    if (head.m_x < 0 || head.m_x >= FIELD_LENGTH || head.m_y < 0 || head.m_y >= FIELD_WIDTH) return true;
    for (int i = 0; i < head.m_body.size(); i++)
    {
        if (head.m_x == head.m_body[i].m_x & head.m_y == head.m_body[i].m_y) return true;

    }
    return false;
}

int main()
{
  /*  std::string path;
    path.resize(1024);

    auto ret = readlink("/proc/self/exe", &path[0], path.size()); // &path[0] - не const char*

    path.resize(ret);

    if (path.at(0) == 0)
    {
        std::cout << "Error" << std::endl;
        return -2;
    }

    std::cout << path << std::endl;*/
    sf::Image dead;
    dead.loadFromFile("../dead.png");
    sf::Texture end_of_game;
    end_of_game.loadFromImage(dead);
    sf::Sprite end_image;
    end_image.setScale(2,2);
    end_image.setTexture(end_of_game);
    end_image.setPosition(-670,-200);




    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_LENGTH), "snake");
    Head head(FIELD_WIDTH/2, FIELD_LENGTH/2);
    window.draw(head.m_rect);
    create_apple();
    sf::Clock clock;
    bool game_is_not_over = true;

        while (window.isOpen())
        {
            while (game_is_not_over)
            {

            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    head.m_direction[0] = -1;
                    head.m_direction[1] = 0;
                    head.Move();
                    clock.restart();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    head.m_direction[0] = 1;
                    head.m_direction[1] = 0;
                    head.Move();
                    clock.restart();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    head.m_direction[0] = 0;
                    head.m_direction[1] = -1;
                    head.Move();
                    clock.restart();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    head.m_direction[0] = 0;
                    head.m_direction[1] = 1;
                    head.Move();
                    clock.restart();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    head.m_direction[0] = 0;
                    head.m_direction[1] = 0;
                }
            }
            sf::Time elapsed = clock.getElapsedTime();
            if (elapsed.asSeconds() >= dT & not(head.m_direction[0] == 0 & head.m_direction[1] == 0)) {
                head.Move();
                clock.restart();
            }
            window.clear();
            window.draw(head.m_rect);
            if (head.Eat(apples) == true) {
                create_apple();
                head.create_body();


            }
            for (int i = 0; i < apples.size(); i++) {
                window.draw(apples[i].m_circle);
            }
            for (int j = 0; j < head.m_body.size(); j++) {
                window.draw(head.m_body[j].m_rect);
            }


            window.display();
            if (is_game_end(head) == true) game_is_not_over = false;
            }
            window.clear(sf::Color::Red);
            window.draw(end_image);
            window.display();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
    }
    return 0;
}
