/*************************************************************************
	> File Name: 1.文章分词和统计.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年11月16日 星期五 17时22分01秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LENGTH = 256;

char *get_letter() {
    static char letter[10000000];
    letter[999999] = ' ';
    char *p = letter;
    int size = MAX_LENGTH;
    while (feof(stdin) == 0) {
        if (size == 0) {
            break;
        }
        fgets(p, size + 1, stdin);
        while (*p != '\0') {
            p++;
            size--;
        }
    }
    return letter;
}

int main() {
    char *str = get_letter();
    int i = 0;
    char delim[20] = "\n\t ,.\r'\"";
    char love[5] = "love";
    char *str1 = (char *)malloc(sizeof(char) * MAX_LENGTH);
    strcpy(str1, str);
    char *p;
    p = strtok(str1, delim);
    while (p != NULL) {
        printf("%s\n", p);
        if (!strcmp(p, love)) 
            i++;
        p = strtok(NULL, delim);
    }
    printf("%d\n", i);
    free(str1);
    puts(str);
    return 0;
}

#undef MAX_LENGTH
