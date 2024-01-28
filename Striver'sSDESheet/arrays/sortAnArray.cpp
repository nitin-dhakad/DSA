/*https://leetcode.com/problems/sort-colors/
 */
#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int> &nums)
{
    int j, k;
    j = k = 0;
    for (int m = 0; m < nums.size(); m++)
    {
        if (nums[m] == 0)
        {
            swap(nums[m], nums[k]);
            swap(nums[j], nums[k]);
            j++, k++;
        }
        else if (nums[m] == 1)
        {
            swap(nums[m], nums[k]);
            k++;
        }
    }
}
int main()
{
    vector<int> arr{2, 0, 2, 1, 1, 0};
    sortColors(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << '\n';
}