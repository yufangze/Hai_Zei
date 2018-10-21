/*************************************************************************
	> File Name: 1035.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月29日 星期六 10时25分54秒
 ************************************************************************/
#include <stdio.h>

int main() {
    int k, n = 0;
    scanf("%d", &k);
    for (double Sn = 0; Sn <= k; ++n, Sn += 1.0 / n);
    printf("%d\n", n);
    return 0;
}
