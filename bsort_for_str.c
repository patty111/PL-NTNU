#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// bsort for string
void bsort(char w[][101], int n){
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if (strcmp(w[j],w[j+1]) > 0){
                char tmp[101] = {};
                strcpy(tmp,w[j]);
                strcpy(w[j],w[j+1]);
                strcpy(w[j+1],tmp);
            }
        }
    }
    return;
}