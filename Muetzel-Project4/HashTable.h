#pragma once
#define MAXHASH 1000
#include "Record.h"

class HashTable {

public:
	HashTable();
	//TODO: bool HashTable<T>::insert(int key, T value, int& collisions);
	//TODO: bool HashTable<T>::remove(int key);
	bool HashTable<T>::find(int key, T& value);
	float HashTable<T>::alpha();
	//TODO: overload operator <<

	template class HashTable<int>;

private:
	int capacity;   //current number of items in the hash table.
	int HashTable<T>::hashFunct(int key);	//hash function


};