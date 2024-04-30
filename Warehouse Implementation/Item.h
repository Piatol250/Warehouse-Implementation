#ifndef ITEM_H
#define ITEM_H

typedef struct Item {
    int id;
    char name[50];
    int quantity;
    struct Item* left;
    struct Item* right;
} Item;

void insertItem(Item** root, int id, const char* name, int quantity); //Finds the position in the BST based on the given id and inserts so the BST is sorted
Item* searchItem(Item* root, int id); //Searchs the BST for the given id, returning the object
void displayItems(Item* root); //Prints all items in the BST recursively
Item* newItem(int id, const char* name, int quantity);
void freeItems(Item* root); // Declaration for freeItems

#endif /* ITEM_H */