#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
public:
    TicTacToe();
    void playGame();
    bool placeMaker(int row, int col); 
    bool checkWin(); 
    void printBoard();
    void switchPlayer();
    bool boardFull();
private:
    char board[3][3];
    char currentMarker;
    int currentPlayer;
};

#endif // TICTACTOE_H
