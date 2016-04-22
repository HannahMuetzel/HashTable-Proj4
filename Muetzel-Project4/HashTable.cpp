#include "HashTable.h"
#define EULERS_CONSTANT 577	
#define PI 314159

template <typename T> HashTable::HashTable() {
	ht = new Record<T>[MAXHASH];	//array for hash table
	capacity = 0;					//initial capacity of hash table = 0
};

int HashTable<T>::hashFunct(int key) {
	//Hash formula is:
	//((((key*key)/2)+(key*key))/ digits of euler's constant)*digits of pi
	//HOWEVER, each time that key is called again outside of parentheses, it is the "new" key
	//meaning that the first key squared is not equal to the second key squared
	//EULERS_CONSTANT and PI are #defined in HashTable.cpp file
	
	key = key*key;					//square key
	key = key / 2;					//divide key by 2
	key = key + (key*key);			//add key squared to key
	key = key / EULERS_CONSTANT;	//divide by euler's constant
	key = key * PI;					//multiply key by pi

	//right now, key is really freakin' big.
	//do a % operator so we only get the remainder of what big key number is / MAXHASH
	//this % operator should make it so that the key is within the range of 0 to 999.
	return (key % MAXHASH);
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