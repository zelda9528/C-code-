#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<assert.h>

#define NULLKEY -32679

int HASHSIZE = 20;

struct HashTable {
	int length;
	int* elem;
	int count;
	HashTable()
	{
		length = 0;
		elem = NULL;
		count = 0;
	}
};


void InitHashTable(HashTable* hashTable)
{
	hashTable->length = HASHSIZE;
	hashTable->elem = (int*)malloc(sizeof(int) * HASHSIZE);
	for (int i = 0; i < HASHSIZE; i++) {
		hashTable->elem[i] = NULLKEY;
	}
}


void FreeHashTable(HashTable* hashTable)
{
	free(hashTable->elem);
}


void SwapHashTable(HashTable* hashTableOne, HashTable* hashTableTwo)
{
	HashTable* p = hashTableOne;
	hashTableOne = hashTableTwo;
	hashTableTwo = p;
}


int HashAddress(int data)
{
	return data / HASHSIZE;
}


void AddHashTableCapacity(HashTable* hashTable)
{
	HASHSIZE *= 2;
	HashTable* newHashTable=new HashTable();
	newHashTable->length = HASHSIZE;
	newHashTable->elem = (int*)malloc(sizeof(int) * HASHSIZE);
	int hashAddress;
	for (int i = 0; i < HASHSIZE; i++) {
		hashAddress = HashAddress(hashTable->elem[i]);
		newHashTable->elem[hashAddress] = hashTable->elem[i];
	}
	SwapHashTable(hashTable, newHashTable);
	FreeHashTable(newHashTable);
}


bool DetectHashTable(HashTable* hashTable)
{
	if ((hashTable->count / HASHSIZE) * 10 > 7) {
		return true;
	}
	return false;
}


void Insert(HashTable *hashTable, int data)
{
	if (DetectHashTable(hashTable)) {
		AddHashTableCapacity(hashTable);
	}
	int hashAddress = HashAddress(data);
	while (hashTable->elem[hashAddress] != NULLKEY) {
		hashAddress = HashAddress(++hashAddress);
	}
	hashTable->elem[hashAddress] = data;
	hashTable->count++;
}


int Search(HashTable* hashTable, int target)
{
	int hashAddress = HashAddress(target);
	while (hashTable->elem[hashAddress] != target) {
		hashAddress = HashAddress(++hashAddress);
		if ((hashTable->elem[hashAddress] == NULLKEY) && (hashAddress == HashAddress(target))) {
			return -1;
		}
	}
	return hashAddress;
}


void ShowHashTable(HashTable* hashTable)
{
	for (int i = 0; i < hashTable->length; i++) {
		printf("%5d", hashTable->elem[i]);
		if ((i + 1) % 10 == 0) {
			printf("\n");
		}
	}
	printf("\n");
}


int main()
{
	HashTable* hashTable=new HashTable();
	InitHashTable(hashTable);
	ShowHashTable(hashTable);
	return 0;
}

