#pragma once
#include "sign.h"

class Board {
private:
    Sign board[3][3] = {};

public:
    bool set(int x, int y, Sign val);
    void print();
    bool line_won(Sign a, Sign b, Sign c);
    bool check_row(int i);
    bool check_col(int i);
    bool check_diagonals();
    bool game_won();
    Sign get(int x, int y) const { return board[x][y]; }
};
