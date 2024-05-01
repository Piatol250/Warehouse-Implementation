#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warehouse.h"
#include "item.h"
#include <time.h> 

Item* createItem()
{
	char name[50] = "test";
	int id;
	int quantity;

	printf("What is the name of the item?\n");
	scanf_s("%49s", &name, 50);
	printf("What is the id of the item?\n");
	scanf_s("%d", &id);
	printf("How many items are stored?\n");
	scanf_s("%d", &quantity);

	return newItem(id, name, quantity);
}

Warehouse* constructWarehouse(int insOrCreate, Warehouse* warehouse)
{
	char location[50] = "test";
	int id;
	Warehouse* result;

	printf("What is the warehouse location?\n");
	scanf_s("%49s", &location, 50);
	printf("What is the id of the warehouse?\n");
	scanf_s("%d", &id);
	result = newWarehouse(id, location, NULL);

	if(insOrCreate == 0)
	{
		return result;
	}
	else if(insOrCreate == 1)
	{
		insertWarehouse(warehouse, id, location);
		return NULL;
	}
}

void dataBaseConstructor()
{
	int mainChoice = NULL;
	int tempID = NULL;
	Warehouse* currentWarehouse = NULL;
	Item* currentItem = NULL;
	Warehouse* tempWarehouse;

	currentWarehouse = constructWarehouse(0, currentWarehouse);
	do 
	{
		printf("Do you want to:\n"
			"0. Quit?\n"
			"1. Add an item to a warehouse?\n"
			"2. Create a new warehouse?\n"
			"3. Display warehouses?\n");
		scanf_s("%d", &mainChoice);
		switch (mainChoice)
		{
		case 1:
			currentItem = createItem();
			printf("What is the id of the warehouse you want to add the item to?\n");
			scanf_s("%d", &tempID);
			tempWarehouse = findWarehouse(currentWarehouse, tempID);
			addItemToWarehouse(tempWarehouse, currentItem);
			break;
		case 2:
			constructWarehouse(1, &currentWarehouse);
			break;
		case 3:
			displayWarehouses(currentWarehouse);
			break;
		}
		
	} while (mainChoice != 0);

	return currentWarehouse;
}

int main()
{
	int mainChoice = NULL;
	Warehouse* currentWarehouse = NULL;

	do
	{
		printf("Do you want to build a warehouse or test the code?"
			"\n0. Quit\n1. Run the code testing module\n2. Build a warehouse\n");
		scanf_s("%d", &mainChoice);
		if (mainChoice == 1)
		{
			TestDriver();
		}
		else if (mainChoice == 2)
		{
			dataBaseConstructor();
		}

	} while (mainChoice != 0);

	return 0;
}