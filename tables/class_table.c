/*************************************************************************
	> File Name: class_table.c
	> Author:cjw 
	> Mail:1293632174@qq.com 
	> Created Time: Mon 18 Mar 2024 07:48:33 PM CST
 ************************************************************************/

#include <stdio.h>
#include <database.h>
static const char *table_name = "class_table";
static const char *table_file = "./data/class_data.dat";
static const char *header_name[] = {"name", "No.Stu", "master"};
static int header_len[] = {15, 7, 15};
typedef struct Class {
    char name[20];
    int NoStu;
    char master[20];
} table_data;
#include "table_unit.bilibili"
static void printData(void *__data) {
    table_data *data = (table_data *)(__data);
    printf("%15s|%7d|%15s|\n", 
        data->name, data->NoStu, data->master
    );
}
static void scanData(void *__data) {
    table_data *data = (table_data *)(__data);
    scanf("%s%d%s", 
        data->name, &(data->NoStu),
        data->master);
    return ;
}
