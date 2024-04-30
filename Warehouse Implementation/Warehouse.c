#include <stdio.h>
#include <stdlib.h>
#include "warehouse.h"
#include "item.h"

void insertWarehouse(Warehouse** head, int id, const char* location) {
    Warehouse* newWarehouse = (Warehouse*)malloc(sizeof(Warehouse));
    if (newWarehouse == NULL) {
        printf("Memory allocation failed for new warehouse.\n");
        return;
    }
    newWarehouse->id = id;
    strcpy(newWarehouse->location, location);
    newWarehouse->root = NULL; // Initialize item BST root to NULL
    newWarehouse->next = *head;
    *head = newWarehouse;
}