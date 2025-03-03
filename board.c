#include "sudoku.h"
#include <stdlib.h>
#include <stdio.h>
 
int** alloc_board() {
  int** board = (int**) malloc(BOARD_SIZE * sizeof(int*));

  for (int i = 0; i < BOARD_SIZE; ++i) {
    board[i] = (int*) malloc(BOARD_SIZE * sizeof(int));
  }

  return board;
}

void free_board(int** board) {
  for (int i = 0; i < BOARD_SIZE; ++i) {
    free(board[i]);
  }

  free(board);
}

void fill_solvable(int** board) {
  int solvable_board[BOARD_SIZE][BOARD_SIZE] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
  };

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
        board[i][j] = solvable_board[i][j];
    }
  }
}

void fill_unsolvable(int** board) {
 int unsolvable_board[BOARD_SIZE][BOARD_SIZE] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 5} 
  };

  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
        board[i][j] = unsolvable_board[i][j];
    }
  }
}

void print_board(int **board) {
  char hr[] = "-------------------------------";

  for (int i = 0; i < BOARD_SIZE; ++i) {
    if (i == 0) printf("%s\n", hr);

    printf("|");

    for (int j = 0; j < BOARD_SIZE; ++j) {
      printf(" %d ", board[i][j]);
      if ((j + 1) % CELL_SIZE == 0) printf("|");
    }

    printf("\n");

    if ((i + 1) % CELL_SIZE == 0) printf("%s\n", hr);
  }
}