/*
https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
https://takeuforward.org/data-structure/n-meetings-in-one-room/
*/
#include <bits/stdc++.h>
using namespace std;

int maxMeetings(int start[], int end[], int n)
{
    pair<int, int> nums[n];
    for (int i = 0; i < n; i++)
    {
        nums[i].first = end[i];
        nums[i].second = i;
    }
    sort(nums, nums + n);
    int count = 1;
    pair<int, int> curr = nums[0];
    int i = 1;
    while (i < n)
    {
        if (start[nums[i].second] > curr.first)
        {
            curr = nums[i];
            count++;
        }
        i++;
    }
    return count;
}
int main()
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    cout << maxMeetings(start, end, 6);
}