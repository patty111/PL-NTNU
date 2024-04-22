#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int n, m;

// land: 1, sea: 0, searched: 2
int** MAP;

bool is_land(int x, int y){
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= m) return false;
    if (MAP[x][y] == 0 || MAP[x][y] == 2) return false; // Mark as searched
    return true;
}

void mark_visited(int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (MAP[x][y] == 1) MAP[x][y] = 2; // Mark as visited
}

int find_land_area(int x, int y, int area){
    mark_visited(x, y); // Mark current cell as visited
    area++; // Increment area for the current cell

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < 4; ++i){
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (is_land(newX, newY)){
            area = find_land_area(newX, newY, area); // Recursive call
        }
    }
    return area;
}

int main(){
    scanf("%d %d", &n, &m);

    MAP = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i)
        MAP[i] = (int*)malloc(sizeof(int) * m);

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            scanf("%d", &MAP[i][j]);
        }
    }
    
    int island_count = 0;
    int max_area = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (MAP[i][j] == 1){
                int tmp_area = find_land_area(i, j, 0);
                island_count++;
                max_area = (tmp_area > max_area) ? tmp_area : max_area;
            }
        }
    }

    printf("%d %d\n", island_count, max_area);

    return 0;
}
