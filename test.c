// ======================================================================

#include <stdio.h>
#include <stdlib.h>
#include "test.h"

// ======================================================================

void print_maze(MAZE * maze)
{
  // maze->map[maze->here_r][maze->here_c] = '*';
  for(int i = 0; i < MAX_MAZE_SIZE; i++){
    for(int j = 0; j < MAX_MAZE_SIZE; j++){
      if((maze->here_r == i) && (maze->here_c == j)){
        printf("* ");
        continue;
      }
      printf("%c ", maze->map[i][j]);
    }
    printf("\n");
  }
}

// ======================================================================

void push_loc(MAZE * maze, int r, int c)
{
  if(r < 0 || c < 0) return;
  if(maze->map[r][c] != '1' && maze->map[r][c] != '2'){
    push_stack(maze->stack, r);
    push_stack(maze->stack, c);
    print_stack(maze->stack);
  }
}

// ======================================================================

int run_maze(MAZE * maze)
{
  int r, c;

  r = maze->here_r;
  c = maze->here_c;

  if(maze->map[r][c] == 'x')
    return FOUND;

  maze->map[r][c] = '2';
  push_loc(maze, r - 1, c);
  push_loc(maze, r, c + 1);
  push_loc(maze, r, c - 1);
  push_loc(maze, r + 1, c);

  if(empty_stack(maze->stack)){
    return FAILED;
  }
  else{
    maze->here_c = pop_stack(maze->stack);
    maze->here_r = pop_stack(maze->stack);
    return FINDING;
  }
}

// ======================================================================
