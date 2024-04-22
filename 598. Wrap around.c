#include <stdio.h>

void print_binary(unsigned int n){
    for (int i=31; i>=0; --i)
        printf("%d", (n & (1 << i)) >> i);
    
    printf("\n");
}

int main(){
    unsigned int x, n;

    scanf("%u %u", &x, &n);
    // print_binary(x);

    for (int i=0; i<n; ++i){
        unsigned int msb = (x & (1 << 31)) >> 31; // Get the most significant bit
        x <<= 1; // Shift left
        x |= msb;
        // printf("msb: %d ", msb);
        // print_binary(x);
    }

    printf("%u\n", x);
    return 0;
}