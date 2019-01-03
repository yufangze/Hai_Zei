/*************************************************************************
	> File Name: 1177.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年12月15日 星期六 19时05分42秒
 ************************************************************************/
#include <stdio.h>
#define max 100000
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}
void quick_sort(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while (x <= y && num[x] < z) x++;
            while (x <= y && num[y] > z) y--;
            if (x <= y) {
                swap(num[x], num[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick_sort(num, x, r);
        r = y;
    }
    return ;
}

void output(int *a, int n) {
    printf("%d", a[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int a[max + 5] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    quick_sort(a, 0, n - 1);
    output(a, n);
    return 0;
}
