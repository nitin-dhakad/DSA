/*
https://leetcode.com/problems/reverse-pairs/
https://takeuforward.org/data-structure/count-reverse-pairs/
*/
#include <bits/stdc++.h>
using namespace std;

int reversePairs(vector<int> &nums) // Brute Force
{
    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++)
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] > 2 * nums[j])
                count++;
        }
    return count;
}

int merge(vector<int> &arr, vector<int> &temp, int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;
    int count = 0;
    for (int i = l; i <= m; i++)
    {
        while (j <= r && arr[i] > 2LL * arr[j])
        {
            j++;
        }
        count += (j - (m + 1));
    }
    i = l;
    j = m + 1;
    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= m)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (i = l; i <= r; i++)
        arr[i] = temp[i];
    return count;
}

int mergeSort(vector<int> &arr, vector<int> &temp, int l, int r)
{
    int count = 0;
    if (r > l)
    {
        int mid = l + (r - l) / 2;
        count += mergeSort(arr, temp, l, mid);
        count += mergeSort(arr, temp, mid + 1, r);
        count += merge(arr, temp, l, mid, r);
    }
    return count;
}

int reversePairs2(vector<int> &nums) // Brute Force
{
    vector<int> temp(nums.size());
    return mergeSort(nums, temp, 0, nums.size() - 1);
}

int main()
{
    vector<int> arr{233, 2000000001, 234, 2000000006, 235, 2000000003, 236, 2000000007, 237, 2000000002, 2000000005, 233, 233, 233, 233, 233, 2000000004};
    cout << reversePairs2(arr);
}