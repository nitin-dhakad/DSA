/*
https://leetcode.com/problems/search-a-2d-matrix/
https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/
*/
#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &arr, int target, int start, int end)
{
    int mid = (start + end) / 2;
    if (arr[mid] == target)
    {
        return true;
    }
    if (start >= end)
        return false;
    if (arr[mid] > target)
        return binarySearch(arr, target, start, mid - 1);
    else
        return binarySearch(arr, target, mid + 1, end);
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int start = 0;
    int end = n - 1;
    if (target < matrix[0][0] || target > matrix[n - 1][m - 1])
    {
        return false;
    }
    while (true)
    {
        int mid = (start + end) / 2;
        if (matrix[mid][0] <= target && matrix[mid][m - 1] >= target)
        {
            return binarySearch(matrix[mid], target, 0, m - 1);
        }
        if (start >= end)
            return false;
        if (matrix[mid][0] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
}

bool searchMatrix2(vector<vector<int>> &matrix, int target) //clean code same complexity
{
    int lo = 0;
        if(!matrix.size()) return false;
        int hi = (matrix.size() * matrix[0].size()) - 1;
        
        while(lo <= hi) {
            int mid = (lo + (hi - lo) / 2);
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] == target) {
                return true;
            }
            if(matrix[mid/matrix[0].size()][mid % matrix[0].size()] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
}

int main()
{
    // vector<vector<int>> arr{{1, 3}};
    vector<vector<int>> arr{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    cout << searchMatrix2(arr, 13);
}