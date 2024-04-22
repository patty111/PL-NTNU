#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_wordmap(char** strmap, int row, int col){
    for (int i=0; i<row; ++i){
        for (int j=0; j<col; ++j){
            if (isalpha(strmap[i][j]))
                printf("%c", strmap[i][j]);
        }
    }
}

void show_wordmap(char** strmap, int row, int col){
    for (int i=0; i<row; ++i){
        for (int j=0; j<col; ++j){    
            printf("%c", strmap[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    char word[1001];

    scanf("%d %s", &n, word);
    int wordlen = strlen(word);

    char** strmap = (char**)malloc(sizeof(char*) * n); // [n][wordlen];
    for (int i=0; i<n; ++i) strmap[i] = (char*)malloc(wordlen);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < wordlen; j++) {
            strmap[i][j] = '-';
        }
    }

    int wordcount = 0;
    int col = 0;
    while (wordcount < wordlen){
        for (int i=0; i<n && wordcount < wordlen; ++i)
            strmap[i][col] = word[wordcount++]; 

        col++;

        for (int i=n-2; i>0 && wordcount < wordlen; --i)
            strmap[i][col++] = word[wordcount++];
    }

    print_wordmap(strmap, n, col);
    printf("\n");
    
    return 0;
}