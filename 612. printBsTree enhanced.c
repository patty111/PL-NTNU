#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    struct Node* right;
    struct Node* left;
    int data;
} node;

node* create_node(int data, node* left, node* right) {
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left = left;
    n->right = right;
    return n;
}

node* insert_node(int data, node* root) {
    if (root == NULL){
        return create_node(data, NULL, NULL);
    }

    if (data < root->data) {
        root->left = insert_node(data, root->left);
    }
    else {
        root->right = insert_node(data, root->right);
    }
    
    return root;
}

void print_bst(node* root, int depth, char path[10]) {
    if (root == NULL) return;

    char newpath[10];
    strncpy(newpath, path, 10);

    if (root->left) {
        newpath[depth] = 'L';
        newpath[depth+1] = '\0';
        print_bst(root->left, depth+1, newpath);
    }

    printf("%s%d data = %d\n", path, depth, root->data);

    if (root->right) {
        newpath[depth] = 'R';
        newpath[depth+1] = '\0';
        print_bst(root->right, depth+1, newpath);
    }
}

int main(){
    int nums[5];
    for (int i=0; i<5; ++i)
        scanf("%d", &nums[i]);
    
    node* root = (node*)malloc(sizeof(node));
    root = NULL;

    for (int i=0; i<5; ++i)
        root = insert_node(nums[i], root);

    print_bst(root, 0, "");

    return 0;
}