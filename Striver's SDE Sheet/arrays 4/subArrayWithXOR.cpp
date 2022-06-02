/*
https://www.interviewbit.com/problems/subarray-with-given-xor/
https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k/
*/
#include <bits/stdc++.h>
using namespace std;

int subArrayWithXOR(vector<int> &A, int B)
{
    unordered_map<int, int> m;
    int count = 0;
    int currXor = 0;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        currXor ^= A[i];
        int y = currXor ^ B;
        if (currXor == B)
            count++;
        if (m.find(y) != m.end())
            count += m[y];
        m[currXor]++;
    }
    return count;
}

int main()
{
    vector<int> arr = {5, 6, 7, 8, 9};
    int target = 5;
    cout << subArrayWithXOR(arr, target);
}