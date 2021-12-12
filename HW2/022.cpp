
#include <iostream>
using namespace std;

int largest_pow_of_2(int x) {
	int i = 1;
	while (i <= x) {
		i = 2 * i;
	}
	return i/2;
}

int main() {
	int x = 0;
	cin >> x;
	cout << largest_pow_of_2(x);
	return 0;
}