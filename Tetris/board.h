#ifndef board_h_
#define board_h_

const int BOARD_WIDTH = 11; //in blocks
const int BOARD_HEIGHT = 21; //in blocks
const int POS_FREE = 0; 
const int POS_TAKEN = 1;
const int BORDER = 2;
const int MAGNIFICATION = 11;

extern int board[BOARD_WIDTH][BOARD_HEIGHT];

void drawBoard();
void initBoard();
void savePieceToBoard();

#endif