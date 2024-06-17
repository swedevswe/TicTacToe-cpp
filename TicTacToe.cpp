#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe() : currentMarker('X'), currentPlayer(1){
    for(int i = 0; i<3; i++)
        for(int j = 0; j<3; j++)
            board[i][j] = ' ';
}

void TicTacToe::playGame(){
    int row, col;
    bool gameWon = false;
    bool gameTied = false;

    while (!gameWon && !gameTied)
    {
        printBoard();
        std::cout << "Player" << currentPlayer << "'s turn. Enter row and column: ";
        std::cin >> row >> col;

        if(placeMaker(row, col)){
            gameWon = checkWin();
            gameTied = checkTie();
            if(!gameWon && !gameTied) switchPlayer();
        }else{
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }
    printBoard();
    if(gameWon){
        std::cout << "Player " << currentPlayer << " wins!" << std::endl;
    }else if(gameTied) {
        std::cout << "It's a tie!" << std::endl;
    }
}

void TicTacToe::printBoard(){
    std::cout << "  0 1 2\n";
    for(int i = 0; i<3; i++){
        std::cout << i << " ";
        for(int j = 0; j<3; j++){
            std::cout << board[i][j];
            if(j<2) std::cout << "|";
        }
        std::cout << std::endl;
        if(i<2) std::cout << "  -----\n";
    }
}
bool TicTacToe::placeMaker(int row, int col){
    if(row>=0 && row<3 && col>=0 && col<3 && board[row][col] == ' '){
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}
bool TicTacToe::checkWin(){
    for(int i = 0; i<3; i++){
        if(board[i][0] == currentMarker && board[i][1] == currentMarker && board[i][2] == currentMarker) return true;
        if(board[0][i] == currentMarker && board[1][i] == currentMarker && board[2][i] == currentMarker) return true;
    }
    if(board[0][0] == currentMarker && board[1][1] == currentMarker && board[2][2] == currentMarker) return true;
    if(board[0][2] == currentMarker && board[1][1] == currentMarker && board[2][0] == currentMarker) return true;
    return false;
}
bool TicTacToe::checkTie(){
    for(int i = 0; i<3; i++)
        for(int j = 0; j<3; j++)
            if(board[i][j] == ' ') return false;
    return true;
}

void TicTacToe::switchPlayer(){
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMarker = (currentMarker == 'X') ? '0' : 'X';
}

