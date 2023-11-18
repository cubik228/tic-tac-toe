#pragma once

class Player_ste_coord {
public:
    void set_coord(int m_x, int m_y) {
        if (m_x < 0 || m_y < 0 || m_x >= 3 || m_y >= 3) {
            return;
        }
        x = m_x;
        y = m_y;
    }
    int x, y;
};

