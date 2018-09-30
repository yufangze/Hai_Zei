/*************************************************************************
	> File Name: 1008.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月29日 星期六 09时47分14秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
int main() {
    int a[10];
    for (int i = 123; i <= 329; i++) {
        memset(a, 0, sizeof(a));
        a[i % 10] = a[i / 10 % 10] = a[i / 100] = 1;
        a[i * 2 % 10] = a[i * 2 / 10 % 10] = a[i * 2 / 100] = 1;
        a[i * 3 % 10] = a[i * 3 / 10 % 10] = a[i * 3 / 100] = 1;
    int cnt = 0;
    for (int j = 1; j <= 9; j++) cnt += a[j];
    if (cnt == 9) printf("%d %d %d\n", i, i * 2, i * 3);
    }
    return 0;
}
