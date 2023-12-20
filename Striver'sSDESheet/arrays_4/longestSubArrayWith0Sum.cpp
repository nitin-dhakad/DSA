/*
https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
https://takeuforward.org/data-structure/length-of-the-longest-subarray-with-zero-sum/
*/
#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &A, int n)
{
    int maxSize = 0;
    int sum = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)
        {
            maxSize = i + 1;
        }
        else if (m.find(sum) != m.end())
        {
            maxSize = max(maxSize, i - m[sum]);
        }
        else
        {
            m[sum] = i;
        }
    }
    return maxSize;
}

int main()
{
    // vector<int> arr{15, -2, 2, -8, 1, 7, 10, 23};
    vector<int> arr{-1, 1, -1 ,1};
    cout << maxLen(arr, arr.size());
}