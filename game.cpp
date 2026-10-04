#include "board.h"
#include "player.h"
#include "sign.h"
#include <iostream>

using namespace std;

int main() {
    auto board = Board();
    HumanPlayer human(Sign::O);
    while (!board.game_won()) {
        board.print();
        Move m = human.choose_move(board);
        if (!board.set(m.row, m.col, human.sign)) {
            cout << "invalid move, try again" << '\n';
        }
    }
    board.print();
    cout << "game won" << '\n';
}
