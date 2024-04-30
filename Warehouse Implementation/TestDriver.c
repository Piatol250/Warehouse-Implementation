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
    Item* result;

    // Create an item BST with manual data
    Item* root = newItem(1000, "Item 0", 0);
    createAndInsertItem(&root, 1001, "Item 1", 10);
    createAndInsertItem(&root, 1002, "Item 2", 20);
    createAndInsertItem(&root, 1003, "Item 3", 30);
    createAndInsertItem(&root, 1004, "Item 4", 40);

    // Search for items
    searchItem(root, 1002); // Search for item with ID 1002
    searchItem(root, 1005); // Search for item with ID 1005 (not found)

    // Free memory allocated for the item BST
    freeItems(root);
}

void testItemMethods()
{
    srand(time(NULL)); // Seed the random number generator

    printf("Create a BST of 5 items, which tests newItem(), insertItem(), and displayItems():\n");
    // Generate a random item BST with 5 items
    Item* root = generateRandomItemBST(5);
    displayItems(root);
    freeItems(root);
    printf("\nCreates manual data for a new BST of 5 items and searches for items with id 1002 and 1005, tests searchItem():\n");
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
    printf("Create 10 random warehouses with 10 random items, tests newWarehouse() and displayWarehouses():\n");
    testWarehouse = generateAndLinkRandomWarehouses(10, 10);
    displayWarehouses(testWarehouse);
    printf("\n");
    printf("Add a item to a warehouse, which tests addItemToWarehouse() and displayWarehouse():\n");
    addItemToWarehouse(testWarehouse, 75, "test", 200);
    displayWarhouse(testWarehouse, testWarehouse->id);
    
}

int main() {
    int choice = NULL;
    Warehouse* testWarehouse;

    do 
    {
        printf("Functionality or time?\n");
        printf("0: quit\n1: function \n2: time\n");
        scanf_s("%d", &choice);
        if (choice == 1)
        {
            printf("Which data type?\n");
            printf("1. Item (BST)\n2. Warehouse(Linked List)\n");
            scanf_s("%d", &choice);
            if (choice == 1) 
            {
                testItemMethods();
            }
            else if(choice == 2)
            {
                testWarehouseMethods();
            }
        }
        else if (choice == 2)
        {

        }

    } while (choice != 0);

    return 0;
}