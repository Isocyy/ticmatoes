#include<iostream>
#include "subBoard.h"
#include "board.h"


void Board::setXY(int x, int y, int subBoardX, int subBoardY,  int val){
    board[subBoardX][subBoardY].setXY(x, y, val);
    lastMoveX = x;
    lastMoveY = y;

    if (board[x][y].checkWin() != 0)
    {
        lastMoveX = -1;
        lastMoveY = -1;
    }
}
int Board::getXY(int x, int y, int subBoardX, int subBoardY)
{   
    return board[subBoardX][subBoardY].getXY(x, y);
}

Board::Board(){
    lastMoveX = -1;
    lastMoveY = -1;
    
    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    board[i][j].set0();
}


void Board::printBoard(){
    int printBuffer[9][9];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            int rowCordinate = i*3;
            int colCordinate = j*3;
            for (int x = 0; x < 3; x++){
                for (int y = 0; y < 3; y++){
                    printBuffer[rowCordinate+x][colCordinate+y] = board[i][j].getXY(x,y);
                }
            }        
        }
    }
    std::cout << "\n=============================\n";
    for (int i = 0; i < 9; i++){
        std::cout << "|| ";
        for (int j = 0; j < 9; j++){
        int temp = printBuffer[i][j];
        
        if (temp == 0)
        std::cout << '.';//printBuffer[i][j];
        else if (temp == 1)
        std::cout << 'x';
        else
        std::cout << 'o';
        if(j%3==2){
            std::cout<< " || ";
        }
        else{
        std::cout<<' ';
        }
        }
        if (i % 3 == 2)
        std::cout << "\n=============================\n";
        else
        std::cout << "\n";
    }
}


int Board::checkWinAbsolute()
{
    int dp[3][3];
    int empty_counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = board[i][j].checkWin();
            if (dp[i][j] == 0)
            {
                empty_counter++;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (dp[i][0] == dp[i][1] && dp[i][1]== dp[i][2])
        {
            if (dp[i][0] != 0 && dp[i][0] != 2)
            {
                return dp[i][0];
            }
        }
    }
    for (int j = 0; j < 3; j++)
    {
        if (dp[0][j] == dp[1][j] && dp[1][j] == dp[2][j])
        {
            if (dp[0][j] != 0 && dp[0][j] != 2)
            {
                return dp[0][j];
            }
        }
    }
    if (board[0][0].checkWin() == board[1][1].checkWin() && board[1][1].checkWin()==board[2][2].checkWin())
    {
        if (board[0][0].checkWin() != 0 && board[0][0].checkWin() != 2)
        {
            return board[0][0].checkWin();
        }
    }
    if (board[0][2].checkWin() == board[1][1].checkWin() && board[1][1].checkWin()== board[2][0].checkWin())
    {
        if (board[0][0].checkWin() != 0 && board[0][0].checkWin() != 2)
        {
            return board[0][0].checkWin();
        }
    }
    if (empty_counter > 0)
    {
        return 0;
    }
    return 2;
}
