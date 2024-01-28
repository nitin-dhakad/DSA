/*
https://leetcode.com/problems/merge-intervals/
https://takeuforward.org/data-structure/merge-overlapping-sub-intervals/
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &arr) // My Approach O(n^2)
{
    int n = arr.size();
    vector<vector<int>> ret;
    sort(arr.begin(), arr.end()); //sort the array with first element of sub array, frist element is same then it compares second element
    ret.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        int k = ret.size();
        bool isOverLapped = false;
        for (int j = 0; j < k; j++)
        {
            if (arr[i][0] <= ret[j][0])
            {
                if (arr[i][1] == ret[j][0])
                {
                    isOverLapped = true;
                    ret[j][0] = arr[i][0];
                }
                else if (arr[i][1] > ret[j][0] && arr[i][1] <= ret[j][1])
                {
                    isOverLapped = true;
                    ret[j][0] = arr[i][0];
                }
                else if (arr[i][1] > ret[j][1])
                {
                    isOverLapped = true;
                    ret[j] = arr[i];
                }
            }
            else if (arr[i][0] <= ret[j][1])
            {
                if (arr[i][1] > ret[j][1])
                {
                    isOverLapped = true;
                    ret[j][1] = arr[i][1];
                }
                else if (arr[i][1] <= ret[j][1])
                {
                    isOverLapped = true;
                }
            }
        }
        if (!isOverLapped)
            ret.push_back(arr[i]);
    }

    return ret;
}

vector<vector<int>> merge2(vector<vector<int>> &arr) // Time = O(nlog(n))  space = O(n)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ret{arr[0]};
    for (int i = 1; i < n; i++)
    {
            vector<int> &last = ret.back();
            if (last[1] >= arr[i][0] && last[1] < arr[i][1])
                last[1] = arr[i][1];
            else if (last[1] >= arr[i][0] && last[1] >= arr[i][1])
                continue;
            else
                ret.push_back(arr[i]);
    }
    return ret;
}

//same as above with simplied loop logic
vector<vector<int>> merge3(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ret;
        sort(intervals.begin(),intervals.end());
        ret.push_back(intervals[0]);
        int k = 0;
        for(int i=1;i<n;i++){
           if(ret[k][1]>=intervals[i][0]){
               if(ret[k][1]<intervals[i][1] )
                    ret[k][1] = intervals[i][1];
           }
           else{
               ret.push_back(intervals[i]);
               k++;
           }
        }
        return ret;
        
    }
int main()
{
    vector<vector<int>> arr{{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    vector<vector<int>> result = merge2(arr);
    for (auto arr1 : result)
    {
        for (auto arr2 : arr1)
        {
            cout << arr2 << " ";
        }
        cout << "\n";
    }
}