#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warehouse.h"
#include "item.h"
#include <time.h> 



int main()
{
	int mainChoice = NULL;
	do
	{
		printf("Do you want to build a warehouse or test the code?"
			"\n1. Test code\n2. Build warehouse\n");
		scanf_s("%d", &mainChoice);
		if (mainChoice == 1)
		{
			TestDriver();
		}
		else if (mainChoice == 2)
		{

		}

	} while (mainChoice != 0);

	return 0;
}