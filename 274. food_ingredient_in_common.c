#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int idx_of_food(char** foods, int foods_len, char* food){
    for (int i=0; i<foods_len; ++i){
        if (strncmp(foods[i], food, 15) == 0)
            return i;
    }
    return -1;
}

void ingredient_match(char** ingredient_list1, int ingd1_len, char** ingredient_list2, int ingd2_len){
    int loop = ingd1_len > ingd2_len ? ingd1_len : ingd2_len;
    int subloop = ingd1_len > ingd2_len ? ingd2_len : ingd1_len;

    int flag = 0;
    int init = 1;

    char** same_ingd = (char**)malloc(sizeof(char*) * loop);
    for (int i=0; i<loop; ++i) same_ingd[loop] = (char*)malloc(15);

    int c = 0;
    for (int i=0; i<loop; ++i){
        for (int j=0; j<subloop; ++j){
            if (strncmp(ingredient_list1[i], ingredient_list2[j], 15) == 0){
                // printf("%s", ingredient_list1[i]);
                strncpy(same_ingd[c], ingredient_list1[i], strlen(ingredient_list1[i]));
                flag = 1;
            }
        }
    }


    if (!flag)
        printf("nothing\n");
}


int main(){
    int n, m;
    scanf("%d", &n);

    char** foods = (char**)malloc(sizeof(char*) * n);
    char*** ingredients = (char***)malloc(sizeof(char**) * n);
    int* ingredient_counts = (int*)malloc(sizeof(int) * n);

    for (int i=0; i<n; ++i) foods[i] = (char*)malloc(15);
    
    for (int i=0; i<n; ++i){
        scanf("%s", foods[i]);
        int tmp;
        scanf("%d", &tmp);
        ingredient_counts[i] = tmp;
        ingredients[i] = (char**)malloc(sizeof(char*) * tmp);
        for (int j=0; j<tmp; ++j){
            ingredients[i][j] = (char*)malloc(sizeof(char) * 15);
            scanf("%s", ingredients[i][j]);
        }
    }

    scanf("%d", &m);
    for (int i=0; i<m; ++i){
        char food1[15];
        char food2[15];

        scanf("%s %s", food1, food2);
        // printf("\n%d\n", idx_of_food(foods, n, food1));


        int idx1 = idx_of_food(foods, n, food1);
        int idx2 = idx_of_food(foods, n, food2);
        ingredient_match(ingredients[idx1], ingredient_counts[idx1], ingredients[idx2], ingredient_counts[idx2]);
    }

    return 0;
}