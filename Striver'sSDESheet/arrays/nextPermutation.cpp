/*https://leetcode.com/problems/next-permutation/
 */
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    for (int i = n - 1; i > 0; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i - 1])
                    minIndex = j;
                else
                    break;
            }
            int value = nums[minIndex];
            nums.erase(nums.begin() + minIndex);
            nums.insert(nums.begin() + i - 1, value);
            sort(nums.begin() + i, nums.end());
            return;
        }
    }
    for (int i = 0; i < n / 2; i++)
        swap(nums[i], nums[n - i - 1]);
}

int main()
{
    vector<int> arr{1, 3, 2};
    nextPermutation(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}