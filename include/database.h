/*************************************************************************
	> File Name: database.h
	> Author:cjw 
	> Mail:1293632174@qq.com 
	> Created Time: Sun 17 Mar 2024 05:49:52 PM CST
 ************************************************************************/

#ifndef _DATABASE_H
#define _DATABASE_H
struct Database;
typedef void(*InitTable_T)(struct Database *);
enum OP_TYPE {
    // 选择表
    CHOOSE_TABLE,
    // 操作表
    TABLE_USAGE,
    // 结束
    OP_END,
    // 增删改查
    LIST_TABLE,
    ADD_TABLE,
    MODIFY_TABLE,
    DELETE_TABLE
};

struct table_data {
    void *data;
    long offset;
    struct table_data *next;
};
struct Database {
    FILE *table;
    const char *table_name;
    const char *table_file;
    const char **header_name;
    int header_cnt;
    int *header_len;
    struct table_data head;// 虚拟头节点
    size_t (*getDataSize)();
    void (*printData)(void *);
    void (*scanData)(void *);
};
struct TableInfo {
    const char *table_name;
    InitTable_T init_table;
};
void run_database();
void register_table(const char *, InitTable_T);
static void __register_table();

extern struct Database db;
#endif
