#ifndef ITEM_H
#define ITEM_H

typedef struct Item {
    int id;
    char name[50];
    int quantity;
    struct Item* left;
    struct Item* right;
} Item;

void insertItem(Item** root, int id, const char* name, int quantity);

#endif /* ITEM_H */