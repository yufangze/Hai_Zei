/*************************************************************************
	> File Name: 10.heap_sort.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年10月30日 星期二 20时27分44秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    __typeof(a)  __temp = a; a = b; b = __temp;\
}

void heap_sort(int *arr, int n) {
    int *p = arr - 1;
    for (int i = 2; i <= n; i++) {
        int ind = i;
        while (ind > 1) {
            if (p[ind] <= p[ind >> 1]) break;
            swap(p[ind], p[ind >> 1]);
            ind >>= 1;
        }
    }
    for (int i = n; i > 1; i--) {
        swap(p[i], p[1]);
        int ind = 1;
        while ((ind << 1) <= i - 1) {
            int temp = ind;
            if (p[temp] < p[ind << 1]) temp = ind << 1;
            if ((ind << 1 | 1) <= i - 1 && p[temp] < p[ind << 1 | 1]) temp = ind << 1 | 1;
            if (temp == ind) break;
            swap(p[temp], p[ind]);
            ind = temp;
        }
    }
    return ;

}

void output(int *num, int n) {
    printf("Arr = [");
    for (int i = 0; i < n; i++) {
        printf(" %d", num[i]);
        i == n - 1 || printf(",");
    }
    printf("]\n");
    return ;
}

int main() {
    #define max_n 20
    srand(time(0));
    int arr[max_n];
    for (int i = 0; i < max_n; i++) arr[i] = rand() % 100;
    output(arr, max_n);
    heap_sort(arr, max_n);
    output(arr, max_n);
    return 0;
}
