/*************************************************************************
	> File Name: 1046.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年10月04日 星期四 09时47分19秒
 ************************************************************************/
#include <stdio.h>

int main() {
    int a[10] = {0};
    int high;
    for (int i = 0; i < 10; i++) {
        scanf("%d", a + i);
    }
    scanf("%d", &high);
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        if (a[i] > high + 30) continue;
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
