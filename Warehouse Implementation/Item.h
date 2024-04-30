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
Item* searchItem(Item* root, int id); //Searches the BST for the item based on the given id and prints it if found, displaying an error message if not
void displayItems(Item* root); //Prints all items in the BST recursively
Item* newItem(int id, const char* name, int quantity); //Creates the head node for a new item BST
void freeItems(Item* root); //Frees all items in the BST

#endif /* ITEM_H */