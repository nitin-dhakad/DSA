/*
https://www.interviewbit.com/problems/repeat-and-missing-number-array/
https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A) // Mathmatical Approach go to above link(sol2) for explanation
{
    long long int n = A.size();
    long long int sum = n * (n + 1) / 2;
    long long int sqSum = n * (n + 1) * (2 * n + 1) / 6;
    for (auto val : A)
    {
        sum -= (long long int)val;
        sqSum -= (long long int)val * (long long int)val;
    }
    long long int missing = (sum * sum + sqSum) / (2 * sum);
    long long int repeat = missing - sum;
    return vector<int>{(int)repeat, (int)missing};
}
vector<int> repeatedNumber2(const vector<int> &A) // XOR Approach 
{
    int Xor = 0;
    int n = A.size();
    for (auto val : A)
        Xor ^= val;
    for (int i = 1; i <= n; i++)
        Xor ^= i;
    int rbs = Xor & -Xor;
    int x = 0;
    int y = 0;
    for (auto val : A)
    {
        if (rbs & val)
            x ^= val;
        else
            y ^= val;
    }
    for (int i = 1; i <= n; i++)
    {
        if (rbs & i)
            x ^= i;
        else
            y ^= i;
    }
    int repeat, missing;
    for (auto val : A)
    {
        if (val == x)
        {
            repeat = x;
            missing = y;
            break;
        }
        else if (val == y)
        {
            repeat = y;
            missing = x;
            break;
        }
    }
    return vector<int>{repeat, missing};
}
int main()
{
    vector<int> arr{3, 1, 2, 5, 3};
    vector<int> result = repeatedNumber2(arr);
    for (auto i : result)
    {
        cout << i << " ";
    }
}