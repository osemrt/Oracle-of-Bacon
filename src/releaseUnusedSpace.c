#include "..\inc\main.h"

//A function to used to remove unused spaces
//in the given string
char* releaseUnusedSpace(char* str) {

	int i = 0;
	while (str[i++] != NULL)
		i++;

	//Total character count
	int count = i;
	char* newStr = (char*)my_malloc(CHAR, count + 1);
	strcpy(newStr, str);

	return newStr;
}