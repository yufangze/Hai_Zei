/*************************************************************************
	> File Name: struct.c
	> Author: yufangze
	> Mail: 2224590123@qq.com
	> Created Time: 2018年10月04日 星期四 10时17分49秒
 ************************************************************************/
#include <stdio.h>
#pragma pack(1) //以多少字节为对齐方式
struct person {
    char name[20];
    int age;
    char gendar;
    float height;
};

int main() {
    printf("sizeof(person): %d\n", sizeof(struct person));
    return 0;
}
