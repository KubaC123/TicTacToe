//
//  Game.hpp
//  TicTacToe
//
//  Created by Jakub Cichy on 04/06/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "Board.hpp"

struct Move { int x, y; };

class Game {
    Board *board;
public:
    Game(int boardSize);
    ~Game();
    bool isTie();
    bool checkWin(PlayerType player);
    Move minimax();
    int maxSearch();
    int minSearch();
    void getPlayerMove();
    void playSingleRound();
    void play();
};

#endif /* Game_hpp */
