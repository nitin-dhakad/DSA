#include <iostream>
using namespace std;

int Partition(int arr[], int l, int r)
{
    int pivot = arr[l];
    int j = l;
    for (int i = l + 1; i < r; i++)
    {
        if (arr[i] < pivot)
        {
            j++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[j];
    arr[j] = arr[l];
    arr[l] = temp;
    return j;
}
void QuickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = Partition(arr, l, r);
        QuickSort(arr, l, m - 1);
        QuickSort(arr, m + 1, r);
    }
}

int main()
{
    int A[] = {2, 7, 4, 1, 5, 3};
    cout << "\n"
         << "Quick sort"
         << "\n";
    QuickSort(A, 0, 6);
    for (int i = 0; i < 6; i++)
        cout << A[i] << " ";
}