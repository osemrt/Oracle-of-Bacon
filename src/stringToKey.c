#include "main.h"

//A constant used in stringToKey()
//to calculate the key of a string
#define PRIME 31

//A function used to calculate a key for a given string
unsigned long long int stringToKey(char* str) {
	unsigned long long int key = 0;
	int i = strlen(str);
	int R = 1;

	while (i >= 0) {
		key = key + R * str[i];
		R = R * PRIME;
		i--;
	}

	return key;
}