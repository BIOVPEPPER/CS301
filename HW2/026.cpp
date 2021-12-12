
#include <iostream>
#include<vector>
using namespace std;
vector<int> vec[1000];
// Function prototypes

//Actually I think this is much more easier than what we introduced in the class, i start from left but j start from right.
void quicksort(int num[], int st, int en)
{
    if (st >= en)
        return;
    int i = st;
    int j = en;
    int op = num[i];
    while (i < j)
    {
        while (i < j && num[j] >= op)
            j--;
        num[i] = num[j];
        while (i < j && num[i] <= op)
            i++;
        num[j] = num[i];
    }

    num[i] = op;

    quicksort(num, st, i - 1);
    quicksort(num, i + 1, en);


}


int main()
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b);
    }
    for (int i = 0; i < 1000; i++) {
        if (vec[i].empty() == false) {
            int lengthb = vec[i].size();
            int *array = new int[lengthb];
            for (int j = 0; j < lengthb; j++) {
                array[j] = vec[i].at(j);
            }
            quicksort(array, 0, lengthb-1);
            for (int m = 0; m < lengthb; m++) {
                if (m != lengthb - 1) {
                    cout << array[m] << " ";
                }
                else {
                    cout << array[m] << "\n";
                }
            }
            
        }
    }
}
