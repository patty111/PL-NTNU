#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* s1 = (char*)malloc(21);
    char* s2 = (char*)malloc(21);

    scanf("%s %s", s1, s2);

    for (int i=0; i<26; ++i) {
        for (int j=0; j<strlen(s1); ++j)
            s1[j] = (s1[j] - 'a' + 1) % 26 + 'a';

        if (strncmp(s1, s2, strlen(s1)) == 0) {
            printf("True\n");
            return 0;
        }
    }
    
    printf("False\n");
    return 0;
}