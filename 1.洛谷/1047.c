/*************************************************************************
	> File Name: 1047.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年10月26日 星期五 15时38分31秒
 ************************************************************************/
#include <stdio.h>
#define max 10000

int cnt[max + 5] = {0};

int main() {
    int l, m, start, end;
    scanf("%d%d", &l, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &start, &end);
        for (int i = start; i <= end; i++) {
            cnt[i] = 1;
        }
    }
    int num = 0;
    for (int i = 0; i <= l; i++) {
        if (!cnt[i]) num++;
    }
    printf("%d\n", num);
    return 0;
}
