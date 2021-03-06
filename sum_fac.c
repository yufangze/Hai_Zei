/*************************************************************************
	> File Name: sum_fac.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年08月18日 星期六 14时32分40秒
 ************************************************************************/
#include <stdio.h>
#include <math.h>
#define max 1000000

int prime[max + 5] = {0};
int min_num[max + 5] = {0};
int fnum[max + 5] = {0};

void init() {
    for (int i = 2; i <= max; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            min_num[i] = 1;
            fnum[i] = 1 + i;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                fnum[prime[j] * i] = fnum[i] / (pow(prime[j], min_num[i] + 1) - 1) * (pow(prime[j], min_num[i] + 2) - 1);
                min_num[prime[j] * i] = min_num[i] + 1;
                break;
            } else {
                fnum[prime[j] * i] = fnum[prime[j]] * fnum[i];
                min_num[prime[j] * i] = 1;
            }
        }
    }
    return ;
}

int main() {
    init();
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("fnum[%d] = %d\n", n, fnum[n]);
    }
    return 0;
}
