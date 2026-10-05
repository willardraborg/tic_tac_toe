#pragma once
#include "sign.h"

class Board;

struct Move {
    int row, col;
};

class Player {
public:
    Player(Sign s) : sign(s) {}
    virtual ~Player() = default;
    virtual Move choose_move(const Board &board) = 0;
    Sign sign;
};

class HumanPlayer : public Player {
public:
    HumanPlayer(Sign s) : Player(s) {}
    Move choose_move(const Board &board) override;
};

class BotPlayer : public Player {
public:
    BotPlayer(Sign s) : Player(s) {}
    Move choose_move(const Board &board) override;
};
