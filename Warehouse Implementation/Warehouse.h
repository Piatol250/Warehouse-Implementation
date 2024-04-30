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

#endif /* WAREHOUSE_H */