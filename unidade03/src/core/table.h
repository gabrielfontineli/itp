#ifndef TABLE_H
#define TABLE_H

#include <stdint.h> // For uint32_t

#define MAX_COLUMNS 10
#define MAX_NAME_LEN 50
#define MAX_COL_NAME_LEN 50

typedef enum { TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_STRING } DataType;

typedef struct {
    char name[MAX_COL_NAME_LEN];
    DataType type;
} Column;

typedef struct {
    char name[MAX_NAME_LEN];
    int numColumns;
    Column columns[MAX_COLUMNS];
    uint32_t primaryKeyIndex; // Index of the primary key column
} Table;

#endif // TABLE_H
