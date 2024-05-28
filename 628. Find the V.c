#include <stdio.h>
#include <stdlib.h>

int* nums;
int n;
int count = 0;

void combination(int start, int* comb, int comb_len, int* nums, int target_length){
    if ((comb_len + n - start) < target_length) return;
    if (comb_len == target_length){
        if (comb[0] > comb[1] && comb[1] < comb[2])
            count++;
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

    for (int i=0;i <n; ++i)
        scanf("%d", &nums[i]);

    int* comb = (int*)malloc(sizeof(int) * n);
    for (int i=0; i<n; ++i) comb[i] = 0;
    
    combination(0, comb, 0, nums, 3);
    printf("%d\n", count);
    return 0;
}