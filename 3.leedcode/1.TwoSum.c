/*************************************************************************
	> File Name: 1.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年11月08日 星期四 19时02分58秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct Data {
    int val, ind;
} Data;

typedef struct hash_table {
    Data *data;
    int *flag;
    int size;
} hash;

hash *init(int n) {
    hash *h = (hash *)malloc(sizeof(hash));
    h->size = n << 1;
    h->data = (Data *)malloc(sizeof(Data) * h->size);
    h->flag = (int *)calloc(sizeof(int), h->size);
    return h;
}

int hashfunc(int val) {
    return val & 0x7fffffff;
}

void insert(hash *h, int val, int ind) {
    int hash = hashfunc(val);
    int pos = hash % h->size;
    int times = 1;
    while (h->flag[pos]) {
        pos += (times * times);
        times++;
        pos %= h->size;
    }
    h->data[pos].val = val;
    h->data[pos].ind = ind;
    h->flag[pos] = 1;
    return ;
}

Data *search(hash *h, int val) {
    int hash = hashfunc(val);
    int pos = hash % h->size;
    int times = 1;
    while (h->flag[pos] && h->data[pos].val != val) {
        pos += (times * times);
        times++;
        pos %= h->size;
    }
    if (h->flag[pos] == 0) return NULL;
    return h->data + pos;
}

void clear(hash *h) {
    if (h == NULL) return ;
    free(h->data);
    free(h->flag);
    free(h);
    return ;
}

int* twoSum(int* nums, int numsSize, int target) {
    hash *h = init(numsSize);
    int *ret = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        Data *result = search(h, target - nums[i]);
        if (result) {
            ret[0] = result->ind;
            ret[1] = i;
            break;
        }
        insert(h, nums[i], i);
    }
    clear(h);
    return ret;
}

int main() {
    int num[100] = {0};
    int n, target;
    while (scanf("%d", &n) != EOF) {
        int *ret = (int *)calloc(2, sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }
        scanf("%d", &target);
        ret = twoSum(num, n, target);
        printf("%d %d\n", ret[0], ret[1]);
    }
    return 0;
}
