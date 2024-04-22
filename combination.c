#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* nums;
int n;
void combination(int start, int* comb, int comb_len, int* nums, int target_length){
    if ((comb_len + n - start) < target_length) return;
    if (comb_len == target_length){
        for (int i=0; i<start; ++i){
            if (comb[i] != 0)
                printf("%d ", comb[i]);
        }
        printf("\n");
        return;
    }

    for (int i=start; i<n; ++i){
        comb[comb_len] = nums[i];
        combination(i+1, comb, comb_len+1, nums, target_length);
        comb[comb_len] = 0;
    }
}

int main(){
    scanf("%d", &n);

    nums = (int*)malloc(sizeof(int) * n);

    for (int i=0;i <n; ++i){
        scanf("%d", &nums[i]);
    }

    int* comb = (int*)malloc(sizeof(int) * n);
    for (int i=0; i<n; ++i) comb[i] = 0;
    
    // C n 取 2
    combination(0, comb, 0, nums, 2);
    

    // problem 602, 取一個, 取兩個 ... 到取n個
    // for (int i=1; i<=n; ++i){
    //     printf("------------\n");
    //     combination(0, comb, 0, nums, i);
    // }
    
    return 0;
}