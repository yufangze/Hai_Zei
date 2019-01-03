/*************************************************************************
	> File Name: print.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2019年01月03日 星期四 16时37分28秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

int print_int(int x, int flag) {
    if (x == 0) {
        flag && putchar('0');
        return !!(flag);
    }
    int temp = x, ret = 0, digit = 0;
    x = 0;
    while (temp) {
        x = x * 10 + temp % 10;
        temp /= 10;
        digit++;
    }
    while (digit--) {
        putchar(x % 10 + '0');
        x /= 10;
        ret++;
    }
    return ret;
}

int my_print(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0; frm[i]; i++) {
        switch (frm[i]) {
            case '%' : {
                i++;
                switch (frm[i]) {
                    case 'd' : {
                        int temp = va_arg(arg, int);
                        int p1 = temp / 10, p2 = temp % 10;
                        if (temp < 0) {
                            p1 = -p1, p2 = -p2;
                            putchar('-');
                        }
                        cnt += print_int(p1, 0);
                        cnt += print_int(p2, 1);
                    } break;
                    default :
                        fprintf(stderr, "error : unknown %%%c\n", frm[i]);
                        exit(1);
                }
            } break;
            default :
                putchar(frm[i]);
                cnt++;
        }
    }

    return cnt;
}

int main() {
    int n = 123;
    int m = my_print("hello world\n");
    my_print("n = %d\n", n);
    my_print("n = %d\n", 12000);
    my_print("n = %d\n", -567);
    my_print("n = %d\n", 0);
    my_print("n = %d\n", INT32_MIN);
    my_print("n = %d\n", INT32_MAX);
    printf("%d\n", m);
    return 0;
}
