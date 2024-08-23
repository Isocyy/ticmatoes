#ifndef BOARD_H
#define BOARD_H

#include "subBoard.h"

struct Board{
    struct subBoard board[3][3];
    int lastMoveX;
    int lastMoveY;

    Board();

    //int LegalSub(); // 0 if all board, 1-9 corresponding to subboard
    int checkWinAbsolute(); // 1 if player 1, -1 if -1, 0 if game continue, 2 if draw
    int getXY(int x, int y, int subBoardX, int subBoardY);
    void setXY(int x, int y, int subBoardX, int subBoardY,  int val);
    void printBoard();
};


#endif