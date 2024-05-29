#include <stdio.h>
#include <stdlib.h>

char* toubinary(unsigned int num) {
    char* binary = malloc(33);

    binary[32] = '\0'; // Set the null terminator
    for (int i = 31; i >= 0; i--) {
        binary[i] = (num & 1) + '0'; // Check the least significant bit and convert to char
        num >>= 1; // Right shift the number by 1
    }

    return binary;
}

char* tosbinary(int num) {
    char* binary = (char*)malloc(33);

    unsigned int unum = (unsigned int)num; // Cast to unsigned to handle negative numbers
    binary[32] = '\0'; // Set the null terminator
    for (int i = 31; i >= 0; i--) {
        binary[i] = (unum & 1) + '0'; // Check the least significant bit and convert to char
        unum >>= 1; // Right shift the number by 1
    }
    return binary;
}