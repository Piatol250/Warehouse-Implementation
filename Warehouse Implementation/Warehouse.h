#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "item.h"

typedef struct Warehouse {
    int id;
    char location[50];
    // Other warehouse attributes
    struct Item* root; // Root of BST of items in this warehouse
    struct Warehouse* next;
} Warehouse;

void insertWarehouse(Warehouse** head, int id, const char* location);
void addItemToWarehouse(Warehouse* warehouse, int id, const char* name, int quantity);
void displayWarehouses(Warehouse* head);
Warehouse* newWarehouse(int id, const char* location, Item* itemBSTRoot);

// Other warehouse-related function declarations

#endif /* WAREHOUSE_H */