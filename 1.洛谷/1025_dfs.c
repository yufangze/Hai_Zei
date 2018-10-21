/*************************************************************************
	> File Name: 1025_dfs.c
	> Author: 
	> Mail: 
	> Created Time: Wed Sep 26 19:19:20 2018
 ************************************************************************/
#include <stdio.h>

int k, n, cnt;

void dfs(int last, int sum, int cur) {
    if (cur == k) {
        cnt  +=  (sum == n);
        return ;
    }
    for (int i = last; sum + i * (k - cur) <= n; i++) {//剪枝， 只用枚举到sum+i*(k-cur)<=n为止
        dfs(i, sum + i, cur + 1);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    dfs(1, 0, 0);
    printf("%d\n", cnt);
    return 0;
}
