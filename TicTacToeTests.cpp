#include "TicTacToe.h"
#include <cassert>
#include <iostream>

void testPlaceMaker() {
    TicTacToe game;
    assert(game.placeMaker(0, 0) == true);
    assert(game.placeMaker(0, 0) == false);
}

void testWinCondition() {
    TicTacToe game;
    game.placeMaker(0, 0);
    game.placeMaker(1, 0);
    game.placeMaker(0, 1);
    game.placeMaker(1, 1);
    game.placeMaker(0, 2);
    assert(game.checkWin() == true);
}

int main() {
    testPlaceMaker();
    testWinCondition();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
