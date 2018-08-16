/*************************************************************************
	> File Name: 24_1.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年08月16日 星期四 17时14分54秒
 ************************************************************************/
#include <stdio.h>
#define max 1000000

int get_num(int n, int *num, int flag) {
    int rand = n / flag + 1, count = 0;
    for (int i = 0; i < 10; i++) {
        count += !(num[i]);
        if (rand == count) return i;
    }
    return -1;
}

int main() {
    int n = max - 1, num[10] = {0}, flag = 362880;
    for (int i = 0; i < 10; i++) {
        int digit = get_num(n, num, flag);
        printf("%d", digit);
        num[digit] = 1;
        n %= flag;
        if (i == 9) break;
        flag /= (9 - i);
    }
    printf("\n");
    return 0;
}
