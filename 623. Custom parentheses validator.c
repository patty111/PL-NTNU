#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, p;
    scanf("%d %d", &n, &p);
    char* str = (char*)malloc(21);

    scanf("%s", str);

    char lparan[21];
    char rparan[21];

    int len = 0;
    for (int i=0; i<p; ++i){
        char pair[3];
        scanf("%s", pair);
        lparan[len] = pair[0];
        rparan[len] = pair[1];
        len++;
    }

    char* stack = (char*)malloc(21);
    int top = 0;

    while (*str != '\0'){
        if (strchr(lparan, *str))
            stack[top++] = *str;
        
        if (strchr(rparan, *str)){
            int idx = strchr(rparan, *str) - rparan;
            char pop_val = stack[top-1];
            top--;

            if (pop_val != lparan[idx]){
                printf("false\n");
                return 0;
            }
        }
        
        str++;
    }
    
    printf("true\n");
    return 0;
}