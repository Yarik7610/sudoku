#include "sudoku.h"

int main() {
  int **board = alloc_board();

  fill_solvable(board);

  print_board(board);

  free_board(board);

  return 0;
}