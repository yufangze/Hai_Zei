/*************************************************************************
	> File Name: 13.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年08月13日 星期一 15时35分39秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#define max 50

int ans[max + 5] = {0};
char str_num[max + 5] = {0};

int main() {
    
    while (scanf("%s", str_num) != EOF) {
        int len = strlen(str_num);
        if (len > ans[0]) ans[0] = len;
        for (int i = 0; i <= len; i++) {
            ans[len - i] += (str_num[i] - '0');
        }
        for (int j = 1; j <= ans[0]; j++) {
            if (ans[j] < 10) continue;
            ans[j + 1] += ans[j] / 10;
            ans[j] %= 10;
            ans[0] += (ans[0] == j);
        }
    }
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
