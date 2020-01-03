#include "main.h"

void showMenu() {


	char* path[MAX_SIZE];
	char* actor1;
	char* actor2;
	int distance;
	int choice;
	int c;
	//a flag is used to prevent the wrong choices of the user
	int FLAG = FALSE;
	do
	{
		clearScreen();
		printf("\n\n");
		printf("\tMENU");
		printf("\n------------------------------\n");
		printf("1:Add the dataset");
		printf("\n2:Find Kevin-Bacon number of an actress/actors");
		printf("\n3:Find the distance of two actresses/artists");
		printf("\n4:Print hash table");
		printf("\n5:Exit");
		printf("\n------------------------------\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:

			clearScreen();
			int fileSize;
			char* file = getFileFromUser(&fileSize);
			parseFile(file, fileSize);
			FLAG = TRUE;

			printf("\nPress any key to continue...\n\n");

			while ((c = getchar()) != '\n' && c != EOF);
			getchar();

			break;
		case 2:
			while ((c = getchar()) != '\n' && c != EOF); 
			clearScreen();

			if (FLAG == TRUE) {
				actor1 = readNameFromUser();
				actor2 = "Bacon, Kevin";
				distance = computeDistance(actor1, actor2, path, TRUE);
				if (distance == -1) {
					printf("The given actor/actress is too far from the Kevin-Bacon (distance>6)...\n");
				}
				else {
					printResults(actor1, actor2, path, distance);
				}
				printf("\nPress any key to continue...\n\n");
				getchar();

				resetGraph(graph);
				
			}
			else {
				printf("You have do not yet added any dataset...");
			}

			break;
		case 3:
			while ((c = getchar()) != '\n' && c != EOF);
			clearScreen();
			if (FLAG == TRUE) {
				printf("First: ");
				actor1 = readNameFromUser();
				printf("Second: ");
				actor2 = readNameFromUser();
				distance = computeDistance(actor1, actor2, path, FALSE);
				printResults(actor1, actor2, path, distance);

				printf("\nPress any key to continue...\n\n");

				while ((c = getchar()) != '\n' && c != EOF);

				resetGraph(graph);

			}
			else {
				printf("You have do not yet added any dataset...");
			}



			break;
		case 4:
			clearScreen();
			if (FLAG == TRUE) {
				ht_print(hashTable);
			}
			else {
				printf("You have do not yet added any dataset...");
			}
			break;
		case 5:
			exit(0);
			break;
		default:
			clearScreen();
			printf("Invalid Input. Please Enter valid Input... ");
		}
	} while (choice != 5);

	return;
}