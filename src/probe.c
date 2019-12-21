#include "..\inc\main.h"

int probe(HashTable* hashTable, unsigned long long int key) {

	if (hashTable == NULL) {
		return INT_MIN;
	}

	int i = 0;
	int hashIndex;

	hashIndex = hash(key, i);
	while (hashTable->arr[hashIndex].status != EMPTY) {
		hashIndex = hash(key, ++i);
	}

	return hashIndex;

}