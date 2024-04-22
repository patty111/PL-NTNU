#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary_str_consecutive_one_count(int n){
    int count = 0;
    int max_count = -1;
    for (int i=31; i>=0; --i){
        if (n & (1 << i)){
            count++;
            max_count = max_count > count ? max_count : count;
        }
        else
            count = 0;
    }
    return max_count;
}

int main(){
    int n;
    while (scanf("%d", &n) != EOF){
        printf("%d\n", binary_str_consecutive_one_count(n));
    }

    return 0;
}