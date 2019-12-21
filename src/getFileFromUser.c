#include "../inc/main.h"

FILE* getFileFromUser() {
	
	//Reading a file from the user						 
	FILE* fp;														 
	char* filePath = (char*)my_malloc(CHAR, 300);	 
	do {															 
																	 
		printf("Drag and drop samples.txt\n");						 
		scanf("%s", filePath);
																	 
		fp = fopen(filePath, "r");
		if (fp == NULL) {											 
			clearScreen();											 
			printf("Could not open file: %s\n", filePath);
		}															 
																	 
	} while (fp == NULL);											 
	

}