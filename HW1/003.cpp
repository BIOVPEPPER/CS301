#include <iostream>
using namespace std;
void merge(int*, int, int, int);
void merge_sort(int* arr, int low, int high)
//Basically what I did was simply copy and paster my SORTI and change the range of my temporary list so I can save more number in it.
{
    int mid;
    if (low < high) {
        //Divide it by two arrays, sort them seperately, and then merge them together
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}
// Merge sort 
void merge(int* arr, int low, int high, int mid)
{
    int i, j, k, c[5000000];
    i = low;
    k = low;
    j = mid + 1;
    // Divide one array into two, and sort them togther
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    //If there's anything left in the first array, put them in the c[k]
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    //If there's anything left in the second array, put them in the c[k]
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    //extract elements from the new temp to the original array
    for (i = low; i < k; i++) {
        arr[i] = c[i];
    }
}
// read input array and call mergesort
int main()
{
    int myarray[5000000], len;
    cin >> len;
    for (int i = 0; i < len; i++) {
        cin >> myarray[i];
    }
    merge_sort(myarray, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        cout << myarray[i] << " ";
    }
}