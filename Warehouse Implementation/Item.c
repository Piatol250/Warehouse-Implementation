#include <stdio.h>
#include <stdlib.h>
#include "item.h"

void insertItem(Item** root, int id, const char* name, int quantity) {
    if (*root == NULL) {
        // Create a new node
        *root = (Item*)malloc(sizeof(Item));
        if (*root == NULL) {
            printf("Memory allocation failed for new item.\n");
            return;
        }
        (*root)->id = id;
        strcpy((*root)->name, name);
        (*root)->quantity = quantity;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else {
        // Recursively insert based on ID
        if (id < (*root)->id) {
            insertItem(&((*root)->left), id, name, quantity);
        }
        else if (id > (*root)->id) {
            insertItem(&((*root)->right), id, name, quantity);
        }
        else {
            printf("Item with ID %d already exists.\n", id);
            // Handle duplicate IDs as needed
        }
    }
}