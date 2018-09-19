/*************************************************************************
	> File Name: quick_pow.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月18日 星期二 17时08分00秒
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>
int64_t quick_pow(int64_t a, int64_t b) {
    int64_t r = 1, base = a;
    while (b) {
        if (b & 1) r *= base;
        base *= base;
        b >>= 1;
    }
    return r;
}


int main() {
    int64_t a, b;
    while (scanf("%ld%ld", &a, &b) != EOF) {
        printf("%ld\n", quick_pow(a, b));
    }
    return 0;
}

