/*************************************************************************
	> File Name: students_table.c
	> Author:cjw 
	> Mail:1293632174@qq.com 
	> Created Time: Mon 18 Mar 2024 07:48:33 PM CST
 ************************************************************************/

#include <stdio.h>
#include <database.h>
static const char *table_name = "students_table";
static const char *table_file = "./data/student_data.dat";
static const char *header_name[] = {"name", "age", "class", "height"};
static int header_len[] = {15, 6, 6, 6};
typedef struct Student {
    char name[20];
    int age;
    int class;
    double height;
} table_data;
#include "table_unit.bilibili"
static void printData(void *__data) {
    table_data *data = (table_data *)(__data);
    printf("%15s|%6d|%6d|%6.2lf|\n", 
        data->name, data->age, data->class, data->height
    );
}
static void scanData(void *__data) {
    table_data *data = (table_data *)(__data);
    scanf("%s%d%d%lf", 
        data->name, &(data->age),
        &(data->class), &(data->height)
    );
    return ;
}
