#include "board.h"
#include "player.h"
#include "sign.h"
#include <iostream>

using namespace std;

int main() {
    Board board;
    HumanPlayer human(Sign::O);
    BotPlayer bot(Sign::X);
    Player *players[2] = {&human, &bot};
    int turn = 0;

    while (!board.game_won()) {
        board.print();
        Player *current = players[turn];
        Move m = current->choose_move(board);
        if (!board.set(m.row, m.col, current->sign)) {
            cout << "invalid move, try again" << '\n';
            continue;
        }
        turn = 1 - turn;
    }
    board.print();
    if (1 - turn) {
        cout << "bot won" << '\n';
    } else {
        cout << "you won" << '\n';
    }
}
