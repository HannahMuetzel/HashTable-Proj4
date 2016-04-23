#include <iostream>
#include <iomanip>
#include "HashTable.h"

using namespace std;

int main()
{

	HashTable<int> hashtable;

	int inc = 0;
	int dec = 0;
	int ninehun = 0;
	int onehun = 0;
	for (int i = 0; i < MAXHASH; i++) {
		int hashed = hashtable.hashFunct(i);
		if (hashed > 500) {
			inc++;
		}
		if (hashed <= 500) {
			dec++;
		}
		if (hashed > 900) {
			ninehun++;
		}
		if (hashed < 100) {
			onehun++;
		}
		cout << i << "----------" << hashed << endl;
	}

	cout << "Keys above 500: " << inc << " | Keys less than 500: " << dec << " | Keys above 900: " << ninehun << " | Keys below 100: " << onehun << endl;
	int collisions = 0;
	int size = 0;
	for (size_t i = 0; i < MAXHASH; ++i) {
		collisions = 0;
		bool isGud = hashtable.insert(i, MAXHASH - i, collisions);
		if (isGud) {
			size++;
		}
		cout << "Inserted? " << isGud << endl;
		cout << "Number of collisions: " << collisions << endl;
		cout << "Actual size: " << size << endl;
	}

	collisions = 0;
	hashtable.insert(777, 11025101160059, collisions);
	int newVal = 0;
	bool isFound = hashtable.find(777, newVal);
	cout << "777 is found? " << isFound << endl;
	bool isGone = hashtable.remove(777);
	cout << "777 is gone? " << isGone << endl;
	isFound = hashtable.find(777, newVal);
	cout << "777 is found? (Should return false): " << isFound << endl;

	cout << "How bad is your hashtable? " << hashtable.alpha() << endl;

	system("pause");
	return 0;
}

