/*************************************************************************
	> File Name: 20.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年08月19日 星期日 13时59分39秒
 ************************************************************************/
#include <stdio.h>
#define max 600

void fac(int n, int *num) {
    for (int i = 1; i <= n; i++) {
        for (int j = num[0]; j > 0; j--) {
            num[j] *= i;
        }
        for (int k = 1; k <= num[0]; k++) {
            if (num[k] < 10) continue;
            num[k + 1] += num[k] / 10;
            num[k] %= 10;
            num[0] += (k == num[0]);
        }
    }
    return ;
}


int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int num[max + 5] = {1, 1, 0};
        fac(n, num);
        int ans = 0;
        for (int i = num[0]; i > 0; i--) {
            ans += num[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
