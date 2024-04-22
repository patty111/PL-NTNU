#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Modified to use a provided buffer instead of allocating memory.
void to_binary_char(unsigned int num, char c1, char c0, char* bin) {
    for (int i = 31; i >= 0; i--) {
        bin[31-i] = (num & (1 << i)) ? c1 : c0;
    }
    bin[32] = '\0';
}

int main(){
    int w, h;
    char zero, one;
    unsigned int nums[1024]; 
    char bin_num[33];
    int idx = 0, totalBits;

    scanf("%d %d", &w, &h);
    scanf(" %c %c", &one, &zero); // Added a space before %c to skip any whitespace characters
    
    totalBits = w * h;
    
    while (scanf("%u", &nums[idx]) != EOF){
        idx++;
    }
    
    int bitPrinted = 0;
    for (int i = 0; i < idx; ++i) {
        to_binary_char(nums[i], one, zero, bin_num);
        for (int j = 0; j < 32 && bitPrinted < totalBits; ++j, ++bitPrinted) {
            if (bitPrinted > 0 && bitPrinted % w == 0) printf("\n"); // New line for each row
            printf("%c", bin_num[j]);
        }
    }
    
    printf("\n");

    return 0;
}