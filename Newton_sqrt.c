/*************************************************************************
	> File Name: Newton_sqrt.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年09月14日 星期五 10时57分27秒
 ************************************************************************/
#include <stdio.h>
#include <math.h>
double f(double x, double n) {
    return x * x - n;
}

double f_prime(double x) {
    return 2 * x;
}

double Newton_sqrt(int n, double (*f)(double, double), double (*f_prime)(double)) {
    double x = 1.0;
    #define EP 1e-7
    while (fabs(f(x, n)) > EP) {
        x -= f(x, n) / f_prime(x);
    }
    #undef EP
    return x;
}


int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%lf\n", Newton_sqrt(n, f, f_prime));
    }
    return 0;
}
