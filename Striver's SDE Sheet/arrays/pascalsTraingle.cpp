/*https://leetcode.com/problems/pascals-triangle/
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalTraingle(int n)
{
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].resize(i + 1);
        for (int j = 0; j < i + 1; j++)
        {
            if (i == 0 || j == 0 || i == j)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    return arr;
}

int main()
{
    vector<vector<int>> arr = pascalTraingle(5);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}