#include <stdio.h>

void printubinary(unsigned int num){
    for(int i = 31; i >= 0; i--){
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

void printsbinary(int num){
    for(int i = 31; i >= 0; i--){
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}