/*************************************************************************
	> File Name: 14.binary_search.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年11月06日 星期二 19时27分08秒
 ************************************************************************/
#include <stdio.h>

int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}
//1111111111111100000000000000000

int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

//00000000000001111111111111111

int binary_search3(int *num, int n) {
    int head = 0, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

int main() {
    
    return 0;
}
