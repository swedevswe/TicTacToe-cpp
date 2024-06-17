#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
public:
    TicTacToe();
    void playGame();

private:
    char board[3][3];
    char currentMarker;
    int currentPlayer;

    void printBoard();
    bool placeMaker(int row, int col);
    bool checkWin();
    bool checkTie();
    void switchPlayer();
};

#endif //TICTACTOE_H
