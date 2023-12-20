/*
https://leetcode.com/problems/merge-sorted-array/
https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/
*/
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0, j = 0;
    while (i < m + j && j < n)
    {
        if (nums2[j] < nums1[i])
        {
            nums1.insert(nums1.begin() + i, nums2[j]);
            nums1.pop_back();
            j++;
        }
        i++;
    } 
    while (j < n)
    {
        nums1[i] = nums2[j];
        i++, j++;
    }
}
int main()
{
    vector<int> arr1{2,0};
    vector<int> arr2{1};
    merge(arr1, 1, arr2, 1);
    for (auto arr3 : arr1)
    {
        cout << arr3 << " ";
    }
}