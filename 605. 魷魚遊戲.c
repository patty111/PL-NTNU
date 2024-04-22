#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int value;
    struct Node* ptr;
} node;

typedef struct linkedList{
    node* head;
    node* end;
} linkedList;

void print_linkedlist(linkedList linkedlist){
    node* tmp = linkedlist.head;

    if (!linkedlist.end){
        printf("%d", tmp->value);
        tmp = tmp->ptr;
        while (tmp != NULL){
            printf("-%d", tmp->value);
            tmp = tmp->ptr;
        }
    }
    else{
        printf("%d", tmp->value);
        tmp = tmp->ptr;
        while (tmp != NULL && tmp != linkedlist.end){
            printf("-%d", tmp->value);
            tmp = tmp->ptr;
        }
        printf("-%d", tmp->value);
    }
    printf("\n");
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);

    node* head = (node*)malloc(sizeof(node));
    head->value = 1;
    head->ptr = NULL;
    
    linkedList linkedlist;
    linkedlist.head = head;
    
    node* tmp = head;

    // N people as a circle -> N-node circular linked list
    for (int i=2; i<=N; ++i){
        node* n = (node*)malloc(sizeof(node));
        n->value = i;

        tmp->ptr = n;
        tmp = tmp->ptr;
        tmp->ptr = NULL;
    }

    tmp->ptr = head;
    linkedlist.end = tmp;
    

    int count = 0;
    tmp = head;

    node* tail = linkedlist.end;

    while (linkedlist.head != linkedlist.end){
        // printf("count: %d ", count);
        // print_linkedlist(linkedlist);

        if (count+1 == M){
            count = (count+1) % M;

            // linkedlist = remove_node(linkedlist, tmp->value);
            // remove head
            if (tmp == linkedlist.head){
                linkedlist.end->ptr = tmp->ptr;
                free(tmp);
                tmp = tail->ptr;
                linkedlist.head = tmp;
                continue;
            }
            
            // remove end
            if (tmp == linkedlist.end){
                tail->ptr = linkedlist.head;
                linkedlist.end = tail;
                // free(tmp);
                tmp = linkedlist.head;
                continue;
            }

            // remove middle
            tail->ptr = tmp->ptr;
            free(tmp);
            tmp = tail->ptr;
            continue;        
        }

        count = (count+1) % M;
        tail = tmp;
        tmp = tmp->ptr;
    }

    int result = linkedlist.head->value - 1;
    if (result == 0)
        printf("-1\n");
    else
        printf("%d\n", result);

    return 0;
}