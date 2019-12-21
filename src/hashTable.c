#include "../inc/main.h"

HashTable* ht_create(int size) {
	HashTable* hashTable = (HashTable*)my_malloc(HASH_TABLE, 1);
	hashTable->arr = (Entry*)my_malloc(ENTRY, size);
	hashTable->size = size;

	int i;
	for (i = 0; i < hashTable->size; i++) {
		hashTable->arr[i].status = EMPTY;
		hashTable->arr[i].hashNode = (HashNode*)my_malloc(HASH_NODE, 1);
		hashTable->arr[i].hashNode->key = (Key*)my_malloc(KEY, 1);
		hashTable->arr[i].hashNode->key->str = "";
		hashTable->arr[i].hashNode->key->value = INT_MIN;
	}

	return hashTable;

}

Entry* ht_search(HashTable* hashTable, Key* key) {

	if (hashTable == NULL) {
		return NULL;
	}

	int i = 0;
	int hashIndex = hash(key->value, i);

	while (hashTable->arr[hashIndex].status != EMPTY &&
		strcmp(hashTable->arr[hashIndex].hashNode->key->str, key->str) != 0) {
		hashIndex = hash(key->value, ++i);
	}

	if (hashTable->arr[hashIndex].status != DELETED &&
		strcmp(hashTable->arr[hashIndex].hashNode->key->str, key->str) == 0) {
		return &hashTable->arr[hashIndex];
	}

	return NULL;

}

void ht_put(HashTable* hashTable, Key* key, int value) {

	int i = 0;
	int hashIndex = hash(key->value, i);

	while (hashTable->arr[hashIndex].status == OCCUPIED) {
		hashIndex = hash(key->value, ++i);
	}

	hashTable->arr[hashIndex].status = OCCUPIED;
	hashTable->arr[hashIndex].hashNode->key = key;
	hashTable->arr[hashIndex].hashNode->value = value;
}

int ht_get(HashTable* hashTable, Key* key) {
	Entry* entry = ht_search(hashTable, key);
	if (entry == NULL) {
		return INT_MIN;
	}
	return entry->hashNode->value;
}

int ht_delete(HashTable* hashTable, Key* key) {

	Entry* entry = ht_search(hashTable, key);

	if (entry == NULL) {
		return FALSE;
	}

	entry->status = DELETED;
	return TRUE;

}

void ht_print(HashTable* hashTable) {

	printf("\nPrinting hashTable...\n");
	int i;
	for (i = 0; i < hashTable->size; i++) {
		if (hashTable->arr[i].status == OCCUPIED) {
			printf("%d: (%s, %d)\n", i, hashTable->arr[i].hashNode->key->str, hashTable->arr[i].hashNode->value);
		}
		else if (hashTable->arr[i].status == EMPTY) {
			printf("%d: %s\n", i, "EMPTY!");
		}
		else {
			printf("%d: %s\n", i, "DELETED!");
		}
	}


}