#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* s1 = (char*)malloc(102);
    char* s2 = (char*)malloc(102);

    scanf("%s %s", s1, s2);

    char* new_s1 = (char*)malloc(102);
    char* new_s2 = (char*)malloc(102);
    int top = 0;

    while (*s1 != '\0') {
        if (top > 0 && *s1 == '#') {
            // pop
            new_s1[top-1] = '\0';
            top--;
            s1++;
            continue;
        }

        if (*s1 == '#'){
            s1++;
            continue;
        }
        new_s1[top++] = *s1;
        s1++;
    }

    top = 0;
    while (*s2 != '\0') {
        if (top > 0 && *s2 == '#') {
            // pop
            new_s2[top-1] = '\0';
            top--;
            s2++;
            continue;
        }

        if (*s2 == '#') {
            s2++;
            continue;
        }
        new_s2[top++] = *s2;
        s2++;
    }

    if (strncmp(new_s1, new_s2, 102) == 0)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}