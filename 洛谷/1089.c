/*************************************************************************
	> File Name: 1089.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月28日 星期五 19时00分28秒
 ************************************************************************/
#include <stdio.h>

int main() {
    int month[13] = {0};
    for (int i = 1; i <= 12; i++) {
        scanf("%d", &month[i]);
    }
    int sum = 0, flag = 0, last = 0;
    for (int i = 1; i <= 12; i++) {
        if ((last + 300) < month[i]) {
            flag = i;
            break;
        } 
        sum += (last + 300 - month[i]) / 100 * 100;
        last = (last + 300 - month[i]) % 100;
    }
    sum = sum * 1.2 + last;
    printf("%d\n", flag == 0 ? sum : -flag);
    return 0;
}
