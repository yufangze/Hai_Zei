/*************************************************************************
	> File Name: 1567.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年10月26日 星期五 18时52分12秒
 ************************************************************************/
#include <stdio.h>
#define max 10000000

int day[max + 5] = {0};

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", day + i);
    }
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (day[i] < day[i + 1]) cnt++;
        else if (cnt > ans) {
            ans = cnt;
            cnt = 0;
        } else {
            cnt = 0;
        }
    }
    printf("%d\n", ans + 1);
    return 0;
}
