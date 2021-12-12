#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int table_size = 20000003;
int PRIME = 999991;
int invalid = -1E9 - 1;
//use a big prime number as table-size


vector<int> hashtable(table_size, invalid);

//Hashing
int hashing(int key, int i) {
	size_t address1 = key % table_size;
	unsigned address2 = PRIME - (key % PRIME);
	unsigned  final = (address1 + i * address2) % table_size;
	return final;
}
//Insert
void insert(vector<int>& table, int key) {
	int probe = 0;
	while (true) {
		int address = hashing(key, probe);
		if (table[address] == invalid) {
			table[address] = key;
			break;
		}
		else if (table[address] == key) {
			break;
		}
		else {
			probe++;
		}
	}

}
//Find
bool find(int key) {
	int prob = 0;
	while (hashtable[hashing(key, prob)] != invalid) {
		if (hashtable[hashing(key, prob)] == key) {
			return true;
		}
		else {
			++prob;
		}
	}
	return false;

}


int main() {
	int n;
	int ret = 0;
	cin >> n;
	vector <int> arr;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);

		for (int j = 0; j < i; j++) {
			if (find(arr[i] - arr[j])) {
				++ret;
				break;
			}
		}
		for (int m = 0; m <= i; m++) {
			insert(hashtable, arr[i] + arr[m]);
		}


	}
	cout << ret;
	return 0;
}




	
