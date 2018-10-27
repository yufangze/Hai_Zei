/*************************************************************************
	> File Name: 1200.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年10月26日 星期五 20时18分12秒
 ************************************************************************/
#include <stdio.h>

char str[26] = {0};

int main() {
    int a = 1, b = 1;
    scanf("%s", str);
    for (int i = 0; str[i]; i++) {
        a *= (str[i] - 'A' + 1);
        a %= 47;
    }
    scanf("%s", str);
    for (int i = 0; str[i]; i++) {
        b *= (str[i] - 'A' + 1);
        b %= 47;
    }
    printf("%s\n", a == b ? "GO" : "STAY");
    return 0;
}
