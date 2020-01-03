#include "main.h"

int hash(unsigned long long int key, int i) {
	return (hash1(key) + i * hash2(key)) % hashTable->size;
}

unsigned long long int hash1(unsigned long long int key) {
	int M = hashTable->size;
	return key % M;
}

int hash2(unsigned long long int key) {
	int MM = hashTable->size - 1;
	return 1 + (key % MM);
}