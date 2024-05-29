#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* right;
    struct Node* left;
    int data;
} node;

int* tree;
int treeidx = 0;
int* bst;
int bstidx = 0;

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

void bst_traverse(node* root) {
    if (root == NULL) return;
    bst_traverse(root->left);
    bst[bstidx++] = root->data;
    bst_traverse(root->right);
}

void tree_traverse(node* root) {
    if (root == NULL) return;
    tree_traverse(root->left);
    tree[treeidx++] = root->data;
    tree_traverse(root->right);
}


int main(){
    int n;
    node* bst_root = (node*)malloc(sizeof(node));
    bst_root = NULL;

    scanf("%d", &n);

    node* nodes = (node*)malloc(n * sizeof(node));
    bst = (int*)malloc(n * sizeof(int));
    tree = (int*)malloc(n * sizeof(int));

    for (int i=0; i<n; ++i){
        int l, r, node_val;
        scanf("%d %d %d", &l, &r, &node_val);

        if (l != -1) {
            nodes[i].left = &nodes[l];
        }
        else {
            nodes[i].left = NULL;
        }

        if (r != -1) {
            nodes[i].right = &nodes[r];
        }
        else {
            nodes[i].right = NULL;
        }
        nodes[i].data = node_val;

        bst_root = insert_node(node_val, bst_root);
    }

    bst_traverse(bst_root);
    tree_traverse(&nodes[0]);

    for (int i=0; i<n; ++i){
        if (tree[i] != bst[i]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

    return 0;
}