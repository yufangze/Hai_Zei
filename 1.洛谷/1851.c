/*************************************************************************
	> File Name: 1851.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月15日 星期六 09时59分46秒
 ************************************************************************/
#include <stdio.h>
#include <math.h>
#define max 60000 
int prime[max + 5] = {0};
int fnum[max + 5] = {0};
int min_num[max + 5] = {0};

void fac_prime() {
    for (int i = 2; i <= max; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            fnum[i] = 1 + i;
            min_num[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                fnum[prime[j] * i] = fnum[i] / (pow(prime[j], min_num[i] + 1) - 1) * (pow(prime[j], min_num[i] + 2) - 1);
                min_num[prime[j] * i] = min_num[i] + 1;
                break;
            } else {
                fnum[prime[j] * i] = fnum[prime[j]] * fnum[i];
                min_num[prime[j] * i] = min_num[prime[j]];
            }
        }
    }
    return ;
}


int main() {
    fac_prime();
    for (int i = 2; i <= max; i++) {
        fnum[i] -= i;
    }
    int n, flag = 0;
    scanf("%d", &n);
    for (int i = n; i <= max; i++) {
        if (fnum[i] < max && fnum[fnum[i]] < max && fnum[fnum[i]] == i && fnum[i] != i) {
            flag = i;
            break;
        }
    }
    printf("%d %d\n", flag, fnum[flag]);
    return 0;
}
