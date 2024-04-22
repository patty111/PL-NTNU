#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* nums;

void permute(int depth, int max_depth, int* current_permutation){
    if (depth == max_depth){
        for (int i=0; i<depth; ++i){
            printf("%d ",current_permutation[i]);
        }
        printf("\n");
        return;
    }

    for (int i=0; i<max_depth; ++i){
        current_permutation[depth] = nums[i];
        permute(depth+1, max_depth, current_permutation);
        current_permutation[depth] = 0;
    }

}

int main(){
    int n;
    scanf("%d", &n);

    nums = (int*)malloc(sizeof(int) * n);
    int* result = (int*)malloc(sizeof(int) * n);
    for(int i=0; i<n; ++i)
        scanf("%d", &nums[i]);

    permute(0, n, result);
    
    return 0;
}