#include "Record.h"

int hashFunct(int key) {
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

void main() {
	int key = 10;
	std::cout << "The key is " << key << " and the hashKey is " << hashFunct(key) << endl;
};