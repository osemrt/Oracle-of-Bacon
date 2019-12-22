#include "../inc/main.h"

char* getFileFromUser(int* fileSize) {

	//Reading a file from the user						 
	FILE* fp;
	char* filePath = (char*)my_malloc(CHAR, 1024);
	do {

		printf("Drag and drop the dataset...\n");
		scanf("%s", filePath);

		fp = fopen(filePath, "rb");
		if (fp == NULL) {
			clearScreen();
			printf("Could not open file: %s\n", filePath);
		}

	} while (fp == NULL);

	char* file = NULL;

	/* Go to the end of the file. */
	if (fseek(fp, 0L, SEEK_END) == 0) {
		/* Get the size of the file. */
		long bufsize = ftell(fp);
		if (bufsize == -1) { 
			/* Error */
			fputs("Error reading file", stderr);
			*fileSize = -1;
		}
		else {

			/* Allocate our buffer to that size. */
			file = malloc(sizeof(char) * (bufsize + 1));
			*fileSize = (sizeof(char) * (bufsize + 1));

			/* Go back to the start of the file. */
			if (fseek(fp, 0L, SEEK_SET) != 0) { /* Error */ }

			/* Read the entire file into memory. */
			size_t newLen = fread(file, sizeof(char), bufsize, fp);
			if (newLen == 0) {
				fputs("Error reading file", stderr);
			}
			else {
				file[++newLen] = '\0'; /* Just to be safe. */
			}
		}

		fclose(fp);

	}

	

	return file;

}