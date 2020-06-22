//
// Created by maria on 21.06.2020.
//
#include <vector>
#include "body.h"
#include "consts.h"

Body::Body(int x, int y)
{
    m_x = x;
    m_y = y;
    last_x = x;
    last_y = y;
    m_rect.setSize(sf::Vector2f(WINDOW_LENGTH/FIELD_LENGTH, WINDOW_WIDTH/FIELD_WIDTH));
    m_rect.setPosition(m_x*WINDOW_LENGTH/FIELD_LENGTH, m_y*WINDOW_WIDTH/FIELD_WIDTH);
    m_rect.setFillColor(sf::Color::Blue);

}
void Body::Move(int x, int y)
{
    last_x = m_x;
    last_y = m_y;
    m_x = x;
    m_y = y;
    m_rect.setPosition(m_x*WINDOW_LENGTH/FIELD_LENGTH, m_y*WINDOW_WIDTH/FIELD_WIDTH);

}