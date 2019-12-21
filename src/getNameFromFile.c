#include "..\inc\main.h"

char getNameFromFile(FILE* fp, char buffer[]) {

	int i = 0;
	//char c = getc(fp);
	fread(&c, sizeof(c), 1, fp);
	while (c != EOF && c != '\n' && c != '/') {
		buffer[i] = c;
		i++;
		c = getc(fp);
	}

	buffer[i] = '\0';

	return c;
}
