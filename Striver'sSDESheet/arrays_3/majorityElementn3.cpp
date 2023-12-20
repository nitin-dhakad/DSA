/*
https://leetcode.com/problems/majority-element-ii/
https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums) // hash maps time = O(n*log(n)) space = O(n)
{
    map<int, int> m;
    vector<int> ans;
    int min = nums.size() / 3;
    for (auto i : nums)
        m[i]++;
    for (auto i : m)
        if (i.second > min)
            ans.push_back(i.first);
    return ans;
}

vector<int> majorityElement2(vector<int> &nums) // Extended Voyer Moore's Voting algorithm time = O(n) space = O(1)
{
    int c1 = 0;
    int c2 = 0;
    int e1, e2;
    for (auto i : nums)
    {
        if (c1 == 0 && e2 != i)
        {
            e1 = i;
            c1++;
        }
        else if (c2 == 0 && e1 != i)
        {
            e2 = i;
            c2++;
        }
        else if (e1 == i)
            c1++;
        else if (e2 == i)
            c2++;
        else
            c1--, c2--;
    }
    vector<int> ans;
    c1 = c2 = 0;
    for (auto i : nums)
    {
        if (i == e1)
            c1++;
        else if (i == e2)
            c2++;
    }
    if (c1 > nums.size() / 3)
        ans.push_back(e1);
    if (c2 > nums.size() / 3)
        ans.push_back(e2);
    return ans;
}
int main()
{
    vector<int> arr{1,1,2,3,4,1,1,5,6,7,1,1,8,9,10,1,11,12,13,14};
    vector<int> ans = majorityElement2(arr);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}