#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../core/table.h"
#include "../utils/input_helpers.h"

Table* createTable() {
    char tableName[MAX_NAME_LEN];
    printf("Enter table name: ");
    getLine(tableName, MAX_NAME_LEN); // Assuming getLine is a utility function for input

    Table* newTable = (Table*)malloc(sizeof(Table));
    if (newTable == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }

    strncpy(newTable->name, tableName, MAX_NAME_LEN);
    newTable->numColumns = 0;
    newTable->primaryKeyIndex = -1;

    // Add code to input columns and set primary key
    // ...

    return newTable;
}

// Additional functions to add columns, set primary key, etc.
