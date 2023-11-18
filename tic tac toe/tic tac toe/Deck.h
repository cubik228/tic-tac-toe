#pragma once
#include <vector>
#include <iostream>
#include "Player.h"
class Desk {
public:
    Desk() {
        for (int i = 0; i != 3; i++)
        {
            for (int j = 0; j != 3; j++) {
                arr[i][j] = 0;
            }
        }
    };
    void print_arr() {
        for (int i = 0; i != 3; i++)
        {
            for (int j = 0; j != 3; j++)
            {
                std::cout << arr[i][j];
            }
            std::cout << std::endl;
        }
    }
    void change_value_player(Player_ste_coord p) {
        if (p.x < 0 || p.y < 0 || p.x >= 3 || p.y >= 3) {
            return;
        }
        arr[p.x][p.y] = 1;
    }
    void change_value_computer() {
        for (int i = 0; i != 3; i++)
        {
            for (int g = 0; g != 3;g++) {
                if (arr[i][g] == 0) {
                    arr[i][g] = 2;
                    break;
                }
            }
            break;
        }
    }
    std::vector<std::vector<int>> arr{ 3, std::vector<int>(3, 0) };
};
