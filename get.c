/*************************************************************************
	> File Name: get.c
	> Author:cjw 
	> Mail:1293632174@qq.com 
	> Created Time: Tue 26 Mar 2024 02:07:03 PM CST
 ************************************************************************/

#include <stdio.h>
typedef struct Data {
    char name[20];
    int age;
    int class;
    double height;
} Data;
int main() {
    char enter[1] = {"\n"};
    FILE *fp = fopen("test.dat", "wb");
    Data test[3] = {{"cjw", 18, 2, 175.7}, {"CaptainHu", 32, 6, 178.9}, {"wzz", 15, 8, 170}};
    int i = 0;
    while (i < 3) {
        fwrite(test + i, sizeof(Data), 1, fp);
        i++;
        printf("success write %d data\n", i);
    }
    fclose(fp);
}

