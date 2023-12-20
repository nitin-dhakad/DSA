/*
https://www.codingninjas.com/codestudio/problems/count-inversions_615
https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/
*/
#include <bits/stdc++.h>
using namespace std;

long long merged(long long *arr, long long *temp, int left, int mid, int right)
{
    long long inversionCount = 0;
    int i, j, k;
    i = k = left;
    j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (arr[i] > arr[j])
        {
            inversionCount += j - k;
            temp[k++] = arr[j++];
        }
        else
            temp[k++] = arr[i++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    return inversionCount;
}

long long mergeSort(long long *arr, long long *temp, int left, int right)
{
    long long inversionCount = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;
        inversionCount += mergeSort(arr, temp, left, mid);
        inversionCount += mergeSort(arr, temp, mid + 1, right);
        inversionCount += merged(arr, temp, left, mid, right);
    }
    return inversionCount;
}

long long getInversions(long long *arr, int n)
{
    long long temp[n];
    return mergeSort(arr, temp, 0, n - 1);
}
int main()
{
    long long arr[] = {52244275, 123047899, 493394237, 922363607, 378906890, 188674257, 222477309, 902683641, 860884025, 339100162};
    int n = 10;
    cout << getInversions(arr, n) << " ";
}