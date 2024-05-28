#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int* toubinary(unsigned int num){
    int* tmp = (int*)malloc(sizeof(int)* 32);
    for(int i = 31; i >= 0; i--)
        tmp[31-i] = (num >> i) & 1;

    return tmp;
}

int main(){
    unsigned int a, b;
    scanf("%u %u", &a, &b);

    int* b_a = (int*)malloc(sizeof(32));
    int* b_b = (int*)malloc(sizeof(32));

    b_a = toubinary(a);
    b_b = toubinary(b);
    int count = 0;
    for (int i=0; i<32; ++i){
        if (b_a[i] != b_b[i])
            count++;
    }

    printf("%d\n",count);
    return 0;
}