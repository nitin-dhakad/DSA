#include <iostream>
using namespace std;

int *merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int l[n1], r[n2];
    for (int i = 0; i < n1; i++)
    {
        l[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        r[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (l[i] < r[j])
        {
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = l[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = r[j];
        j++;
        k++;
    }
}
void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int A[] = {2, 7, 4, 1, 5, 3};
    cout << "\n"
         << "Merge sort"
         << "\n";
    MergeSort(A, 0, 5);
    for (int i = 0; i < 6; i++)
        cout << A[i] << " ";
}