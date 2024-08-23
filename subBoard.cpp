#include<iostream>
#include<cstring>
#include "subBoard.h"

int subBoard::checkWin()
{
    bool EmptyCount = false;
    // check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            if (board[i][0] != 0)
                return board[i][0];
        if (board[i][0] == 0)
            EmptyCount = true;
    }
    // check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            if (board[0][i] != 0)
                return board[0][i];
        if (board[0][i] == 0)
            EmptyCount = true;
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        if (board[0][0] != 0)
            return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        if (board[0][2] != 0)
            return board[0][2];

    if (EmptyCount)
        return 0;
    return 2;
}

void subBoard::set0(){
    memset(board, 0, sizeof board);
}


int subBoard::setXY(int x, int y, int val){
    board[x][y] = val;
    return 0;

}
int subBoard::getXY(int x, int y){
    return board[x][y];
}