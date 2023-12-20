/*
https://leetcode.com/problems/longest-consecutive-sequence/
https://takeuforward.org/data-structure/longest-consecutive-sequence-in-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

int longestconsecutive(vector<int> &nums) // Not_optimized
{
    int n = nums.size();
    if (n == 0)
        return 0;
    unordered_map<int, int> m;
    int maxCount = 1;
    for (int i = 0; i < n; i++)
        m[nums[i]] = 1;
    for (int i = 0; i < n; i++)
    {

        int count = 1;
        int num = nums[i] - 1;
        while (m[num--])
            count++;
        if (count > maxCount)
            maxCount = count;
    }
    return maxCount;
}
int longestconsecutive2(vector<int> &nums) // Optimized 
{
    unordered_map<int, int> m;
    int maxCount = 0;
    for (auto n: nums) 
        if (!m[n])
        {
            int left = m[n - 1];
            int right = m[n + 1];
            int sum = left + right + 1;
            maxCount = max(maxCount,sum);
            m[n] = sum;
            m[n - left] = sum ;
            m[n + right] = sum ;
        }
    return maxCount;
}

/* one liner for above code , Replace inside if block with this
maxCount = max(maxCount,m[n] = m[n -  m[n - 1]] = m[n +  m[n + 1]] = m[n - 1] +  m[n + 1] + 1);
*/
int main()
{
    vector<int> arr{100, 4, 200, 1, 3, 2};
    cout << longestconsecutive2(arr);
}