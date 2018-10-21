/*************************************************************************
	> File Name: 1424.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月30日 星期日 11时13分47秒
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>
int main() {
    int64_t x, n;
    scanf("%ld%ld", &x, &n);
    int64_t sum = 0;
    for (int64_t i = x % 7, j = 1; j <= n; j++, i = (i + 1) % 7) {
        if (i == 6 || i == 0)continue;
        sum += 250;
    }
    printf("%ld\n", sum);
    return 0;
}
