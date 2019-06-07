//
//  Board.cpp
//  TicTacToe
//
//  Created by Jakub Cichy on 04/06/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#include "Board.hpp"
#include <iostream>
#include <iomanip>

Board::Board() : size(0), positions(nullptr) { }

Board::Board(int size) : size(size) {
    positions = new PlayerType*[size];
    for(int i=0; i<size; i++) {
        positions[i] = new PlayerType[size];
    }
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            positions[i][j] = PlayerType::NONE_PRESENT;
        }
    }
}

Board::~Board() {
    for(int i=0; i<size; ++i) {
        delete [] positions[i];
    }
    delete [] positions;
}

int Board::getSize() const {
    return size;
}

PlayerType** Board::getPositions() const {
    return positions;
}

void Board::update(int x, int y, PlayerType player) {
    positions[x][y] = player;
}

void Board::clear() {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            positions[i][j] = PlayerType::NONE_PRESENT;
        }
    }
}

void Board::show() {
    std::cout << std::setw(5) << "0" << std::setw(6) << "1" << std::setw(6) << "2";
    for (int i=0; i<size; i++) {
        std::cout << "\n" << i << "|";
        for (int j=0; j<size; j++) {
            std::cout << std::setw(3) << static_cast<char>(positions[i][j]) << std::setw(3) << " |";
        }
    }
    std::cout << std::endl << std::endl;
}
