#include "player.h"
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
