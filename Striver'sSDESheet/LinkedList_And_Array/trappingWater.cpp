/*
https://leetcode.com/problems/trapping-rain-water/
https://takeuforward.org/data-structure/trapping-rainwater/
*/
#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> maxRight(n, 0);
    int maxRightSoFar = 0;
    for (int i = n - 1; i > 0; i--)
    {
        maxRightSoFar = max(maxRightSoFar, height[i]);
        maxRight[i - 1] = maxRightSoFar;
    }
    int maxLeftSoFar = height[0];
    int total = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (maxLeftSoFar <= height[i])
            maxLeftSoFar = height[i];
        else if (maxRight[i] > height[i])
            total += min(maxRight[i], maxLeftSoFar) - height[i];
    }
    return total;
}



int main()
{
    vector<int> arr{4, 2, 0, 3, 2, 5};
    cout << trap(arr);
}