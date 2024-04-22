#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    int available = 0;

    char** seats = malloc(n * sizeof(char*));

    for (int i=0; i<n; ++i){
        seats[i] = malloc(11);

        scanf("%s", seats[i]);
        int countall = 0;
        int countleft = 0;
        int countright = 0;
        int countmid = 0;
        for (int j=0; j<10; ++j){
            if (seats[i][j] == '0' && j>=1 && j <=8)
                countall++;
            if (seats[i][j] == '0' && j>=1 && j <=4)
                countleft++;
            if (seats[i][j] == '0' && j>=5 && j <=8)
                countright++;
            if (seats[i][j] == '0' && j>=3 && j <=6)
                countmid++;
        }
        if (countall == 8)
            available += 2;
        else if (countmid == 4 || countright == 4 || countleft == 4)
            available++;
        
        free(seats[i]);
    }

    printf("%d\n", available);

    return 0;
}