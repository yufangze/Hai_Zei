/*************************************************************************
	> File Name: 1425.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月28日 星期五 16时22分06秒
 ************************************************************************/
#include <stdio.h>

int main() {
    int a_h, a_m, b_h, b_m;
    scanf("%d%d%d%d", &a_h, &a_m, &b_h, &b_m);
    int suma = a_h * 60 + a_m;
    int sumb = b_h * 60 + b_m;
    printf("%d %d\n", (sumb - suma) / 60, (sumb - suma) % 60);
    return 0;
}
