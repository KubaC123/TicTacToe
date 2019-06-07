//
//  Board.hpp
//  TicTacToe
//
//  Created by Jakub Cichy on 04/06/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include "PlayerType.hpp"

class Board {
    int size;
    PlayerType **positions;
public:
    Board();
    Board(int size);
    ~Board();
    int getSize() const;
    PlayerType** getPositions() const;
    void update(int x, int y, PlayerType player);
    void clear();
    void show();
};

#endif /* Board_hpp */
