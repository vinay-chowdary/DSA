#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertion_sort(arr, n);
    end = clock();
    for (int i = 0; i < n; i++)
        sorted << arr[i] << endl;
    cout << (end - start) * 1.0 / CLOCKS_PER_SEC;
    return 0;
}