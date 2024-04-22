#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    unsigned int num;
    int n = 0;
    scanf("%u", &num);

    unsigned int tmp = num;
    for (int i=0; i<4; ++i){
        n += (tmp & 1) * pow(2, i);
        tmp >>= 1;
    }
    
    int secret = 0;
    for (int i=4; i<=n+3; ++i){
        secret += (tmp & 1) * pow(2, i-4);
        tmp >>= 1;
    }

    printf("%d\n", secret);

    return 0;
}
