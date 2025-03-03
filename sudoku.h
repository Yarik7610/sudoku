#ifndef SUDOKU_H
#define SUDOKU_H

#define BOARD_SIZE 9
#define CELL_SIZE 3

int** alloc_board(void);
void free_board(int** board);
 
void fill_solvable(int** board);
void fill_unsolvable(int** board);

void print_board(int** board);

#endif