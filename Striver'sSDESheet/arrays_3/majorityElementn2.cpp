/*
https://leetcode.com/problems/majority-element/
https://takeuforward.org/data-structure/find-the-majority-element-that-occurs-more-than-n-2-times/
*/
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums) // using hashmap time = O(nlogn) , space =O(n)
{
    map<int, int> m;
    int ele;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }
    for (auto i : m)
        if (i.second > nums.size() / 2)
            ele = i.first;
    return ele;
}

int majorityElement2(vector<int> &nums) // Moore's Voting Algorithm Time Complexity = O(n) ans space = O(1)
{
    int count = 0;
    int ele;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
            ele = nums[i];
        if (nums[i] == ele)
            count++;
        else
            count--;
    }
    return ele;
}

int main()
{
    vector<int> arr{3, 2, 3};
    cout << majorityElement(arr);
}