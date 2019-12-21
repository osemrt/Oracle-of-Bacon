#include "..\inc\main.h"

int getNameFromFile(char* file, int filesize, int* i, char buffer[]) {

	char c = file[*i];
	int k = 0;
	while (*i < filesize && c != '\n' && c != '/') {
		buffer[k++] = c;
		(*i)++;
		c = file[*i];
	}
	buffer[k] = '\0';
	(*i)++;
	return c;
}
