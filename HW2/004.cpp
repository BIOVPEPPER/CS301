#include <cstdlib>
#include <iostream>
//I didn't use the psudocode on the book, I think this should be easier to think
using namespace std;

int main() {
    int len = 0;
    cin >> len;
    // Initalize the count array
    int count[1001]{ 0 };

    int num = 0;
    // Increment it into the array without using other memories
    for (int i = 0; i < len; i++) {
        cin >> num;
        count[num]++;
    }
   
    for (int i = 0; i < 1001; i++) {
        int c = count[i];
        for (int j = 0; j < c; j++) {
            cout << i << ' ';
        }
    }
}