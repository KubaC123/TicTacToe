#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>

#define SIZE 4

//class Heh
//{
//    enum class Player
//    {
//        none = '-',
//        human = 'X',
//        computer = 'O'
//    };
//
//    struct Move
//    {
//        unsigned int x = 0;
//        unsigned int y = 0;
//    };
//
//    Player board[SIZE][SIZE];
//
//public:
//    Heh()
//    {
//        for (unsigned int i = 0; i < SIZE; i++)
//        {
//            for (unsigned int j = 0; j < SIZE; j++)
//            {
//                board[i][j] = Player::none;
//            }
//        }
//    }
//
//    void printBoard()
//    {
//        for (unsigned int i = 0; i < SIZE; i++)
//        {
//            std::cout << "\n|";
//            for (unsigned int j = 0; j < SIZE; j++)
//            {
//                std::cout << std::setw(3) << static_cast<char>(board[i][j]) << std::setw(3) << " |";
//            }
//        }
//        std::cout << "\n\n";
//    }
//
//    bool isTie()
//    {
//        bool isTie = true;
//        for (int i=0; i<SIZE; i++) {
//            for(int j=0; j<SIZE; j++)
//                if (board[i][j] != Player::none) isTie = false;
//        }
//        return isTie;
//    }
//
//    bool checkWin(Player player)
//    {
//        bool horizontalCheck = true, verticalCheck = true, firstDiagonal = true, secondDiagonal = true;
//        for (int i=0; i<SIZE; i++) {
//
//            for(int j=0; j<SIZE; j++)
//                if(board[i][j] != player) horizontalCheck = false;
//
//            for(int j=0; j<SIZE; j++)
//                if(board[j][i] != player) verticalCheck = false;
//
//            for(int i=0, j=0; i<SIZE; i++, j++)
//                if(board[i][j] != player) firstDiagonal = false;
//
//
//            for(int i=SIZE-1, j=0; j<SIZE; i--, j++)
//                if(board[i][j] != player) secondDiagonal = false;
//        }
//        return horizontalCheck || verticalCheck || firstDiagonal || secondDiagonal;
//    }
//
//    Move minimax()
//    {
//        int score = std::numeric_limits<int>::max();
//        Move move;
//
//        for (unsigned int i = 0; i < SIZE; i++)
//        {
//            for (unsigned int j = 0; j < SIZE; j++)
//            {
//                if (board[i][j] == Player::none)
//                {
//                    board[i][j] = Player::computer;
//
//                    int temp = maxSearch();
//
//                    if (temp < score)
//                    {
//                        score = temp;
//                        move.x = i;
//                        move.y = j;
//                    }
//                    board[i][j] = Player::none;
//                }
//            }
//        }
//
//        return move;
//    }
//
//    int maxSearch()
//    {
//        if (checkWin(Player::human)) { return 10; }
//        else if (checkWin(Player::computer)) { return -10; }
//        else if (isTie()) { return 0; }
//
//        int score = std::numeric_limits<int>::min();
//
//        for (unsigned int i = 0; i < SIZE; i++)
//        {
//            for (unsigned int j = 0; j < SIZE; j++)
//            {
//                if (board[i][j] == Player::none)
//                {
//                    board[i][j] = Player::human;
//                    score = std::max(score, minSearch());
//                    board[i][j] = Player::none;
//                }
//            }
//        }
//
//        return score;
//    }
//
//    int minSearch()
//    {
//        if (checkWin(Player::human)) { return 10; }
//        else if (checkWin(Player::computer)) { return -10; }
//        else if (isTie()) { return 0; }
//
//        int score = std::numeric_limits<int>::max();
//
//        for (unsigned int i = 0; i < SIZE; i++)
//        {
//            for (unsigned int j = 0; j < SIZE; j++)
//            {
//                if (board[i][j] == Player::none)
//                {
//                    board[i][j] = Player::computer;
//                    score = std::min(score, maxSearch());
//                    board[i][j] = Player::none;
//                }
//            }
//        }
//
//        return score;
//    }
//
//    void getHumanMove()
//    {
//        bool fail = true;
//        unsigned int x = -1, y = -1;
//
//        do
//        {
//            std::cout << "Your Move: ";
//
//            char c;
//            std::cin >> c;
//            x = c - '0';
//            std::cin >> c;
//            y = c - '0';
//
//            fail = board[x][y] != Player::none;
//
//            std::cin.clear();
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//        } while (fail);
//
//        board[x][y] = Player::human;
//    }
//
//    void play()
//    {
//        unsigned int turn = 0;
//        bool exit = false;
//
//        printBoard();
//        std::cout << "Enter your move in coordinate form[row, col]. ex: 02\n";
//
//        do
//        {
//            // human move
//            if (turn == 0)
//            {
//                getHumanMove();
//
//                if (checkWin(Player::human))
//                {
//                    std::cout << "Human Wins\n";
//                    exit = true;
//                }
//            }
//            else
//            {
//                std::cout << "\nComputer Move: ";
//
//                Move aimove = minimax();
//                std::cout << aimove.x << aimove.y << "\n";
//                board[aimove.x][aimove.y] = Player::computer;
//
//                if (checkWin(Player::computer))
//                {
//                    std::cout << "Computer Wins\n";
//                    exit = true;
//                }
//            }
//
//            if (isTie())
//            {
//                std::cout << "\n*** Tie ***\n";
//                exit = true;
//            }
//
//            turn ^= 1;
//            printBoard();
//
//        } while (!exit);
//    }
//};
//
//int main()
//{
//    Heh tictactoe;
//    tictactoe.play();
//    std::cin.ignore();
//}

#include "Game.hpp"

int main() {
    Game game(3);
    game.play();
    std::cin.ignore();
}
