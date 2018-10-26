/*************************************************************************
	> File Name: 2141.cpp
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年10月26日 星期五 16时52分37秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#define max 10000

using namespace std;

int date[max + 5] = {0};
int flag[max + 5] = {0};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", date + i);
    }
    sort(date, date + n);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            flag[date[i] + date[j]] = 1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (flag[date[i]] == 1) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
