//
// Created by maria on 21.06.2020.

#include <iostream>
#include "head.h"
#include <SFML/Graphics.hpp>
#include "consts.h"
#include "body.h"
Head::Head(int x, int y)
{
    m_x = x;
    m_y = y;
    last_x = x;
    last_y = y;
    sf::RectangleShape rectangle;
    m_rect = rectangle;
    m_rect.setSize(sf::Vector2f(WINDOW_LENGTH/FIELD_LENGTH, WINDOW_WIDTH/FIELD_WIDTH));
    m_rect.setPosition(m_x*WINDOW_LENGTH/FIELD_LENGTH, m_y*WINDOW_WIDTH/FIELD_WIDTH);

    m_direction = std::vector<int>(2, 0);


}
void Head::Move()
{
    if (m_body.empty() == false) {
        m_body.begin()->Move(m_x, m_y);
        for (int i = 1; i < m_body.size(); i++) {
            int new_x = m_body[i - 1].last_x;
            int new_y = m_body[i - 1].last_y;
            m_body[i].Move(new_x, new_y);
        }

    }

    last_x = m_x;
    last_y = m_y;
    m_x += m_direction[0];
    m_y += m_direction[1];

    m_rect.setPosition(m_x*WINDOW_LENGTH/FIELD_LENGTH, m_y*WINDOW_WIDTH/FIELD_WIDTH);
    std::cout <<m_body.size()<<std::endl;

}
bool Head::Eat(std::vector<Apple> &apples)
{
    for (int i = 0; i<apples.size(); i++){
        if (m_x == apples[i].m_x and m_y == apples[i].m_y)
        {
            apples.erase(apples.begin()+i);
            return true;
        }
    }
    return false;
}
void Head::create_body()
{
if (m_body.empty())
{
 Body body(last_x, last_y);
 m_body.push_back(body);
}
else
{
    Body body = m_body[m_body.size()-1];
    Body new_body(body.last_x, body.last_y);

    m_body.push_back(new_body);


}
}