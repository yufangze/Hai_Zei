/*************************************************************************
	> File Name: 10.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年08月11日 星期六 09时46分23秒
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>
#define max 2000000

int prime[max + 5] = {0};

void init_prime() {
    for (int i = 2; i <= max; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int main() {
    init_prime();
    int64_t sum = 0;
    for (int i = 1; i <= prime[0]; i++) {
        sum += prime[i];
    }
    printf("%"PRId64"\n", sum);
    return 0;
}
