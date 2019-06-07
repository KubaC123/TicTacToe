//
//  Game.cpp
//  TicTacToe
//
//  Created by Jakub Cichy on 04/06/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#include "Game.hpp"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <limits>

Game::Game(int boardSize) {
    board = new Board(boardSize);
}

Game::~Game() {
    delete board;
    std::cout << "Bye Bye" << std::endl;
}

bool Game::isTie() {
    for (int i=0; i<board->getSize(); i++) {
        if (board->getPositions()[i][0] == PlayerType::NONE_PRESENT || board->getPositions()[i][1] == PlayerType::NONE_PRESENT || board->getPositions()[i][2] == PlayerType::NONE_PRESENT)
            return false;
    }
    return true;
}

bool Game::checkWin(PlayerType player) {
    for (int i=0; i<board->getSize(); i++) {
        if (board->getPositions()[i][0] == player && board->getPositions()[i][1] == player && board->getPositions()[i][2] == player)
            return true;
        if (board->getPositions()[0][i] == player && board->getPositions()[1][i] == player && board->getPositions()[2][i] == player)
            return true;
    }
    if (board->getPositions()[0][0] == player && board->getPositions()[1][1] == player && board->getPositions()[2][2] == player)
        return true;
    if (board->getPositions()[0][2] == player && board->getPositions()[1][1] == player && board->getPositions()[2][0] == player)
        return true;
    return false;
}

Move Game::minimax() {
    int score = std::numeric_limits<int>::max();
    Move move;
    for (int i=0; i<board->getSize(); i++) {
        for (int j=0; j<board->getSize(); j++) {
            if (board->getPositions()[i][j] == PlayerType::NONE_PRESENT) {
                board->update(i, j, PlayerType::COMPUTER);
                int temp = maxSearch();
                if (temp < score) {
                    score = temp;
                    move.x = i;
                    move.y = j;
                }
                board->update(i, j, PlayerType::NONE_PRESENT);
            }
        }
    }
    return move;
}

int Game::maxSearch() {
    if (checkWin(PlayerType::HUMAN)) return 10;
    else if (checkWin(PlayerType::COMPUTER)) return -10;
    else if (isTie()) return 0;
    int score = std::numeric_limits<int>::min();
    for (int i=0; i<board->getSize(); i++) {
        for (int j=0; j<board->getSize(); j++) {
            if (board->getPositions()[i][j] == PlayerType::NONE_PRESENT) {
                board->update(i, j, PlayerType::HUMAN);
                score = std::max(score, minSearch());
                board->update(i, j, PlayerType::NONE_PRESENT);
            }
        }
    }
    return score;
}

int Game::minSearch() {
    if (checkWin(PlayerType::HUMAN)) return 10;
    else if (checkWin(PlayerType::COMPUTER)) return -10;
    else if (isTie()) return 0;
    int score = std::numeric_limits<int>::max();
    for (int i=0; i<board->getSize(); i++) {
        for (int j=0; j<board->getSize(); j++) {
            if (board->getPositions()[i][j] == PlayerType::NONE_PRESENT) {
                board->update(i, j, PlayerType::COMPUTER);
                score = std::min(score, maxSearch());
                board->update(i, j, PlayerType::NONE_PRESENT);
            }
        }
    }
    return score;
}

void Game::getPlayerMove() {
    bool fail = true;
    unsigned int x = -1, y = -1;
    do
    {
        std::cout << "Twoj ruch: ";
        char c;
        std::cin >> c;
        x = c - '0';
        std::cin >> c;
        y = c - '0';
        fail = board->getPositions()[x][y] != PlayerType::NONE_PRESENT;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    } while (fail);
    
    board->update(x, y, PlayerType::HUMAN);
}

void Game::playSingleRound() {
    int win = 0;
    int loss = 0;
    int draw = 0;
    unsigned int turn = 0;
    bool exit = false;
    do {
        if (turn == 0) {
            getPlayerMove();
            if (checkWin(PlayerType::HUMAN)) {
                std::cout << "WYGRALES!\n";
                win++;
                exit = true;
            }
        } else {
            std::cout << "\nKomputer: ";
            Move aimove = minimax();
            std::cout << aimove.x << aimove.y << "\n";
            board->update(aimove.x, aimove.y, PlayerType::COMPUTER);
            if (checkWin(PlayerType::COMPUTER)) {
                std::cout << "PRZEGRALES :(\n";
                loss++;
                exit = true;
            }
        } if (isTie()) {
            std::cout << "\nREMIS\n";
            draw++;
            exit = true;
        }
        turn ^= 1;
        board->show();
    } while (!exit);
    board->clear();
    std::cout << "---------------" << std::endl;
    std::cout << "Wygrane     " << win << std::endl;
    std::cout << "Przegrane   " << loss << std::endl;
    std::cout << "Remisy      " << draw << std::endl;
    std::cout << "NASTEPNA RUNDA" << std::endl;
    std::cout << "---------------" << std::endl;
    board->show();
}

void Game::play() {
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Kolko i krzyzyk" << std::endl;
    std::cout << "Swoje ruchy podawaj w postaci dwoch cyfr (rzad+kolumna) np. 01" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl << std::endl  ;
    board->show();
    while(1) {
        playSingleRound();
    }
}
