/*************************************************************************
	> File Name: 19.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年08月21日 星期二 09时52分54秒
 ************************************************************************/
#include <stdio.h>

int WhichDay(int y, int m, int d) {
    if (m == 1 || m == 2) {
        --y, m += 12;
    }
    int w = 0;
    w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    return w;
}

int main() {
    int sunday = 0;
    for (int y = 1901; y < 2001; y++) {
        for (int m = 1; m <= 12; m++) {
            if (WhichDay(y, m, 1) == 6) {
                sunday++;
            }
        }
    }
    printf("%d\n", sunday);
    return 0;
}
