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

void addItemToWarehouse(Warehouse* warehouse, int id, const char* name, int quantity) {
    if (warehouse == NULL) {
        printf("Warehouse does not exist.\n");
        return;
    }
    insertItem(&(warehouse->root), id, name, quantity);
}

void displayWarehouses(Warehouse* head) {
    Warehouse* current = head;
    while (current != NULL) {
        printf("Warehouse ID: %d, Location: %s\n", current->id, current->location);
        // Display items in this warehouse
        displayItems(current->root);
        current = current->next;
    }
}

Warehouse* newWarehouse(int id, const char* location, Item* itemBSTRoot) {
    Warehouse* newWarehouse = (Warehouse*)malloc(sizeof(Warehouse));
    if (newWarehouse == NULL) {
        printf("Memory allocation failed for new warehouse.\n");
        return NULL;
    }
    newWarehouse->id = id;
    strcpy(newWarehouse->location, location);
    newWarehouse->root = itemBSTRoot; // Use the provided item BST root
    newWarehouse->next = NULL;
    return newWarehouse;
}

void displayWarhouse(Warehouse* head, int id)
{
    Warehouse* currentWarehouse = head;
    while (currentWarehouse != NULL) {
        if (currentWarehouse->id == id) {
            printf("Warehouse ID: %d, Location: %s\n", currentWarehouse->id, currentWarehouse->location);
            displayItems(currentWarehouse->root);
            return; // Found warehouse, no need to continue searching
        }
        currentWarehouse = currentWarehouse->next;
    }
    printf("Warehouse with ID %d not found.\n", id);
}