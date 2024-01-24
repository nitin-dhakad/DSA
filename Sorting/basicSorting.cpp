#include <iostream>
using namespace std;
//select minimum index then inset at first place and so on..
void SelectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int iMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[iMin])
                iMin = j;
        }
        int temp = A[i];
        A[i] = A[iMin];
        A[iMin] = temp;
    }
}
//swapping places if geater number found than it's consecutive number, after first loop greatest will be at last index
void BubbleSort(int A[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = temp;
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}
//In first pass start with two number subarray , swap if not in ascending order,
//Now with 3 number sub-array compare last element with above sub-array keep swapping till get's correct position, and so on...
void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (A[j - 1] > A[j])
            {
                int temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
            }
        }
    }
}
int main()
{
    int A[] = {2, 7, 4, 1, 5, 3};
    cout << "\n"
         << "Selection sort"
         << "\n";
    SelectionSort(A, 6);
    for (int i = 0; i < 6; i++)
        cout << A[i] << " ";

    int B[] = {2, 7, 4, 1, 5, 3};
    cout << "\n"
         << "Bubble sort"
         << "\n";
    BubbleSort(B, 6);
    for (int i = 0; i < 6; i++)
        cout << B[i] << " ";

    int C[] = {2, 7, 4, 1, 5, 3};
    cout << "\n"
         << "Insertion sort"
         << "\n";
    InsertionSort(C, 6);
    for (int i = 0; i < 6; i++)
        cout << C[i] << " ";
}