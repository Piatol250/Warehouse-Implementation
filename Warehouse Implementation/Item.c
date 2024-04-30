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
            //Handles duplicates
            insertItem(root, id + 1, name, quantity);
            
        }
    }
}

Item* searchItem(Item* root, int id) {
    if (root == NULL || root->id == id) {
        if (root != NULL) {
            printf("Item with ID %d found. Name: %s, Quantity: %d\n", id, root->name, root->quantity);
        }
        else {
            printf("Item with ID %d not found.\n", id);
        }
        return root;
    }
    if (id < root->id) {
        return searchItem(root->left, id);
    }
    else {
        return searchItem(root->right, id);
    }
}

void displayItems(Item* root) {
    if (root != NULL) {
        displayItems(root->left); // Display left subtree
        printf("Item ID: %d, Name: %s, Quantity: %d\n", root->id, root->name, root->quantity);
        displayItems(root->right); // Display right subtree
    }
}

Item* newItem(int id, const char* name, int quantity) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    if (newItem == NULL) {
        printf("Memory allocation failed for new item.\n");
        return NULL;
    }
    newItem->id = id;
    strncpy(newItem->name, name, sizeof(newItem->name) - 1);
    newItem->name[sizeof(newItem->name) - 1] = '\0'; // Ensure null-terminated string
    newItem->quantity = quantity;
    newItem->left = NULL;
    newItem->right = NULL;
    return newItem;
}

void freeItems(Item* root) {
    if (root != NULL) {
        freeItems(root->left); // Free left subtree
        freeItems(root->right); // Free right subtree
        free(root); // Free current node
    }
}
