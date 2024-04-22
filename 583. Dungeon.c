#include <stdio.h>

int in_maze(int row, int column, int n, int m)
{
  return(row >= 0 && row < n && 
	 column >= 0 && column < m);
}

int go_maze(int maze[100][100], int step, 
	    int current_row, int current_column, 
	    int end_row, int end_column, 
	    int n, int m)
{
  int drow[4] = {1, 0, -1, 0};
  int dcolumn[4] = {0, 1, 0, -1};
  int d;
  int next_row;
  int next_column;

  if ((current_row == end_row) && 
      (current_column == end_column))
    return 1;

  for (d = 0; d < 4; d++) {
    next_row = current_row + drow[d];
    next_column = current_column + dcolumn[d];
    if (in_maze(next_row, next_column, n, m) &&
	maze[next_row][next_column] == 0) {
      maze[next_row][next_column] = step;
      if (go_maze(maze, step + 1, next_row, 
		  next_column, end_row, 
		  end_column, n, m) == 1)
	return 1;
      maze[next_row][next_column] = 0;
    }
  }
  return 0;
}

int main(void)
{
  int n, m;
  int maze[100][100];
  int i, j;
  int start_row, start_column;
  int end_row, end_column;
  
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      scanf("%d", &(maze[i][j]));

  scanf("%d%d", &start_row, &start_column);
  scanf("%d%d", &end_row, &end_column);
  
  maze[start_row][start_column] = 1;
  go_maze(maze, 2, start_row, start_column, 
	  end_row, end_column, n, m);

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      printf("%2d ", maze[i][j]);
    printf("\n");
  }
  return 0;
}
