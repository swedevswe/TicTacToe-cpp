#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe() {
    currentMarker = 'X';
    currentPlayer = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

bool TicTacToe::placeMaker(int row, int col) {
    if (board[row][col] != ' ') {
        return false;
    }
    board[row][col] = currentMarker;
    return true;
}

bool TicTacToe::checkWin() {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }
    return false;
}

void TicTacToe::switchPlayer() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
    } else {
        currentMarker = 'X';
    }
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

bool TicTacToe::boardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void TicTacToe::playGame() {
    int row, col;
    bool gameWon = false;

    while (!boardFull() && !gameWon) {
        std::cout << "Player " << currentPlayer << "'s turn. Enter row and column: ";
        std::cin >> row >> col;

        if (placeMaker(row, col)) {
            printBoard();
            gameWon = checkWin();
            if (gameWon) {
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            } else {
                switchPlayer();
            }
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    if (!gameWon) {
        std::cout << "It's a tie!" << std::endl;
    }
}

void TicTacToe::printBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "-----" << std::endl;
        }
    }
}
