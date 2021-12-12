#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//I used one of the leetcode problem's code, that problem can be used to resolve this problem partially
int partition(vector<int>& vi, int low, int up)
{
	int pivot = vi[up];
	int i = low - 1;
	for (int j = low; j < up; j++)
	{
		if (vi[j] <= pivot)
		{
			i++;
			swap(vi[i], vi[j]);
		}
	}
	swap(vi[i + 1], vi[up]);
	return i + 1;
}

void quickSort(vector<int>& vi, int low, int up)
{
	if (low < up)
	{
		int mid = partition(vi, low, up);
		quickSort(vi, low, mid - 1);
		quickSort(vi, mid + 1, up);
	}
}

int  main() {
	int n = 0;
	cin >> n;
	vector<int> vec(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	quickSort(vec, 0, n - 1);
	if (vec.front() == vec.back()) {
		cout << 1;
		return 0;
	}

	deque<int> start(1, vec[0]);
	int pre_n = 0;
	int ret = 100001;
	int curr = vec[0];
	int curr_n = 1;
	for (int j = 1; j < n; j++) {
		if (j < n && vec[j] == curr) {
			++curr_n;
			if (curr_n > pre_n) {
				start.push_back(vec[j]);
			}
		}
		else {
			if (pre_n > curr_n) {
				for (int i = 0; i < pre_n - curr_n; i++) {
					int start1 = start.front();
					start.pop_front();
					ret = min(ret, vec[j - 1 - curr_n] - start1 + 1);
				}
			}
			if (j < n && curr + 1 != vec[j]) {
				int start1 = start.front();
				start.pop_front();
				ret = min(ret, vec[j - 1] - start1 + 1);
				start.push_back(vec[j]);
			}
			pre_n = curr_n;
			curr_n = 1;
			curr = vec[j];
		}
	}
	int j = n - 1;
	while (start.empty() == false) {
		ret = min(ret, vec[j--] - start.front() + 1);
		start.pop_front();
	}
	cout << ret;
	return 0;

}