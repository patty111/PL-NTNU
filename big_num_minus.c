#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_num(char* num){
    int len = strlen(num);
    for (int i=0; i<floor(len/2); ++i){
        char tmp = num[i];
        num[i] = num[len-i-1];
        num[len-i-1] = tmp;
    }
}

int main(){
    
    return 0;
}