#include "player.h"
#include "board.h"
#include <iostream>
#include <string>

using namespace std;

Move HumanPlayer::choose_move(const Board &board) {
    string input;
    while (true) {
        cout << "enter move: row,col" << "\n";
        cin >> input;
        if (input.size() == 3 && input[1] == ',') {
            return Move{input[0] - '0', input[2] - '0'};
        }
        cout << "invalid input, try again" << "\n";
    }
}

Move BotPlayer::choose_move(const Board &board) {
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            if (board.get(r, c) == Sign::Empty) {
                return Move{r, c};
            }
        }
    }
    return Move{-1, -1};
}
