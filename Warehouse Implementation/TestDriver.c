#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warehouse.h"
#include "item.h"

// Helper function to generate a random integer within a range
int getRandomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generateRandomString(char* str, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length - 1; ++i) {
        int index = rand() % (sizeof(charset) - 1);
        str[i] = charset[index];
    }
    str[length - 1] = '\0';
}

// Generate a random item BST with a given number of items
Item* generateRandomItemBST(int numItems) {
    Item* root = NULL;
    for (int i = 0; i < numItems; ++i) {
        int id = getRandomInt(1000, 9999); // Random ID between 1000 and 9999
        char* name[50];
        generateRandomString(&name, 10);
        int quantity = getRandomInt(1, 100); // Random quantity between 1 and 100
        Item* item = newItem(id, name, quantity); // Create a new item
        if (item != NULL) {
            insertItem(&root, item->id, item->name, item->quantity); // Insert the item into the BST
        }
    }
    return root;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Generate a random item BST with 5 items
    Item* root = generateRandomItemBST(5);

    // Display the generated item BST
    printf("Generated Item BST:\n");
    displayItems(root);

    // Free the memory allocated for the item BST
    // (Assuming you have implemented the necessary logic in the displayItems function to free memory)
    // freeItems(root);

    return 0;
}