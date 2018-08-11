/*************************************************************************
	> File Name: 8.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年08月11日 星期六 15时07分55秒
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>
#include "8.h"

int main() {
    int64_t max_p = 0, p = 1, zero_num = 0;
    for (int i = 0; num[i]; i++) {
        if (i >= 13) {
            if (num[i - 13] == '0') {
                zero_num--;
            } else {
                p /= (num[i - 13] - '0');
            }
        }
        if (num[i] == '0') {
            zero_num++;
        } else {
            p *= (num[i] - '0');
        }
        if (zero_num == 0 && i >= 12 && p > max_p) {
            max_p = p;
        }
    }
    printf("%"PRId64"\n", max_p);
    return 0;
}
