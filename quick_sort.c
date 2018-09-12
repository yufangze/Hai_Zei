/*************************************************************************
	> File Name: quick_sort.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月12日 星期三 10时59分10秒
 ************************************************************************/
#include <stdio.h>
#define max 100000
#define swap(a, b) {\
    __typeof(a) temp = a;\
    a = b; b = temp;\
}
void quick(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while (num[x] < z) x++;
            while (num[y] > z) y--;
            if (x <= y) {
                swap(num[x], num[y]);
                ++x, --y;
            }
        }while(x <= y);
        quick(num, x, r);
        r = y;
    }
    return ;
}

int main() {
    int num[max + 5] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", num + i);
    }
    quick(num, 0, n - 1);
    printf("%d", num[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", num[i]);
    }
    printf("\n");
    return 0;
}
