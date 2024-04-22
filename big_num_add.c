#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void reverse_num(char* num){
    int len = strlen(num);
    for (int i=0; i<floor(len/2); ++i){
        char tmp = num[i];
        num[i] = num[len-i-1];
        num[len-i-1] = tmp;
    }
}

char* bigN_add(char* n1, char* n2){
    char* result = (char*)malloc(102);
    reverse_num(n1);
    reverse_num(n2);

    int l1 = strlen(n1);
    int l2 = strlen(n2);
    int loops = l1 > l2 ? l1 : l2;

    int cf = 0;
    for (int i=0; i<loops; ++i){
        if (i >= l1)
            n1[i] = '0';
        if (i > l2)
            n2[i] = '0';
        
        int add = n1[i] - '0' + n2[i] - '0' + cf;
        cf = 0;

        if (add >= 10){
            cf = 1;
            add -= 10;
        }
        result[i] = add + '0';    // n1[i] - '0' + n2[i] - '0' + '0' to show as ascii char
    }

    if (cf == 1)
        result[loops] = '1';
    
    reverse_num(result);
    return result;
}

int main(){
    char n1[101];
    char n2[101];

    scanf("%s %s", n1, n2);
    printf("%s\n", bigN_add(n1, n2));

    

    return 0;
}
