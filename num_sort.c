/*************************************************************************
	> File Name: num_sort.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年08月16日 星期四 09时32分38秒
 ************************************************************************/
#include <stdio.h>

int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void change(int x, int y) {
    if (y == 1) return;
    int n = y - 1, max_status = 1, ind = 0;
    while (max_status <= n && ind < x) {
        ++ind;
        max_status *= ind;
    }
    max_status /= ind;
    for (int i = x - ind; i < x && n; ++i) {
        --ind;
        int j = i + 1, k;
        while (n >= max_status && j < x) {
            k = a[i];
            a[i] = a[j];
            a[j] = k;
            n -= max_status, j++;
        }
        max_status /= ind;
    }
    return;
}

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    change(x, y);
    for (int i = 0; i < x; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
