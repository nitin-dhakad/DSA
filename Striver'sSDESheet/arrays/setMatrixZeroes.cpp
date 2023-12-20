/*https://leetcode.com/problems/set-matrix-zeroes/
 */

#include <bits/stdc++.h>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &matrix) // First Approach
{
    int n = matrix.size();
    int m = matrix[0].size();
    set<int> rows;
    set<int> columns;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                rows.insert(i);
                columns.insert(j);
            }
        }
    }
    set<int>::iterator itr;

    // Displaying set elements
    for (itr = rows.begin();
         itr != rows.end(); itr++)
    {
        for (int k = 0; k < m; k++)
        {
            matrix[*itr][k] = 0;
        }
    }
    for (itr = columns.begin();
         itr != columns.end(); itr++)
    {
        for (int k = 0; k < n; k++)
        {
            matrix[k][*itr] = 0;
        }
    }
}
void setMatrixZeroes2(vector<vector<int>> &matrix) // Second Approach
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row(n, 1);
    vector<int> column(m, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 0;
                column[j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 0 || column[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
void setMatrixZeroes3(vector<vector<int>> &matrix) // Third Approach O(1) space complexity
{
    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
            col0 = 0;
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
        if (col0 == 0)
        {
            matrix[i][0] = 0;
        }
    }
}
int main()
{
    vector<vector<int>> arr;
    arr = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setMatrixZeroes3(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}