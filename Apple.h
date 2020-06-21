//
// Created by maria on 21.06.2020.
//
#include <SFML/Graphics.hpp>

#ifndef SFMLAPP_APPLE_H
#define SFMLAPP_APPLE_H


class Apple {
public:
    int m_x;
    int m_y;

    sf::CircleShape m_circle;

    Apple(int x, int y);

};


#endif //SFMLAPP_APPLE_H
