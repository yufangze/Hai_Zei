/*************************************************************************
	> File Name: 1025_dp.c
	> Author: 
	> Mail: 
	> Created Time: Wed Sep 26 19:28:48 2018
 ************************************************************************/
#include <stdio.h>

int main() {
    int n, k, f[201][7];//f[k][x] k分成x份 = {f[k-1][x-1], f[k-x][x]}
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        f[i][1] = 1, f[i][0] = 1;
    for (int x = 2; x <= k; x++)
        f[1][x] = 0, f[0][x] = 0;//边界，为了防止越界， 把0的处理了
    for (int i = 2; i <= n; i++) {
        for (int x = 2; x <= k; x++) { 
            if  ( i > x ) f[i][x] = f[i - 1][x - 1] + f[i - x][x];
            else  f[i][x] = f[i - 1][x - 1]; 
        }
    }
    printf("%d\n", f[n][k]);
    return 0;
}
