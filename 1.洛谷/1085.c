/*************************************************************************
	> File Name: 1085.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月28日 星期五 18时37分09秒
 ************************************************************************/
#include <stdio.h>

int main() {
    int date[8] = {0};
    int a, b;
    for (int i = 1; i <= 7; i++) {
        scanf("%d%d", &a, &b);
        date[i] = a + b;
    }
    int num = 0;
    for (int i = 1; i <= 7; i++) {
        if (date[i] > 8) {
            num = i;
            break;
        }
    }
    printf("%d\n", num);
    return 0;
}
