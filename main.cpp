
#include<iostream>
#include "subBoard.h"
#include "board.h"


int main(){
    Board game;

    std::string p1, p2;

    std::cout << "Enter Player 1:\n";
    std::cin >> p1;

    std::cout << "Enter Player 2:\n";
    std::cin >> p2;
    int move = 1;
    int xcor;
    int ycor;
    int subBoardSelectX;
    int subBoardSelectY;
    while(1){

        game.printBoard();

        if (move == 1){
            std::cout << p1 << "'s turn\n";  
        }
        else{
            std::cout << p2 << "'s turn\n";
        }

        subBoardSelectX = game.lastMoveX;
        subBoardSelectY = game.lastMoveY;
        label:
        if (subBoardSelectX == -1){

            std::cout << "Enter Board X\n";
            std::cin >> subBoardSelectX;
            std::cout << "Enter Board Y\n";
            std::cin >> subBoardSelectY;
        }

        std::cout << "Enter X Co-ordinate:\n";
        std::cin >> xcor;
        std::cout << "Enter Y Co-ordinate:\n";
        std::cin >> ycor;
        

        if (game.getXY(xcor, ycor, subBoardSelectX, subBoardSelectY) != 0)
        goto label;

        game.setXY(xcor, ycor, subBoardSelectX, subBoardSelectY, move);
        
        if (game.checkWinAbsolute()==2){
            std::cout<<"Game Drawn";
            break;
        }
        if(game.checkWinAbsolute()==1){
            std::cout<<p1<<"Wins";
            break;
        }
        if(game.checkWinAbsolute()==-1){
            std::cout<<p2<<"Wins";
            break;
        }
        move*=-1;
    }
}