#include "..\inc\main.h"

char getNameFromFile(FILE* fp, char buffer[]) {

	int i = 0;

	char c = getc(fp);
	while (c != EOF && c != '\n' && c != '/') {
		c = getc(fp);
		buffer[i] = c;
		i++;
	}

	return c;
}
