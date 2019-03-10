/*************************************************************************
	> File Name: 1803.cpp
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2019年03月10日 星期日 16时55分36秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
#define max 1000000
using namespace std;

struct Node {
    int start;
    int end;
} arr[max + 5];

bool cmp(Node a, Node b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].end;
    }
    sort(arr, arr + n, cmp);
    int sum = 1, temp = arr[0].end;
    for (int i = 1; i < n; i++) {
        if (arr[i].start < temp) continue;
        temp = arr[i].end;
        sum++;
    }
    cout << sum << endl;
    return 0;
}
