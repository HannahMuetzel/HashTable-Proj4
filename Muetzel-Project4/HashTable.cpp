#include "HashTable.h"

template <typename T> HashTable::HashTable() {
	ht = new Record<T>[MAXHASH];	//array for hash table
	capacity = 0;					//initial capacity of hash table = 0
};

int HashTable<T>::hashFunct(int key) {
	unsigned long hashKey = key;
	hashKey >> 3;
	key << 2;
	hashKey = hashKey & key;
	for (int i = key; i < hashKey; i++) {
		hashKey >> i;
		hashKey || i;
	};
	return hashKey;
};

bool HashTable<T>::find(int key, T& value) {
	//insert proper way to find once i FIND out what that really is (aha see what i did there?)
	
	int hashKey = 0;
	if ((ht[hashKey].getKey == key) && (ht[hashKey].getValue == value)) {
		return true;
	}
	else if (hashKey-1 > key) {
		for (int i = 1; i < MAXHASH; i++) {
			if ((ht[hashKey + i].getKey == key) && (ht[hashKey + i].getValue == value)) {
				return true;
			}
		}
	}
	else {
		for (int i = 1; i < MAXHASH; i++) {
			if ((ht[hashKey - i].getKey == key) && (ht[hashKey - i].getValue == value)) {
				return true;
			}
		}
	}
	return false;
};

float HashTable<T>::alpha() {
	float alpha = 0.0;
	alpha = (capacity / MAXHASH);
};