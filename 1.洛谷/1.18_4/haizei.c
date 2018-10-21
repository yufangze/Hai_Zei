/*************************************************************************
	> File Name: haizei.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年10月04日 星期四 16时12分21秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[], char *env[]) {
    if (argv[1] == NULL) exit(1);
    if (strcmp(argv[1], "1123")) {
        printf("wrong key!\n");
        exit(1);
    }
    printf("hello world!\n");
    return 0;
}
