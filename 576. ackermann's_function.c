#include <stdio.h>

int ackermann(int m, int n){
    if (m == 0) return n+1;
    if (m > 0 && n == 0) return ackermann(m-1, 1);
    else{
        int sub_ack = ackermann(m, n-1);
        return ackermann(m-1, sub_ack);
    }
}

int main(){
    int n, m;
    scanf("%d %d", &m, &n);

    int result = ackermann(m, n);
    printf("%d\n", result);
    return 0;
}