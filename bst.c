#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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

void print_bst_preorder(node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    print_bst_preorder(root->left);
    print_bst_preorder(root->right);
}

void print_bst_inorder(node* root) {
    if (root == NULL) return;
    print_bst_inorder(root->left);
    printf("%d ", root->data);
    print_bst_inorder(root->right);
}

void print_bst_postorder(node* root) {
    if (root == NULL) return;
    print_bst_postorder(root->left);
    print_bst_postorder(root->right);
    printf("%d ", root->data);
}


int main(){

    int nums[5] = {4, 6, 2, 9, 5};
    node* root = (node*)malloc(sizeof(node));
    root = NULL;

    for (int i=0; i<5; ++i){
        root = insert_node(nums[i], root);
    }
    
    printf("preorder: ");
    print_bst_preorder(root);
    printf("\n");
    printf("inorder: ");
    print_bst_inorder(root);
    printf("\n");
    printf("postorder: ");
    print_bst_postorder(root);
    printf("\n");

    return 0;
}