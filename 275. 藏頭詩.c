#include <stdio.h>
#include <string.h>

int main(){
    int n, m;
    scanf("%d", &n);
    char dict[n][20];

    for (int i=0; i<n; ++i)
        scanf("%s", dict[i]);
    scanf("%d", &m);

    char words[m][50];
    int max_len = -1;
    for (int i=0; i<m; ++i){
        scanf("%s", words[i]);
        int word_len = strlen(words[i]);
        max_len = max_len > word_len ? max_len : word_len;
    }
    
    int flag = 0;
    for (int i=0; i<max_len; ++i){
        char word[50] = "";
        for (int j=0; j<m; ++j){
            if (words[j][i] == '\0')
                flag = 1;
            word[j] = words[j][i];
        }
        for (int k=0; k<n; ++k){
            if (strncmp(dict[k], word, m) == 0)
                printf("%s", dict[k]);
        }
        if (flag) break;
    }
    printf("\n");
    return 0;
}