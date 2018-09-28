/*************************************************************************
	> File Name: 1909.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月28日 星期五 19时45分27秒
 ************************************************************************/
#include <stdio.h>

int main() {
    int n, cnt, price;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%d%d", &cnt, &price);
        int cnt_s = cnt, price_s = price;
        while (cnt < n) cnt <<= 1, price <<= 1;
        while (cnt > n) cnt -= cnt_s, price -= price_s;
        while (cnt < n) cnt += cnt_s, price += price_s;
        if (price < ans || ans == 0) ans = price;
    }//倍增算法
    printf("%d\n", ans);
    return 0;
}
