//
// Created by maria on 21.06.2020.
//
#include <SFML/Graphics.hpp>
#include "Apple.h"
#include "consts.h"

Apple::Apple(int x, int y){
    m_x = x;
    m_y = y;
    m_circle.setRadius(WINDOW_LENGTH/FIELD_LENGTH/2.f);
    m_circle.setFillColor(sf::Color::Green);
    m_circle.setPosition(m_x*WINDOW_LENGTH/FIELD_LENGTH, m_y*WINDOW_WIDTH/FIELD_WIDTH);



}
