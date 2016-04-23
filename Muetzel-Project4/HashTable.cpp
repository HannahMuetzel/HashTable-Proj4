#include "HashTable.h"

template <class T>
HashTable<T>::HashTable() {
	ht = new Record<T>[MAXHASH];	//array for hash table
	numItems = 0;					//initial number of items in hash table = 0
};

template<class T>
bool HashTable<T>::insert(int key, T value, int& collisions) {
	//check to see if the hashtable is full
	if (numItems == MAXHASH) {
		return false;
	}
	
	bool isInTable = false;
	for (size_t i = 0; i < MAXHASH; i++) {
		if (ht[i].getKey() == key) {
			isInTable = true;
		}
	}
	if (isInTable) {
		return false;
	}

	key = hashFunct(key);

	while (!ht[key].isEmpty() && collisions <= MAXHASH*2) {
		//standard double hashing equation
		key = hashFunct(key) + collisions * hashFunct2(key);
		key = key % MAXHASH;
		++collisions;
	}

	Record<T> rec(key, value);
	ht[key] = rec;
	++numItems;
	
	return true;
};

template <class T>
int HashTable<T>::hashFunct(int key) {
	//Hash formula is:
	//((((key*key)/2)+(key*key))/ digits of euler's constant)*digits of pi
	//HOWEVER, each time that key is called again outside of parentheses, it is the "new" key
	//meaning that the first key squared is not equal to the second key squared,
	//because each instance of key is called on a separate line (except for the key squared ones)
	//EULERS_CONSTANT and PI are #defined in HashTable.cpp file
	
	key = key*key;					//square key
	key = key / 2;					//divide key by 2
	key = key + (key*key);			//add key squared to key
	key = key / EULERS_CONSTANT;	//divide by euler's constant
	key = key * PI;					//multiply key by pi

	//right now, key is really freakin' big.
	//do a % operator so we only get the remainder of what big key number is / MAXHASH
	//this % operator should make it so that the key is within the range of 0 to 999.
	return (abs(key) % MAXHASH);
};

template <class T>
int HashTable<T>::hashFunct2(int key) {
	key = key >> 3;
	key = key % 164;
	return abs(key) % MAXHASH;
}

template <class T>
bool HashTable<T>::find(int key, T& value) {
	//iterate through the HashTable to see if the key is in the hashTable.
	//if it is, return true.
	//if it's not, return false.
	for (size_t i = 0; i < MAXHASH; i++) {
		if (ht[i].getKey() == key) {
			value = ht[i].getValue();
			return true;
		}
	}

	return false;
};

template <class T>
bool HashTable<T>::remove(int key) {
	//iterate through the hashtable
	//if the key is actually in the table then remove that record from the table
	//remove the record by setting the type to emptyRecord and the key to 0.
	//then return true
	//else return false and don't do anything

	for (size_t i = 0; i < MAXHASH; i++) {
		if (ht[i].getKey() == key) {
			ht[i].setType(emptyRecord);
			ht[i].setKey(0);
			return true;
		}
	}

	return false;
}

template <class T>
float HashTable<T>::alpha() {
	return (float)((float)numItems / (float)MAXHASH);
};

// Define template variables
template class HashTable<int>;
template class HashTable<double>;
template class HashTable<float>;