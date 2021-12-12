#include <iostream>
using namespace std;
int result(int power) {
	int result = 0;
	//Create a list of power, notice:start from 0, so as long as we get the number on each digit, it can be directly used as the index.
	int pow[10] = { 6,2,5,5,4,5,6,3,7,6 };
	//poweri and powerj are two numbers that added togther, and powerk is the sum
	int poweri = 0;
	int powerj = 0;
	int powerk = 0;
	//If power is smaller than 10, it's impossible
	if (power < 10) {
		return 0;
	}

	else {
		power = power - 4;
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 1000; j++) {

				int k = i + j;
				//single digits
				poweri = pow[i % 10];
				powerj = pow[j % 10];
				powerk = pow[k % 10];
				//tens digit
				if (i >= 10) {
					poweri += pow[(i - i % 10) % 100 / 10];
				}
				//hundreds digit
				if (i >= 100) {
					poweri += int(pow[i / 100]);
				}

				if (j >= 10) {
					powerj += pow[(j - j % 10) % 100 / 10];
				}

				if (j >= 100) {
					powerj += pow[j / 100];
				}
				//Calculate the single digits, the tens digits, the hundred digits of the sum
				if (k >= 10) {
					powerk += pow[(k - k % 10) % 100 / 10];
				}
				if (k >= 100) {
					powerk += pow[(k - k % 100) % 1000 / 100];
				}
				if (k >= 1000) {
					powerk += pow[k / 1000];
				}

				if (poweri + powerj + powerk == power) {
					result += 1;
				}
			}
		}

	}

	return result;

}


int main() {
	int power;
	cin >> power;
	cout << result(power) << " ";

}