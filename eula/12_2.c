/*************************************************************************
	> File Name: 12_2.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年08月17日 星期五 14时40分51秒
 ************************************************************************/
#include <stdio.h>
#define max 1000000

int prime[max + 5] = {0};
int dnum[max + 5] = {0};
int min_num[max + 5] = {0};

void init() {
    for (int i = 2; i <= max; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
            min_num[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                dnum[prime[j] * i] = dnum[i] / (min_num[i] + 1) * (min_num[i] + 2);
                min_num[prime[j] * i] = min_num[i] + 1;
                break;
            } else {
                dnum[prime[j] * i] = dnum[prime[j]] * dnum[i];
                min_num[prime[j] * i] = 1;
            }
        }
    }
    return;
}

int main() {
    init();
    int n = 2;
    while (1) {
        int total_fac = 0;
        if (n & 1) {
            total_fac = dnum[n] * dnum[(n + 1) >> 1];
        } else {
            total_fac = dnum[n >> 1] * dnum[n + 1];
        }
        if (total_fac >= 500) break;
        ++n;
    }
    printf("%d\n", n * (n + 1) >> 1);
    return 0;
}
