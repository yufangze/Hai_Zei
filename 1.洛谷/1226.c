/*************************************************************************
	> File Name: 1226.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月19日 星期三 10时26分42秒
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>

int64_t quick_pow(int64_t a, int64_t b, int64_t c) {
    if (__builtin_expect(!!(b == 0), 0)) return 1 % c;
    int64_t r = 1, base = a;
    while (b) {
        if (b & 1) r = r * base % c;
        base = base * base % c;
        b >>= 1;
    }
    return r;
}

int main() {
    int64_t b, p, k;
    scanf("%ld%ld%ld", &b, &p, &k);
    printf("%ld^%ld mod %ld=%ld\n", b, p, k, quick_pow(b, p, k));
    return 0;
}
