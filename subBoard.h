#ifndef SUB_BOARD_H
#define SUB_BOARD_H

struct subBoard{
    private:
    int board[3][3];
    public:
    void set0();
    int checkWin();
    int setXY(int, int, int);
    int getXY(int, int);
};

#endif