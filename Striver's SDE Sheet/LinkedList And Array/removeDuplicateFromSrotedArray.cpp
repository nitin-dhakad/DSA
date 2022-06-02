/*https://leetcode.com/problems/remove-duplicates-from-sorted-array/
https://takeuforward.org/data-structure/remove-duplicates-in-place-from-sorted-array/
*/
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums) //Brute Force 
{
    int dup = 0;
    int n = nums.size();
    int i = 1;
    while (i < n  - dup)
    {
        if (nums[i] == nums[i - 1])
        {
            dup++;
            for (int j = i; j < n - dup; j++)
                swap(nums[j], nums[j + 1]);
        }
        else
            i++;
    }
    return n - dup;
}

int removeDuplicates2(vector<int> &nums) {
    int n= nums.size();
        if(n<2)
            return n;
        int ans=1, j=0;
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j]=nums[i];
                ans++;
            }
        }
        return ans;
}

int main()
{
    vector<int> arr{1,1,2};
    cout << removeDuplicates2(arr) << "\n";
    for (auto j : arr)
    {
        cout << j << ", ";
    }
    cout << '\n';
}