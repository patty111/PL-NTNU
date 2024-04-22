#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(){
    char* word = (char*)malloc(102);
    int alphabet[26] = {0};

    scanf("%s", word);

    for (;*word != '\0';++word){
        char tmp_char = toupper(*word);
        if (isalpha(tmp_char))
            alphabet[tmp_char - 'A'] += 1;
    }

    for (int i=0; i<26; ++i)
        printf("%d\n", alphabet[i]);

    return 0;
}