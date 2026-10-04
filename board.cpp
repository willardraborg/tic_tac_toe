#include "board.h"
#include <iostream>
using namespace std;

bool Board::set(int x, int y, Sign val) {
    if (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != Sign::Empty) {
        return false;
    }
    board[x][y] = val;
    return true;
}

void Board::print() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "  ";
            cout << symbol(board[i][j]);
        }
        cout << "  ";
        cout << '\n';
    }
}

bool Board::line_won(Sign a, Sign b, Sign c) {
    return a != Sign::Empty && a == b && b == c;
}
bool Board::check_row(int i) {
    return line_won(board[i][0], board[i][1], board[i][2]);
}
bool Board::check_col(int i) {
    return line_won(board[0][i], board[1][i], board[2][i]);
}
bool Board::check_diagonals() {
    return line_won(board[0][0], board[1][1], board[2][2]) ||
           line_won(board[0][2], board[1][1], board[2][0]);
}
bool Board::game_won() {
    for (int i = 0; i < 3; ++i) {
        if (check_row(i) || check_col(i)) {
            return true;
        }
    }
    return check_diagonals();
};
