#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../src/core/table.h"
#include "../src/commands/create_table.h"  // Adjust path as needed
#include "../src/utils/input_helpers.h" // Adjust path as needed
//#include "../src/commands/create_table.c" // Adjust the path as needed

// Test for valid table creation
void testCreateTableValid() {
    Table* t = createTable("ValidTable");
    assert(t != NULL);
    assert(strcmp(t->name, "ValidTable") == 0);
    // Add more assertions here if needed, for example, checking the number of columns or primary key

    // Free the allocated table after test
    free(t);
}

// Test for invalid table name (empty string)
void testCreateTableInvalidName() {
    Table* t = createTable("");
    assert(t == NULL);
    // If your function prints an error, you might not be able to assert this in a simple setup. 
    // In a more advanced setup, you could redirect stdout to capture and assert the output

    // If t is not NULL, remember to free it
    if (t) {
        free(t);
    }
}

int main() {
    testCreateTableValid();
    testCreateTableInvalidName();
    printf("All tests passed.\n");
    return 0;
}
