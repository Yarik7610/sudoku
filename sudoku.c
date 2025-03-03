#include "sudoku.h"
#include <stdio.h>

int main() {
  int **board = alloc_board();

  fill_unsolvable(board);

  if (solve_board(board)) printf("Solved sudoku!\nResult:\n");
  else printf("Can't solve sudoku\nUnsolved sudoku:\n");

  print_board(board);

  free_board(board);

  return 0;
}