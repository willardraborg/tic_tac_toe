#include "sign.h"
#include <iostream>
#include <string>
using namespace std;

class Board {
private:
    Sign board[3][3] = {};

public:
    bool set(int x, int y, Sign val) {
        if (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != Sign::Empty) {
            return false;
        }
        board[x][y] = val;
        return true;
    }
    void print() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << "  ";
                cout << symbol(board[i][j]);
            }
            cout << "  ";
            cout << '\n';
        }
    }
    bool line_won(Sign a, Sign b, Sign c) {
        return a != Sign::Empty && a == b && b == c;
    }
    bool check_row(int i) {
        return line_won(board[i][0], board[i][1], board[i][2]);
    }
    bool check_col(int i) {
        return line_won(board[0][i], board[1][i], board[2][i]);
    }
    bool check_diagonals() {
        return line_won(board[0][0], board[1][1], board[2][2]) ||
               line_won(board[0][2], board[1][1], board[2][0]);
    }
    bool game_won() {
        for (int i = 0; i < 3; ++i) {
            if (check_row(i) || check_col(i)) {
                return true;
            }
        }
        return check_diagonals();
    }
};

class Player {
public:
    Sign sign;

    Player(Sign s) { sign = s; }

    bool make_play(int x, int y, Board &board) { return board.set(x, y, sign); }
};

void move(Board &board) {
    string input;
    while (true) {
        cout << "enter move: x,y" << '\n';
        cin >> input;
        if (input.size() == 3 && input[1] == ',' &&
            board.set(input[0] - '0', input[2] - '0', Sign::O)) {
            return;
        }
        cout << "invalid move, try again" << '\n';
    }
}

int main() {
    auto board = Board();
    while (!board.game_won()) {
        board.print();
        move(board);
    }
    board.print();
    cout << "game won" << '\n';
}
