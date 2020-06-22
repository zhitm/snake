//
// Created by maria on 21.06.2020.
//
#include <SFML/Graphics.hpp>

#ifndef SFMLAPP_BODY_H
#define SFMLAPP_BODY_H


class Body {
public:
    int m_x;
    int m_y;
    int last_x;
    int last_y;
    sf::RectangleShape m_rect;

    Body(int x, int y);
    void Move(int x, int y);
};


#endif //SFMLAPP_BODY_H
