#pragma once

class Board;
class Player;
class Enemy;

class GameView {
    Board& board_;
    Player& player_;
    std::vector<Enemy*> enemies_;
    public:
    GameView(Board& b, Player& p, std::vector<Enemy*>& e);
    //here should be put all drawing functions ;)
};
