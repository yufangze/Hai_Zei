/*************************************************************************
	> File Name: quick_pow.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月18日 星期二 17时08分00秒
 ************************************************************************/
#include <stdio.h>

int quick_pow(int a, int b) {
    int r = 1, base = a;
    while (b) {
        if (b & 1) r *= base;
        base *= base;
        b >>= 1;
    }
    return r;
}


int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("%d\n", quick_pow(a, b));
    }
    return 0;
}

