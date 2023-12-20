/*
https://leetcode.com/problems/powx-n/
https://takeuforward.org/data-structure/implement-powxn-x-raised-to-the-power-n/
*/
#include <bits/stdc++.h>
using namespace std;

double pow(double x, long long n) // Looping
{
    if (n == 0)
        return 1;
    double ans = 1.0;
    long long nn;
    if (n < 0)
        nn = abs(n);
    else
        nn = n;
    while (nn > 1)
    {
        if (nn % 2 == 0)
        {
            x *= x;
            nn /= 2;
        }
        else
        {
            ans *= x;
            nn--;
        }
    }
    ans = ans * x;
    if (n < 0)
        ans = 1 / ans;
    return ans;
}

void powerRecursive(double &x, double &ans, long long n)
{
    cout << ans << " " << x << " " << n << "\n";
    if (n > 1)
    {

        if (n % 2 == 0)
        {
            x *= x;
            powerRecursive(x, ans, n / 2);
        }
        else
        {
            ans *= x;
            powerRecursive(x, ans, --n);
        }
    }
}

double pow2(double x, long long n) // Recursive
{
    if (n == 0)
        return 1;
    long long nn;
    double ans = 1.0;
    if (n < 0)
    {
        cout << "sds";
        nn = abs(n);
    }
    else
        nn = n;
    cout << ans << " " << x << " " << nn << "\n";
    powerRecursive(x, ans, nn);
    if (n < 0)
        ans = 1 / ans;
    return ans;
}

int main()
{
    cout << pow2(2.10000, -2147483648);
}