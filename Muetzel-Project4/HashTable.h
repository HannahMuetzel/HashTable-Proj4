#pragma once
#include "Record.h"

#define MAXHASH 999
#define EULERS_CONSTANT 577	
#define PI 314159

template<class T>
class HashTable {

public:
	HashTable();
	bool insert(int key, T value, int& collisions);
	bool remove(int key);
	bool find(int key, T& value);
	float alpha();

	friend ostream& operator<< (ostream& out, const HashTable& hashtab) {
		for (size_t i = 0; i < MAXHASH; i++) {
			out << hashtab.ht[i] << " at the table position " << i << endl;
		}
		return out;
	};

	//The following functions should be private in common practice, but kept public for testing purposes.
	int hashFunct(int key);		//hash function
	int hashFunct2(int key);	//second hash function in order to do double hashing

private:
	int numItems;   //current number of items in the hash table.
	Record<T>* ht;

};