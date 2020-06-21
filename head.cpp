//
// Created by maria on 21.06.2020.

#include <iostream>
#include "head.h"
#include <SFML/Graphics.hpp>

Head::Head(int x, int y)
{
    m_x = x;
    m_y = y;
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(100, 100));
    rectangle.setPosition(m_x*100, m_y*100);
    m_rect = rectangle;
    m_direction = std::vector<int>(2, 0);


}
void Head::Move() {
    m_x += m_direction[0];
    m_y += m_direction[1];
    m_rect.setPosition(m_x*100, m_y*100);
}
bool Head::Eat(std::vector<Apple> &apples){
    for (int i = 0; i<apples.size(); i++){
        if (m_x == apples[i].m_x and m_y == apples[i].m_y)
        {
            apples.erase(apples.begin()+i);
            return true;
        }
    }
    return false;

}