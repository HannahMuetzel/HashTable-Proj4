#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
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

	cout << "Actual size: " << size << endl;

	//Create test function to add random keys & keep track of number of collisions
	for (size_t n = 100; n <= 1000; n = n + 100) {
		for (size_t i = 0; i < MAXHASH; ++i) {
			collisions = 0;
			bool isGud = hashtable.remove(i);
			if (isGud) {
				--size;
			}
		}
		srand(MAXHASH);
		int random = rand() % 1000;
		vector<int> coll;
		for (size_t i = 0; i < n; ++i) {
			collisions = 0;
			bool isGud = hashtable.insert(i, random, collisions);
			if (isGud) {
				size++;
			}
			coll.push_back(collisions);
			//cout << "Inserted record with key " << i << "? " << isGud << endl;
			//cout << "Number of collisions: " << collisions << endl;
		}
		cout << "Attempted to insert " << n << " items." << endl;
		cout << "Actually inserted " << size << " items." << endl;

		int avg = 0;
		int denom = coll.size();
		for (size_t i = 0; i < MAXHASH; i++) {
			avg = avg + coll.at(i);
			coll.push_back(i);
		}
		avg = avg / denom;

		cout << "Average number of collisions for " << n << " inserts: " << avg << endl;
		cout << "The alpha value is: " << hashtable.alpha() << endl;
	}

	system("pause");
	return 0;
}

