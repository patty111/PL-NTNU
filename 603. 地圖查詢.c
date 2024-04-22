#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node Node;
struct _Node {   
    int val;   
    int numAdjs;   
    struct _Node *adjacents[100]; 
};  

Node *array[100];  

int traverse(int a, int b, int* visited) {  
    if (visited[a]) return 0;
    if (array[a]->val == array[b]->val) return 1;
    if (array[a]->numAdjs == 0) return 0;
    visited[a] = 1;

    // printf("%d ", array[a]->val);

    for (int i=0; i<array[a]->numAdjs; ++i){
        if (traverse((array[a]->adjacents[i])->val, b, visited) == 1) return 1;
    }
    return 0;
} 

int main() {
    int v;
    scanf("%d", &v);

    int* visited = (int*)malloc(sizeof(int) * v);

    for (int i=0; i<v; ++i){
        array[i] = malloc(sizeof(Node));
        array[i]->val = i;
        visited[i] = 0;
    }

    for (int i=0; i<v; ++i){
        int adjs;
        scanf("%d", &adjs);
        array[i]->numAdjs = adjs;

        for (int j=0; j<adjs; ++j){
            int tmp;
            scanf("%d", &tmp);

            array[i]->adjacents[j] = array[tmp];
        }
    }

    int s;
    scanf("%d", &s);

    for (int i=0; i<s; ++i){
        for (int k=0; k<v; ++k) visited[k] = 0;
        int to, from;
        scanf("%d %d", &to, &from);
        // traverse(to, from, visited);
        printf("%d\n", traverse(to, from, visited));
    }
    return 0;
}