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
	system("pause");
	return 0;
}

