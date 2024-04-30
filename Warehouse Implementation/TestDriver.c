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

void createAndInsertItem(Item** root, int id, const char* name, int quantity) {
    Item* item = newItem(id, name, quantity);
    insertItem(root, item->id, item->name, item->quantity);
}

// Generate a random item BST with a given number of items
Item* generateRandomItemBST(int numItems) {
    Item* root = NULL;
    for (int i = 0; i < numItems; ++i) {
        int id = getRandomInt(1000, 9999); // Random ID between 1000 and 9999
        char* name[50];
        generateRandomString(&name, 10);
        int quantity = getRandomInt(1, 100); // Random quantity between 1 and 100
        createAndInsertItem(&root, id, name, quantity);
        
    }
    return root;
}


void testSearchItems() 
{
    printf("Testing searchItem method with manual data:\n");
    Item* result;

    // Create an item BST with manual data
    Item* root = newItem(1000, "Item 0", 0);
    createAndInsertItem(&root, 1001, "Item 1", 10);
    createAndInsertItem(&root, 1002, "Item 2", 20);
    createAndInsertItem(&root, 1003, "Item 3", 30);
    createAndInsertItem(&root, 1004, "Item 4", 40);

    // Search for items
    printf("Searching for items:\n");
    searchItem(root, 1002); // Search for item with ID 1002
    searchItem(root, 1005); // Search for item with ID 1005 (not found)

    // Free memory allocated for the item BST
    freeItems(root);
}

void testItemMethods()
{
    srand(time(NULL)); // Seed the random number generator

    // Generate a random item BST with 5 items
    Item* root = generateRandomItemBST(5);

    // Display the generated item BST
    printf("Generated Item BST:\n");
    displayItems(root);
    freeItems(root);
    testSearchItems();
}

Warehouse* generateAndLinkRandomWarehouses(int numWarehouses, int numItems) {
    Warehouse* head = NULL;
    for (int i = 0; i < numWarehouses; ++i) {
        int id = getRandomInt(100, 999); // Random ID between 100 and 999
        char location[50];
        generateRandomString(&location, 10);
        Warehouse* warehouse = newWarehouse(id, location, generateRandomItemBST(numItems)); // Create a new warehouse
        if (warehouse != NULL) {
            warehouse->next = head; // Link the new warehouse to the head of the list
            head = warehouse; // Update the head to point to the new warehouse
        }
    }
    return head;
}

void testWarehouseMethods()
{
    Warehouse* testWarehouse;
    testWarehouse = generateAndLinkRandomWarehouses(10, 10);
    displayWarehouses(testWarehouse);
    addItemToWarehouse(testWarehouse, 75, "test", 200);
    displayWarhouse(testWarehouse, testWarehouse->id);
    
}

int main() {
    Warehouse* testWarehouse;
    //stestItemMethods();
    testWarehouseMethods();

    return 0;
}