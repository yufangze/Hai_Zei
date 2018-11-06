/*************************************************************************
	> File Name: 15.hash_table.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年11月06日 星期二 20时41分55秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *str;
    struct Node *next;
} Node;

typedef struct HashTable {
    Node **data;
    int size;
} HashTable;

Node *init_node(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *init_hash_table(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (Node **)calloc(n, sizeof(Node *) * h->size);
    return h;
}

int BKDR_Hash(char *str) {
    int seed = 31, hash = 0;
    for (int i = 0; str[i]; i++) {
        hash = hash * seed + str[i];
    }
    return hash & 0x7fffffff;
}

//APHash() ZobristHash()

int insert(HashTable *h, char *str) {
    int hash = BKDR_Hash(str);
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
    /*Node *node = init_node(str, NULL);
    int times = 0;
    while (h->data[ind]) {
        times++;
        ind += times * times;
        ind %= h->size;
    }
    h->data[ind] = node;
    */
    return 1;
}

int search(HashTable *h, char *str) {
    int hash = BKDR_Hash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while (p && strcmp(p->str, str)) p = p->next;
    return p != NULL;

}

void clear_node(Node *node) {
    if (node == NULL) return ;
    Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    return ;
}

void clear_hash_table(HashTable *h) {
    if (h == NULL) return ;
    for (int i = 0; i < h->size; i++) {
        clear_node(h->data[i]);
    }
    free(h->data);
    free(h);
    return ;
}

int main() {
    int op;
    char str[100];
    HashTable *h = init_hash_table(100);
    while (scanf("%d%s", &op, str) != EOF) {
        switch (op) {
            case 0: {
                printf("insert %s to HashTable\n", str);
                insert(h, str);
            } break;
            case 1: {
                printf("search %s result = %d\n", str, search(h, str));
            } break;
        }
    }
    return 0;
}
