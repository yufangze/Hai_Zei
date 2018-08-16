/*************************************************************************
	> File Name: 24.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年08月16日 星期四 11时37分14秒
 ************************************************************************/
#include <stdio.h>
#define max 1000000

int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
    int n = max - 1, max_status = 1, ind = 0;
    while (max_status <= n && ind < 10) {
        ++ind;
        max_status *= ind;
    }
    max_status /= ind;
    for (int i = 10 - ind; i < 10 && n; i++) {
        ind--;
        int j = i + 1, k;
        while (n >= max_status && j < 10) {
            k = a[i];
            a[i] = a[j];
            a[j] = k;
            n -= max_status, j++;
        }
        max_status /= ind;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
    return 0;
}
