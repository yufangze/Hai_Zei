/*************************************************************************
	> File Name: 1423.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月29日 星期六 10时52分46秒
 ************************************************************************/
#include <stdio.h>

int main() {
    double s;
    scanf("%lf", &s);
    int step = 1;
    double len = 2, last = 2;
    while (len < s) {
        len = len + last * 0.98;
        last *= 0.98;
        step++;
    }
    printf("%d\n", step);
    return 0;
}
