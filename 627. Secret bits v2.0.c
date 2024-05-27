#include <stdio.h>
#include "my_libs/include/print_binary.h"

int main(){
    unsigned int num;
    scanf("%u", &num);

    int n, k;

    n = num & 15;
    k = num >> 28;

    
    num = num << (32 - n - k) >> (32 - n - k) >> k;
    
    printubinary(num);
    printf("%u\n", num);
    return 0;
}
