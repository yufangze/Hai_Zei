/*************************************************************************
	> File Name: 6.binary_tree.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年10月23日 星期二 19时17分25秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

Node *init(int data) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *build() {
    Node *root = init(1);
    root->lchild = init(2);
    root->rchild = init(3);
    root->lchild->lchild = init(6);
    root->lchild->rchild = init(7);
    root->rchild->lchild = init(5);
    root->rchild->rchild = init(9);
    root->rchild->lchild->lchild = init(10);
    root->rchild->lchild->rchild = init(11);
    return root;
}

int height_tree(Node *root) {
    if (root == NULL) return 0;
    int lh = height_tree(root->lchild), rh = height_tree(root->rchild);
    return (lh > rh ? lh : rh) + 1;
}

void pre_order(Node *root) {
    if (root == NULL) return ;
    printf("%d ", root->data);
    pre_order(root->lchild);
    pre_order(root->rchild);
    return ;
}

void in_order(Node *root) {
    if (root == NULL) return ;
    in_order(root->lchild);
    printf("%d ", root->data);
    in_order(root->rchild);
    return ;
}

void post_order(Node *root) {
    if (root == NULL) return ;
    post_order(root->lchild);
    post_order(root->rchild);
    printf("%d ", root->data);
    return ;
}

void clear(Node *node) {
    if (node == NULL) return ;
    free(node->lchild);
    free(node->rchild);
    free(node);
    return ;
}

int main() {
    Node *root = build();
    printf("height(root) = %d\n", height_tree(root));
    pre_order(root), printf("\n");
    in_order(root), printf("\n");
    post_order(root), printf("\n");
    return 0;
}
