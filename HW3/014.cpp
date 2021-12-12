#include <iostream>
#include <vector>

using namespace std;
/*
Here's the general idea of this problem, we add up k largest number within this input, then we decide whether if it's odd number, if it is, then we directly return it. if it doesn't, then we 
need to either remove the smallest even number within this k and add up the largest odd number outside this k or we remove the smallest odd number within this k and add up the largest even number outside
of this k.
*/
bool is_odd(long long n) {
    if (n % 2 != 0) {
        return true;
    }
    else {
        return false;
    }

}
int partition(int a[], int l, int r)
{
    int i = l;
    int j = r + 1;
    int v = a[l];

    while (true) {
        while (a[--j] > v);
        while (i < j && a[++i] < v);

        if (i == j)
        {
            break;
        }
        std::swap(a[i], a[j]);
    }

    std::swap(a[i], a[l]);

    return i;
}

void qsort(int a[], int l, int r)
{
    if (l < r) {
        int m = partition(a, l, r);
        qsort(a, l, m - 1);
        qsort(a, m + 1, r);
    }
}

int main() {
    int n, m;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> m;
    vector<int> ks(m, 0);
    for (int j = 0; j < m; j++) {
        cin >> ks[j];
    }
    qsort(nums.data(), 0, n - 1);
    vector<int> upper_evens(n, -1);
    vector<int> upper_odds(n, -1);
    int ei = -1;
    int oi = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (is_odd(nums[i])) {
            oi = i;
        }
        else {
            ei = i;
        }
        upper_evens[i] = ei;
        upper_odds[i] = oi;
    }
    vector<int> lower_evens(n, -1);
    vector<int> lower_odds(n, -1);
    int ei1 = -1;
    int oi1 = -1;
    for (int i = 0; i < n; i++) {
        if (is_odd(nums[i])) {
            oi1 = i;
        }
        else {
            ei1 = i;
        }
        lower_evens[i] = ei1;
        lower_odds[i] = oi1;
    }
    vector<long long> cache(n, 0);
    long long sum0 = 0;
    for (int i = n - 1; i > 0; i--) {
        sum0 += nums[i];
        long long sum = sum0;
        if (is_odd(sum)) {
            cache[n - i - 1] = sum;
            continue;
        }
        //Might be problem here
        else {
            //Add the upper even minus lower odd
            long long sum1 = sum;
            int temp1 = upper_evens[i];
            int temp2 = lower_odds[i - 1];
            if (temp1 != -1 && temp2 != -1) {
                sum1 = sum1 - nums[temp1] + nums[temp2];
            }
            if (!is_odd(sum1)) {
                sum1 = -1;
            }
            //Add the upper odds minus lower even
            long long sum2 = sum;
            int temp3 = upper_odds[i];
            int temp4 = lower_evens[i - 1];
            if (temp3 != -1 && temp4 != -1) {
                sum2 = sum2 - nums[temp3] + nums[temp4];
            }
            if (!is_odd(sum2)) {
                sum2 = -1;
            }
            if (sum1 >= sum2) {
                sum = sum1;
            }
            else {
                sum = sum2;
            }
            cache[n - i - 1] = sum;
        }
    }
    sum0 += nums[0];
    if (is_odd(sum0)) {
        cache[n - 1] = sum0;
    }
    else {
        cache[n - 1] = -1;
    }

    for (int i = 0; i < ks.size(); i++) {
        if (ks[i] > n || ks[i] == 0) {
            cout << -1 << "\n";
        }
        else {
            cout << cache[ks[i] - 1] << "\n";
        }
    }
}
