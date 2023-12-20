/*
https://practice.geeksforgeeks.org/problems/subset-sums2234/1#
https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets/
*/


// More Optimised Solution is available
#include <bits/stdc++.h>
using namespace std;

void calculateSum(vector<int> &arr, vector<int> &sumArr, int i, int sum) //recursion
{

    if (i == arr.size())
    {
        sumArr.push_back(sum);
        return;
    }
    calculateSum(arr, sumArr, i + 1, sum);
    calculateSum(arr, sumArr, i + 1, sum + arr[i]);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> sum;
    calculateSum(arr, sum, 0, 0);
    sort(sum.begin(), sum.end());
    return sum;
}

//Iterative 
//https://www.geeksforgeeks.org/print-sums-subsets-given-set/

int main()
{
}