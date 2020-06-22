//
// Created by maria on 21.06.2020.
//
#include <SFML/Graphics.hpp>

#ifndef SFMLAPP_HEAD_H
#define SFMLAPP_HEAD_H
#include <vector>
#include "body.h"
#include "Apple.h"
class Head {
public:
    int m_x;
    int m_y;
    std::vector<Body> m_body;
    std::vector<int> m_direction;
    sf::RectangleShape m_rect;
    Head(int x, int y);
    void Move();
    bool Eat(std::vector<Apple> &apples);
    void create_body();
    int last_x;
    int last_y;
};



#endif //SFMLAPP_HEAD_H
