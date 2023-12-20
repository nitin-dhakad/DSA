/*
https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
https://takeuforward.org/data-structure/minimum-number-of-platforms-required-for-a-railway/
*/
#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int count = 1;
    int maxPlatform = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] > dep[j])
        {
            count--;
            j++;
        }
        else
        {
            count++;
            i++;
        }
        maxPlatform = max(maxPlatform, count);
    }
    return maxPlatform;
}

// int findPlatform(int arr[], int dep[], int n)
// {
//     if (n < 2)
//         return n;
//     pair<int, int> nums[n];
//     for (int i = 0; i < n; i++)
//     {
//         nums[i].first = dep[i];
//         nums[i].second = i;
//     }
//     sort(nums, nums + n);
//     int maxPlatform = 0;
//     queue<int> q; // index of queued element
//     for (int i = 0; i < n; i++)
//     {
//         while (!q.empty() && arr[nums[i].second] > dep[q.front()])
//             q.pop();
//         q.push(nums[i].second);
//         maxPlatform = max((int)q.size(), maxPlatform);
//     }
//     return max(maxPlatform, (int)q.size());
// }

int main()
{
    int start[] = {900, 940, 950, 1100, 1500, 1800};
    int end[] = {910, 1200, 1120, 1130, 1900, 2000};
    cout << findPlatform(start, end, 6);
}