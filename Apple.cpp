//
// Created by maria on 21.06.2020.
//
#include <SFML/Graphics.hpp>
#include "Apple.h"

Apple::Apple(int x, int y){
    m_x = x;
    m_y = y;
    m_circle.setRadius(50.f);
    m_circle.setFillColor(sf::Color::Green);
    m_circle.setPosition(m_x*100, m_y*100);



}
