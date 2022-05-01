#include <stdio.h>
#include <stdlib.h>

struct tree {
    struct tree* left;
    int data;
    struct tree* right;
};

struct tree* create(int n);

void main() {
    struct tree* root;

    root = create(50);

    root->left = create(10);

    printf("%d", root->left->data);
}

struct tree* create(int n) {
    struct tree* node;

    node = (struct tree*)malloc(sizeof(struct tree));

    node->data = n;

    return node;
}