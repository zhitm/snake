#include <SFML/Graphics.hpp>
#include "head.h"
#include <vector>
#include <random>
#include <iostream>
#include "body.h"
#include "Apple.h"

float WINDOW_WIDTH = 1000;
float WINDOW_LENGTH = 1000;
std::vector<Apple> apples;


int rand(int a){
    std::random_device rd;
    std::mt19937 mersenne(rd());
    int x = mersenne()%a;
    std::cout<<x<<std::endl;

    return x;

}

void create_apple(){
    int x = rand(10);
    int y = rand(10);
    Apple apple(x, y);
    apples.push_back(apple);
}

int main()
{

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_LENGTH), "snake");
    Head head(5, 5);
    create_apple();
    sf::Clock clock;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                head.m_direction[0] = -1;
                head.m_direction[1] = 0;
                head.Move();
                clock.restart();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                head.m_direction[0] = 1;
                head.m_direction[1] = 0;
                head.Move();
                clock.restart();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                head.m_direction[0] = 0;
                head.m_direction[1] = -1;
                head.Move();
                clock.restart();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
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
        if (elapsed.asSeconds() >= 1.5)
        {
            head.Move();
            clock.restart();
        }
        window.clear();
        window.draw(head.m_rect);
        if (head.Eat(apples) == true) create_apple();
        for (int i = 0; i<apples.size(); i++)
        {
            window.draw(apples[i].m_circle);
        }
        
        window.display();

    }

    return 0;
}