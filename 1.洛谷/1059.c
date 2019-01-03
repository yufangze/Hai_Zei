/*************************************************************************
	> File Name: 1059.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年12月15日 星期六 19时43分11秒
 ************************************************************************/
#include <stdio.h>
#define max 100
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
        }while (x <= y);
        quick_sort(num, x, r);
        r = y;
    }
    return ;
}

void output(int *a, int n) {
    int cnt = n;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) continue;
        a[i - 1] = -1;
        cnt--;
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            printf("%d", a[i]);
            i < n - 1 && printf(" ");
        }
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
