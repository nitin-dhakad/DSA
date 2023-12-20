/*https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    int n = r * c;
    int i, j, tb, bb, rb, lb;
    i = j = tb = lb = 0;
    bb = r - 1;
    rb = c - 1;
    int direction = 0;
    vector<int> ret;
    while (n != 0)
    {
        ret.push_back(matrix[i][j]);
        if (direction == 0)
        {
            if (j != rb)
                j++;
            else
            {
                direction = 1;
                i++;
                tb++;
            }
        }
        else if (direction == 1)
        {
            if (i != bb)
                i++;
            else
            {
                direction = 2;
                j--;
                rb--;
            }
        }
        else if (direction == 2)
        {
            if (j != lb)
                j--;
            else
            {
                direction = 3;
                i--;
                bb--;
            }
        }
        else
        {
            if (i != tb)
                i--;
            else
            {
                direction = 0;
                j++;
                lb++;
            }
        }
        n--;
    }
    return ret;
}
int main()
{
    vector<vector<int>> arr{
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<int> arr1 = spirallyTraverse(arr, 4, 4);
    for (auto arr2 : arr1)
    {
        cout << arr2 << " ";
    }
}