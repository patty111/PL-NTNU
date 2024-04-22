#include <stdio.h>
#include <ctype.h>

int main(){
    char guess[6];
    char ans[6];

    scanf("%s %s", guess, ans);

    for (int i=0; i<5; ++i){
        for (int j=0; j<5; ++j){
            if (!isalpha(guess[i]) || !isalpha(ans[i])){
                printf("ERR\n");
                return 0;
            }

            if ((toupper(guess[i]) == toupper(guess[j]) || toupper(ans[i]) == toupper(ans[j])) && i != j){
                printf("ERR\n");
                return 0;
            }
        }
    }


    for (int i=0; i<5; ++i){
        int flag = 0;
        if (toupper(guess[i]) == ans[i]){
            printf("G");
            continue;
        }
        else{
            for (int j=0; j<5; ++j){
                if (toupper(guess[i]) == toupper(ans[j])){
                    printf("Y");
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                continue;
        }
        printf("W");
    }
    return 0;
}