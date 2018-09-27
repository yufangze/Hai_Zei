/*************************************************************************
	> File Name: 1068.cpp
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月27日 星期四 18时38分25秒
 ************************************************************************/
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

struct People {
    int num;
    int score;
};

int cmp(People p1, People p2) {
    if (p1.score > p2.score) return 1;
    if (p1.score == p2.score) {
        if (p1.num < p2.num) return 1;
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    m = floor(m * 1.5);
    People p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i].num >> p[i].score;
    }
    sort(p, p + n, cmp);
    int flag = p[m - 1].score;
    int cnt = m;
    for (int i = m; i < n; i++) {
        if (p[i].score == flag) cnt++;
        else break;
    }
    cout << flag << " " << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << p[i].num << " " << p[i].score << endl;
    }
    return 0;
}
