#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<vector<int>> mat(n, vector<int>(n, 0));
	
	//initialize;
	int* sumro = new int[n]{0};
	int maxsum;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	maxsum = mat[0][0];
	//Add up all the possilbe column elements into a 1-D array.
	for (int i = 0; i < n; i++) {
		int* sumco = new int[n] {0};
		for (int j = i; j < n; j++) {
			for (int m = 0; m < n; m++) {
				sumco[m] += mat[j][m];
			}
			sumro[0] = sumco[0];
			if (maxsum < sumro[0]) {
				maxsum = sumro[0];
			}
			else {
				maxsum = maxsum;
			}
			for (int m = 1; m < n; m++) {
				sumro[m] = max(sumco[m], sumro[m - 1] + sumco[m]);
				maxsum = max(sumro[m],maxsum);
			}
		}
	}
	cout << maxsum << " ";
}