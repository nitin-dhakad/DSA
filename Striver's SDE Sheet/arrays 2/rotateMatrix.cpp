/*
https://leetcode.com/problems/rotate-image/
https://takeuforward.org/data-structure/rotate-image-by-90-degree/
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> &matrix) // BruteForce
{
    int n = matrix.size();
    vector<vector<int>> ret(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ret[j][n - 1 - i] = matrix[i][j];
        }
    }
    return ret;
}
void rotate2(vector<vector<int>> &matrix) // Optimized
{
    int n = matrix.size();
    // Transposing
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> arr{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate2(arr);
    for (auto arr1 : arr)
    {
        for (auto arr2 : arr1)
        {
            cout << arr2 << " ";
        }
        cout << '\n';
    }
}