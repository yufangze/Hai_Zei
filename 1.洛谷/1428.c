/*************************************************************************
	> File Name: 1428.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年10月26日 星期五 16时12分41秒
 ************************************************************************/
#include <stdio.h>
#define max 100

int num[max + 5] = {0};
int ans[max + 5] = {0};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", num + i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            num[j] < num[i] && ans[i]++;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", ans[i]);
        i < n && printf(" ");
    }
    printf("\n");
    return 0;
}
