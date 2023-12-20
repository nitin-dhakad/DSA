/*
https://leetcode.com/problems/4sum/
https://takeuforward.org/data-structure/4-sum-find-quads-that-add-up-to-a-target-value/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target) // Brute Force O(n^4)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    int i, j, k, l;
    for (i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            for (k = j + 1; k < n - 1; k++)
            {
                if (k > j + 1 && nums[k] == nums[k - 1])
                    continue;
                for (l = k + 1; l < n; l++)
                {
                    if (l > k + 1 && nums[l] == nums[l - 1])
                        continue;
                    if (nums[i] + nums[j] == target - nums[k] - nums[l])
                        res.push_back(vector<int>{nums[i], nums[j], nums[k], nums[l]});
                }
            }
        }
    }
    return res;
}

vector<vector<int>> fourSum2(vector<int> &nums, int target) // O(n^3*log(n))
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    int i, j, k;
    for (i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            for (k = j + 1; k < n - 1; k++)
            {
                if (k > j + 1 && nums[k] == nums[k - 1])
                    continue;
                int start = k + 1;
                int end = n - 1;
                while (start <= end)
                {
                    int mid = start + (end - start) / 2;
                    if (nums[i] + nums[j] == target - nums[k] - nums[mid])
                    {
                        res.push_back(vector<int>{nums[i], nums[j], nums[k], nums[mid]});
                        break;
                    }
                    else if (nums[i] + nums[j] < target - nums[k] - nums[mid])
                        start = mid + 1;
                    else
                        end = mid - 1;
                }
            }
        }
    }
    return res;
}

vector<vector<int>> fourSum3(vector<int> &nums, int target) // O(n^3)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    int i, j, k;
    for (i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        if (nums[i] + nums[i + 1] > target - nums[i + 2] - nums[i + 3])
            break;
        if (nums[i] + nums[n - 3] < target - nums[n - 2] - nums[n - 1])
            continue;
        for (j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            if (nums[i] + nums[j] > target - nums[j + 1] - nums[j + 2])
                break;
            if (nums[i] + nums[j] < target - nums[n - 2] - nums[n - 1])
                continue;
            int left = j + 1;
            int right = n - 1;
            while (right > left)
            {
                if (right < n - 1 && nums[right] == nums[right + 1])
                {
                    right--;
                    continue;
                }
                else if (left > j + 1 && nums[left] == nums[left - 1])
                {
                    left++;
                    continue;
                }
                if (nums[left] + nums[right] == target - nums[i] - nums[j])
                {
                    res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if (nums[left] + nums[right] > target - nums[i] - nums[j])
                    right--;
                else
                    left++;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> arr{7, 1, 7, -7, 10, 3, -5, -3, -9, 6, -8, -6, -10, 10, -3, 4, 2};

    vector<vector<int>> res = fourSum3(arr, 18);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << ", ";
        }
        cout << '\n';
    }
}