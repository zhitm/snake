//
// Created by maria on 21.06.2020.
//

#ifndef SFMLAPP_BODY_H
#define SFMLAPP_BODY_H


class Body {
public:
    int m_x;
    int m_y;
    int m_next_x;
    int m_next_y;
    Body(int x, int y, int nx, int ny);
    void Move();
};


#endif //SFMLAPP_BODY_H
