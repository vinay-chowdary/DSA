#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;

//merge sort time complexity is theta(nlogn)

void merge(int *arr, int n, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];

    //copy first half to temporary L array
    for (int t = 0; t < n1; t++)
        L[t] = arr[low + t];

    //copy second half to temporary R array
    for (int t = 0; t < n2; t++)
        R[t] = arr[mid + 1 + t];

    int i = 0, j = 0, k = low;

    //compare elements in both L and R arrays
    for (; i < n1 && j < n2;)
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];

    //remaining elements in L
    while (i < n1)
        arr[k++] = L[i++];

    //remaining elements in R
    while (j < n2)
        arr[k++] = R[j++];
}
void merge_sort(int *arr, int n, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, n, low, mid);
        merge_sort(arr, n, mid + 1, high);
        merge(arr, n, low, mid, high);
    }
}
int main()
{
    srand(time(0));
    clock_t start, end;
    int n;
    cin >> n;
    int arr[n];
    ofstream out("input.txt"), sorted("output.txt");
    ifstream in("input.txt");
    for (int i = 0; i < n; i++)
        out << rand() % n << endl;
    for (int i = 0; i < n; i++)
        in >> arr[i];
    start = clock();
    merge_sort(arr, n, 0, n - 1);
    end = clock();
    for (int i = 0; i < n; i++)
        sorted << arr[i] << endl;
    cout << (end - start) * 1.0 / CLOCKS_PER_SEC;
    cout << "\n";
    return 0;
}