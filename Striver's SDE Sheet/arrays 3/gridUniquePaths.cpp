/*
https://leetcode.com/problems/unique-paths/
https://takeuforward.org/data-structure/grid-unique-paths-count-paths-from-left-top-to-the-right-bottom-of-a-matrix/
*/
#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) //  exponential time and space complexity = O(2^m*n)
{
    if (m == 1 && n == 1)
        return 1;
    else if (m == 0 || n == 0)
        return 0;
    return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}

/*
Dynamic Programming
same as above approach but with dummy matrix so ,
we won't have to calculated unique path whose previously were calculated;
Time Complexity = O(m*n) , space = O(n*n) because of dummy matrix.
*/
int recursiveCount(vector<vector<int>> &dummy, int i, int j, int &m, int &n)
{
    if (dummy[i][j] == -1)
    {
        if (i == m - 1 && j == n - 1)
        {
            dummy[i][j] = 1;
        }
        else if (i == m || j == n)
        {
            dummy[i][j] = 0;
        }
        else
            dummy[i][j] = recursiveCount(dummy, i + 1, j, m, n) + recursiveCount(dummy, i, j + 1, m, n);
    }
    return dummy[i][j];
}
int uniquePaths2(int m, int n)
{
    vector<vector<int>> dummy(m + 1, vector<int>(n + 1, -1));
    if (m == 1 || n == 1)
        return 1;
    return recursiveCount(dummy, 0, 0, m, n);
}

long long uniquePaths3(int m, int n) // combination nCr
{
    n = m + n - 2;
    int r = m - 1;
    long long ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans = ans * (n - r + i) / i;
    }
    return (int)ans;
}
int main()
{
    cout << uniquePaths3(23, 12);
}