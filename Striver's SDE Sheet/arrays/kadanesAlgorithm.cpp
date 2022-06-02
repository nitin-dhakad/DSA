/*https://leetcode.com/problems/maximum-subarray/
 */
#include <bits/stdc++.h>
using namespace std;

int maximumSubarray(vector<int> &nums)
{
    int maxSum = INT_MIN, currSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        currSum += nums[i];
        if (currSum > maxSum)
            maxSum = currSum;
        if (currSum < 0)
            currSum = 0;
    }
    return maxSum;
}
int maximumSubarray2(vector<int> &nums) // With SubArray Index
{
    int maxSum = INT_MIN, currSum = 0, s, start = 0, end = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        currSum += nums[i];
        if (currSum > maxSum)
        {
            start = end = 0;
            maxSum = currSum;
            start = s;
            end = i;
        }
        if (currSum < 0)
        {
            currSum = 0;
            s = i + 1;
        }
    }
    cout << start << " " << end << '\n';
    return maxSum;
}

int main()
{
    vector<int> arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int output = maximumSubarray(arr);
    cout << output;
}