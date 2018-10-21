/*************************************************************************
	> File Name: IP.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年10月04日 星期四 10时01分05秒
 ************************************************************************/
#include <stdio.h>

union Ip {
    struct {
        unsigned char arr[4];
    } ip;
    unsigned int num;
};

int main() {
    int a, b, c, d;
    Ip ip;
    while (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != EOF) {
        ip.ip.arr[0] = a;
        ip.ip.arr[1] = b;
        ip.ip.arr[2] = c;
        ip.ip.arr[3] = d;
        printf("%d\n", ip.num);
    }
    return 0;
}
