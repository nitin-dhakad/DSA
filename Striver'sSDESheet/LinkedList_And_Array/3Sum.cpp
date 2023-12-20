/*
https://leetcode.com/problems/3sum/
https://takeuforward.org/data-structure/3-sum-find-triplets-that-add-up-to-a-zero/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        if (nums[i] + nums[i + 1] + nums[i + 1] > 0)
            break;
        if (nums[i] + nums[n -1] + nums[n -2] < 0)
            continue;;
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            if (right < n - 1 && nums[right] == nums[right + 1])
            {
                right--;
                continue;
            }
            else if (left > i + 1 && nums[left] == nums[left - 1])
            {
                left++;
                continue;
            }
            if (nums[left] + nums[right] + nums[i] == 0)
            {
                res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                left++;
                right--;
            }
            else if (nums[left] + nums[right] + nums[i] > 0)
                right--;
            else
                left++;
        }
    }
    return res;
}

int main()
{
    vector<int> arr{-1, 0, 1, 2, -1, -4};

    vector<vector<int>> res = threeSum(arr);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << ", ";
        }
        cout << '\n';
    }
}