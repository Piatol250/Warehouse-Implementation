#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warehouse.h"
#include "item.h"
#include <time.h> 

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
Item* generateRandomItems(int numItems) {
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
    Item* root = generateRandomItems(5);
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
        Warehouse* warehouse = newWarehouse(id, location, generateRandomItems(numItems)); // Create a new warehouse
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
    printf("Add an item to a warehouse (name: test, id: 75, quantity: 200, which tests addItemToWarehouse() and displayWarehouse():\n");
    addItemToWarehouse(testWarehouse, 75, "test", 200);
    displayWarhouse(testWarehouse, testWarehouse->id);
    freeWarehouses(testWarehouse);
}

void itemCreationPerformance(int numItems)
{
    clock_t start, end;
    double cpu_time_used;
    Item* root;

    start = clock();

    root = generateRandomItems(numItems);

    end = clock();

    cpu_time_used = ((double)(end - start))/1000;
    printf("Time taken to create item BST with %d items: %f seconds\n", numItems, cpu_time_used);
    freeItems(root);
}

void itemSearchPerformance(int numIts)
{
    clock_t start, end;
    double cpu_time_used;
    Item* root;
    int id = getRandomInt(1000, 9999); // Random ID between 1000 and 9999

    root = generateRandomItems(numIts);

    start = clock();

    searchItem(root, id);

    end = clock();

    cpu_time_used = ((double)(end - start)) / 1000;
    printf("Time taken to search for %d items: %f seconds\n", numIts, cpu_time_used);
    freeItems(root);
}

void itemInsertPerformance(int numIts) 
{
    clock_t start, end;
    double cpu_time_used;
    Item* root;
    int id = NULL;
    char name[50];
    int quantity = NULL;

    root = generateRandomItems(1);

    start = clock();

    for(int currIt = 0; currIt < numIts; currIt++)
    {
        id = getRandomInt(1000, 9999); // Random ID between 1000 and 9999
        generateRandomString(&name, 10);
        quantity = getRandomInt(1, 100);
        insertItem(&root, id, name, quantity);   
    }

    end = clock();

    cpu_time_used = ((double)(end - start)) / 1000;
    printf("Time taken to insert %d items: %f seconds\n", numIts, cpu_time_used);
    freeItems(root);
}

void warehouseCreationPerformance(int numWar)
{
    clock_t start, end;
    double cpu_time_used;
    Warehouse* warehouse;

    start = clock();

    warehouse = generateAndLinkRandomWarehouses(numWar, 0);

    end = clock();

    cpu_time_used = ((double)(end - start)) / 1000;
    printf("Time taken to create warehouse list with %d warehouses: %f seconds\n", numWar, cpu_time_used);
    freeWarehouses(warehouse);
}

void warehouseSearchPerformance(int numWar)
{
    clock_t start, end;
    double cpu_time_used;
    Warehouse* warehouse = generateAndLinkRandomWarehouses(numWar, 0);
    int id = getRandomInt(1000, 9999); // Random ID between 1000 and 9999
    

    start = clock();

    displayWarhouse(warehouse, id);

    end = clock();

    cpu_time_used = ((double)(end - start)) / 1000;
    printf("Time taken find and display warehouse in warehouse list with %d items: %f seconds\n", numWar, cpu_time_used);
    freeWarehouses(warehouse);
}

void warehouseInsertPerformance(int numInsert)
{
    clock_t start, end;
    double cpu_time_used;
    Warehouse* warehouse = generateAndLinkRandomWarehouses(1, 0);
    int id = NULL;
    char location[50];

    start = clock();

    for (int currWar = 0; currWar < numInsert; currWar++)
    {
        id = getRandomInt(1000, 9999);
        generateRandomString(&location, 10);
        insertWarehouse(warehouse, id, location);
    }

    end = clock();

    cpu_time_used = ((double)(end - start)) / 1000;
    printf("Time insert %d warehouses into warehouse list: %f seconds\n", numInsert, cpu_time_used);
    freeWarehouses(warehouse);
}



void TestDriver() {
    int choice = NULL;
    int iterations = NULL;

    do 
    {  
        printf("Functionality or performance?\n");
        printf("0: quit\n1: function \n2: time\n");
        scanf_s("%d", &choice);
        if (choice == 1)
        {
            printf("Which data type?\n");
            printf("1. Item (BST)\n2. Warehouse (Linked List)\n");
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
            printf("How many iterations?\n");
            scanf_s("%d", &iterations);
            printf("Which data type?\n");
            printf("1. Item (BST)\n2. Warehouse (Linked List)\n");
            scanf_s("%d", &choice);
            if (choice == 1) 
            {
                printf("Which method?\n");
                printf("1. Creation\n2. Search\n3. Insert\n");
                scanf_s("%d", &choice);
                switch(choice)
                {
                    case 1: 
                        itemCreationPerformance(iterations);
                        break;
                    case 2:
                        itemSearchPerformance(iterations);
                        break;
                    case 3:
                        itemInsertPerformance(iterations);
                }
            }
            else if (choice == 2) 
            {
                printf("Which method?\n");
                printf("1. Creation\n2. Search\n3. Insert\n");
                scanf_s("%d", &choice);
                switch (choice)
                {
                case 1:
                    warehouseCreationPerformance(iterations);
                    break;
                case 2:
                    warehouseSearchPerformance(iterations);
                    break;
                case 3:
                    warehouseInsertPerformance(iterations);
                }
            }
        }

    } while (choice != 0);

    return 0;
}