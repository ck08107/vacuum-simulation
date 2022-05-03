// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "test.h"

// ======================================================================

char map1[MAX_MAZE_SIZE][MAX_MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1', '1'},
    {'1', '0', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '0', '1', '1', '1'},
    {'1', '0', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '1', '1'}
};

// ======================================================================


int main(void)
{
  int r, step = 1;
  MAZE maze1;

  maze1.map = map1;
  maze1.stack = malloc(sizeof(STACK));
  init_stack(maze1.stack);
  maze1.here_r = 5;
  maze1.here_c = 5;

  for (;;) {
    printf("== step %d ==\n", step++);
    print_maze(&maze1);
    getchar();

    r = run_maze(&maze1);
    if (r == FAILED) {
      printf("FAILED!\n");
      break;
    }
    if (r == FOUND) {
      printf("FOUND!\n");
      break;
    }
  }

  return EXIT_SUCCESS;
}

// ======================================================================
