/*************************************************************************
	> File Name: 34.c
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 16时00分46秒
 ************************************************************************/
#include <stdio.h>
#define max 2540160

int keep[10] = {1, 1, 0};

void f_table() {
    for (int i = 2; i < 10; i++) {
        keep[i] = i * keep[i - 1];
    }
    return ;
}

int is_check(int x) {
    int temp = x, sum = 0;
    while (x) {
        sum = sum + keep[x % 10];
        x /= 10;
    }
    return temp == sum;
}

int main() {
    f_table();
    int sum = 0;
    for (int i = 3; i <= max; i++) {
        if (is_check(i)) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
