/*
https://leetcode.com/problems/subsets-ii/
https://takeuforward.org/data-structure/subset-ii-print-all-the-unique-subsets/
*/

// More Optimised Solution is available
#include <bits/stdc++.h>
using namespace std;

void calculateAllArray(vector<int> &arr, set<vector<int>> &resArr, int i, vector<int> ds) // recursion
{
    sort(ds.begin(), ds.end());
    if (i == arr.size())
    {
        resArr.insert(ds);
        return;
    }
    calculateAllArray(arr, resArr, i + 1, ds);
    ds.push_back(arr[i]);
    calculateAllArray(arr, resArr, i + 1, ds);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    set<vector<int>> resArr;
    vector<vector<int>> ret;
    calculateAllArray(nums, resArr, 0, vector<int>{});
    for (auto ds = resArr.begin(); ds != resArr.end(); ds++)
    {
        ret.push_back(*ds);
    }
    return ret;
}

void calculateAllArray(vector<int> &arr, vector<vector<int>> &resArr, int i, vector<int> &ds) // recursion
{
    resArr.push_back(ds);
    for (int j = i; j < arr.size(); j++)
    {
        if (j != i && arr[j] == arr[j - 1])
            continue;
        ds.push_back(arr[i]);
        calculateAllArray(arr, resArr, i + 1, ds);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> resArr;
    calculateAllArray(nums, resArr, 0, vector<int>{});
    return resArr;
}

int main()
{
}