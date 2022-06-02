/*
https://leetcode.com/problems/two-sum/
https://takeuforward.org/data-structure/two-sum-check-if-a-pair-with-given-sum-exists-in-array/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) // time complexity O(n) and space = O(n)
{
    unordered_map<int, int> m;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.count(target - nums[i]) > 0) // OR if (m.find(target - nums[i]) != m.end())
        {
            res = {m[target - nums[i]], i};
            break;
        }
        else
            m[nums[i]] = i;
    }
    return res;
}

int main()
{
    vector<int> arr{3,2,4};
    vector<int> res = twoSum(arr, 6);
    cout << res[0] << " " << res[1];
}