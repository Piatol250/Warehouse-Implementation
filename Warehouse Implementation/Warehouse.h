#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "item.h"

typedef struct Warehouse {
    int id;
    char location[50];
    struct Item* root; // Root of BST of items in this warehouse
    struct Warehouse* next;
} Warehouse;

void insertWarehouse(Warehouse** head, int id, const char* location); //Adds a warehouse to the given linked list
void addItemToWarehouse(Warehouse* warehouse, Item* item); //Adds an item to the item BST of the given warehouse
void displayWarehouses(Warehouse* head); //Displays all warehouses in the given linked list
void displayWarhouse(Warehouse* head, int id); //Displays a warehouse based on the id given
Warehouse* newWarehouse(int id, const char* location, Item* itemBSTRoot); //Creates a new warehouse object based on the inputs
void freeWarehouses(Warehouse* head); //Clears the memory for all warehouses in the linked list along with all item BSTs 
Warehouse* findWarhouse(Warehouse* head, int id);

// Other warehouse-related function declarations

#endif /* WAREHOUSE_H */