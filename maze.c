#include <stdio.h>
#include <stdlib.h>

#define N 50
#define UP '^'
#define DOWN 'v'
#define LEFT '<'
#define RIGHT '>'

int collect(char maze[][N], int m, int n){
    if (!(maze[m][n] == '.' || ((maze[m][n] - '0') >=0 && (maze[m][n] - '0') <=9))) return 0;
    int dx = {-1, 0, 1, 0};
    int dy = {0, 1, 0, -1};

    for (int i=0; i<4; ++i){
        int newM = 
    }
}


int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    char maze[N][N];
    fgets(maze[0], N, stdin);
    for (int i = 0; i < m; i++)
        fgets(maze[i], N, stdin);

    printf("Initial maze:\n");
    for (int i = 0; i < m; i++)
    {
        printf("%s", maze[i]);
    }

    collect(maze, m, n);

    printf("\nResult:\n");
    for (int i = 0; i < m; i++)
    {
        printf("%s", maze[i]);
    }

    return 0;
}