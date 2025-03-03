#include "sudoku.h"

int is_valid(int** board, int row, int col, int num) {
  for (int i = 0; i < BOARD_SIZE; ++i) {
    if (board[i][col] == num || board[row][i] == num) return 0;
  }

  int cell_row = (row / 3) * 3;
  int cell_col = (col / 3) * 3;

  for (int i = cell_row; i < cell_row + CELL_SIZE; ++i) {
    for (int j = cell_col; j < cell_col + CELL_SIZE; ++j) {
      if (board[i][j] == num) return 0;
    } 
  }

  return 1;
}

int solve_board(int** board) {
  int has_empty_square = 0;
  int empty_row, empty_col;

  for (int i = 0; i < BOARD_SIZE; ++i) {
    for (int j = 0; j < BOARD_SIZE; ++j) {
      if (board[i][j] == 0) {
        has_empty_square = 1;
        empty_row = i;
        empty_col = j;
        break;
      }
    }
    if (has_empty_square) break;
  }

  if (!has_empty_square) return 1;
  
  for (int num = 1; num <= 9; ++num) {
    if (is_valid(board, empty_row, empty_col, num)) {
      board[empty_row][empty_col] = num;
      if (solve_board(board)) return 1;
    }
    board[empty_row][empty_col] = 0;
  }

  return 0;
}