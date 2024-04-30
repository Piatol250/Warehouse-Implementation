#ifndef ITEM_H
#define ITEM_H

typedef struct Item {
    int id;
    char name[50];
    int quantity;
    // Other item attributes
    struct Item* left;
    struct Item* right;
} Item;

#endif /* ITEM_H */