#include <stdio.h>
#include <stdlib.h>
#include "core/table.h"
#include "commands/create_table.h"
#include "utils/input_helpers.h"

void printMenu() {
    printf("\n-- SGBD ITP Menu --\n");
    printf("1. Create a new table\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int running = 1;
    int choice;

    while (running) {
        printMenu();
        if (getInt(&choice)) {
            switch (choice) {
                case 1:
                    {
                        Table* newTable = createTable();
                        if (newTable != NULL) {
                            // Add the created table to your database
                            // For now, just printing the table name
                            printf("Table '%s' created successfully.\n", newTable->name);
                            // Remember to free the allocated table when no longer needed
                            free(newTable);
                        } else {
                            printf("Failed to create table.\n");
                        }
                        break;
                    }
                case 2:
                    running = 0; // Exit the loop and end the program
                    break;
                default:
                    printf("Invalid option. Please try again.\n");
            }
        } else {
            printf("Error reading input. Please try again.\n");
        }
    }

    printf("Exiting SGBD ITP.\n");
    return 0;
}
