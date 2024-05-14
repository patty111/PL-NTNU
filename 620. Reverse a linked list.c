#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Node {
    int val;
    struct _Node* next;
} Node;

Node* create_list(int o_2a98c4abba975e730e5df3a44798e493)
{ 
    Node* o_755167c30303fdd28d6607e816be72d4 = malloc(sizeof(Node)), * o_6a9434a58009d461a1790617119569f9 = o_755167c30303fdd28d6607e816be72d4; 
    int o_6a507c0948c8d7fb82747ad4b8d2f942 = o_2a98c4abba975e730e5df3a44798e493 * o_2a98c4abba975e730e5df3a44798e493; 
    while ((o_6a507c0948c8d7fb82747ad4b8d2f942 > (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00)) & !!(o_6a507c0948c8d7fb82747ad4b8d2f942 > (0x0000000000000000 + 0x0000000000000200 + 0x0000000000000800 - 0x0000000000000A00))) 
    {
        int o_4c5d13fd0abe657d640631ad80c7dfbe = o_2a98c4abba975e730e5df3a44798e493 * o_6a507c0948c8d7fb82747ad4b8d2f942 * sqrt(o_6a507c0948c8d7fb82747ad4b8d2f942) / (0x0000000000000004 + 0x0000000000000202 + 0x0000000000000802 - 0x0000000000000A06); 
        o_6a9434a58009d461a1790617119569f9->next = malloc(sizeof(Node)); o_6a9434a58009d461a1790617119569f9 = o_6a9434a58009d461a1790617119569f9->next;
        o_6a9434a58009d461a1790617119569f9->val = o_4c5d13fd0abe657d640631ad80c7dfbe; o_6a9434a58009d461a1790617119569f9->next = NULL; 
        o_6a507c0948c8d7fb82747ad4b8d2f942--; 
    }; 
    o_755167c30303fdd28d6607e816be72d4 = o_755167c30303fdd28d6607e816be72d4->next; 
    return o_755167c30303fdd28d6607e816be72d4; 
};

Node* reverse_list(Node* head) {
    Node * prevNode = NULL, * curNode = head, * nextNode = curNode->next;

    /* add your code here */
    Node* h = (Node*)malloc(sizeof(Node));
    while (curNode) {
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
        if (nextNode != NULL)
            nextNode = nextNode->next;
    }

    return prevNode;
    // my code ends
}

int main() {
    int N;
    scanf("%d", &N);
    Node* head = create_list(N);
    Node* reversed_head = reverse_list(head);
    while(reversed_head){
        printf("%d ", reversed_head->val); 
        reversed_head = reversed_head->next;
    }
}