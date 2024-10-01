#include <stdio.h>

typedef struct Node {
    char item;
    struct Node *left;
    struct Node *right;
} Node;

void inordTrav(Node *root) {
    if (root == NULL)
        return;
    inordTrav(root->left);
    printf("%c ", root->item);
    inordTrav(root->right);
}

void preordTrav(Node *root) {
    if (root == NULL)
        return;
    printf("%c ", root->item);
    preordTrav(root->left);
    preordTrav(root->right);
}

void postordTrav(Node *root) {
    if (root == NULL)
        return;
    postordTrav(root->left);
    postordTrav(root->right);
    printf("%c ", root->item);
}

int main() {
    Node n, l, r;
    // a + b
    n.item = '+'; n.left = &l; n.right = &r;
    l.item = 'a'; l.left = NULL; l.right = NULL;
    r.item = 'b'; r.left = NULL; r.right = NULL;
    
    inordTrav(&n);
    printf("\n");
    preordTrav(&n);
    printf("\n");
    postordTrav(&n);

    return 0;
}
