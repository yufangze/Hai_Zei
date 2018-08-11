/*************************************************************************
	> File Name: prime.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年08月10日 星期五 19时01分13秒
 ************************************************************************/
#include <stdio.h>
#define max 200000

int prime[max + 5] = {0};

int main() {
    for (int i = 2; i <= max; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    printf("%d\n", prime[10001]);
    return 0;
}
