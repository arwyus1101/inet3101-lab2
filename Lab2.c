#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 50
#define METRIC_SIZE 10

// Define the structure to hold a part record.
typedef struct {
    int partNumber;
    char partName[NAME_SIZE];
    float partSize;
    char partSizeMetric[METRIC_SIZE];
    float partCost;
} Part;

// Function to display the menu.
void printMenu() {
    printf("\nMENU\n");
    printf("======\n");
    printf("1. Print all records\n");
    printf("2. Print number of records\n");
    printf("3. Print size of database\n");
    printf("4. Add record\n");
    printf("5. Delete record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Function to print all records.
void printRecords(Part *database, int count) {
    if (count == 0) {
        printf("No records available.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Record %d:\n", i + 1);
        printf("  Part Number: %d\n", database[i].partNumber);
        printf("  Part Name: %s\n", database[i].partName);
        printf("  Part Size: %.2f %s\n", database[i].partSize, database[i].partSizeMetric);
        printf("  Part Cost: %.2f\n", database[i].partCost);
        printf("\n");
    }
}

// Function to print the number of records.
void printNumberOfRecords(int count) {
    printf("Number of records: %d\n", count);
}

// Function to print the current size (in bytes) of the database.
void printDatabaseSize(int count) {
    printf("Size of database: %lu bytes\n", count * sizeof(Part));
}

// Function to add a record to the database.
void addRecord(Part **database, int *count) {
    Part newRecord;
    
    // Prompt and get data for the new record.
    printf("Enter Part Number (integer): ");
    scanf("%d", &newRecord.partNumber);
    
    printf("Enter Part Name: ");
    scanf(" %[^\n]s", newRecord.partName);  // Reads a line including spaces

    printf("Enter Part Size (float): ");
    scanf("%f", &newRecord.partSize);

    printf("Enter Part Size Metric: ");
    scanf(" %[^\n]s", newRecord.partSizeMetric);

    printf("Enter Part Cost (float): ");
    scanf("%f", &newRecord.partCost);

    // Resize the database to hold one more record.
    Part *temp = realloc(*database, ((*count) + 1) * sizeof(Part));
    if (temp == NULL) {
        printf("Error reallocating memory. Record not added.\n");
        return;
    }
    *database = temp;
    (*database)[*count] = newRecord;
    (*count)++;
    printf("Record added successfully.\n");
}

// Function to delete the last record from the database.
void deleteRecord(Part **database, int *count) {
    if (*count == 0) {
        printf("No records to delete.\n");
        return;
    }
    (*count)--;
    // If no records remain, free the memory.
    if (*count == 0) {
        free(*database);
        *database = NULL;
    } else {
        Part *temp = realloc(*database, (*count) * sizeof(Part));
        if (temp == NULL) {
            printf("Error reallocating memory after deletion.\n");
            // In case of error, revert the deletion.
            (*count)++;
            return;
        }
        *database = temp;
    }
    printf("Record deleted successfully.\n");
}

int main() {
    Part *database = NULL;  // Pointer to the dynamic database
    int count = 0;          // Number of records currently stored
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printRecords(database, count);
                break;
            case 2:
                printNumberOfRecords(count);
                break;
            case 3:
                printDatabaseSize(count);
                break;
            case 4:
                addRecord(&database, &count);
                break;
            case 5:
                deleteRecord(&database, &count);
                break;
            case 6:
                printf("Exiting program.\n");
                free(database);
                return 0;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    }
    return 0;
}