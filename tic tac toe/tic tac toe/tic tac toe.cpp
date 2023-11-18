#include <iostream>
#include <vector>
#include "Player.h"
#include "Deck.h"

class Game : public Desk, public Player_ste_coord {
public:
    bool result_win_player();
    bool result_win_computer();
    void check_win();
    friend std::istream& operator>>(std::istream& in, Game& g); 
    void proces_game() {
        while (end_or_contity) {
            print_arr();
            std::cin >> *this;
            p.set_coord(x, y);
            change_value_player(p);
            change_value_computer();
            check_win();
        }
    }
private:
    int x, y;
    bool end_or_contity = true;
    Player_ste_coord p;
    bool is_tie = true;
};
std::istream& operator>>(std::istream& in, Game& g) {
    std::cout << "Enter the coordinates of the cross\n";
    std::cout << "x = ";
    in >> g.x;
    std::cout << "\ny = ";
    in >> g.y;
    return in;
}
bool Game::result_win_computer() {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == 2 && arr[i][1] == 2 && arr[i][2] == 2) {
            return true;
        }
        if (arr[0][i] == 2 && arr[1][i] == 2 && arr[2][i] == 2) {
            return true;
        }
        if (arr[0][0] == 2 && arr[1][1] == 2 && arr[2][2] == 2) {
            return true;
        }
        if (arr[0][2] == 2 && arr[1][1] == 2 && arr[2][0] == 2) {
            return true;
        }
    }
    return false;
}
bool Game::result_win_player() {
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == 1 && arr[i][1] == 1 && arr[i][2] == 1) {
            return true;
        }
        if (arr[0][i] == 1 && arr[1][i] == 1 && arr[2][i] == 1) {
            return true;
        }
        if (arr[0][0] == 1 && arr[1][1] == 1 && arr[2][2] == 1) {
            return true;
        }
        if (arr[0][2] == 1 && arr[1][1] == 1 && arr[2][0] == 1) {
            return true;
        }
    }
    return false;
}
void Game::check_win() {
    if (result_win_player()) {
        std::cout << "Player wins!" << std::endl;
        end_or_contity = false;
    }
    else if (result_win_computer()) {
        std::cout << "Computer wins!" << std::endl;
        end_or_contity = false;
    }
}

int main() {
    Game g;
    g.proces_game();
}