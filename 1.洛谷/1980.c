/*************************************************************************
	> File Name: 1980.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月30日 星期日 14时32分09秒
 ************************************************************************/
#include <stdio.h>

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int temp = i;
        while (temp) {
            int digit = temp % 10;
            temp /= 10;
            cnt += (digit == x);
        }
    }
    printf("%d\n", cnt);
    return 0;
}
