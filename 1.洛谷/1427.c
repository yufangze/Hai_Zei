/*************************************************************************
	> File Name: 1427.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年10月26日 星期五 15时54分36秒
 ************************************************************************/
#include <stdio.h>
#define max 100

int num[max + 5] = {0};

int main() {
    int input = 1, cnt = 0;
    while (input) {
        scanf("%d", &input);
        num[cnt++] = input;
    }
    for (int i = cnt - 2; i >= 0; i--) {
        printf("%d", num[i]);
        i && printf(" ");
    }
    printf("\n");
    return 0;
}
