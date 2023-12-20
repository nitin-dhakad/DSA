/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;
    int min = prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] - min > maxProfit){
            maxProfit = prices[i] - min;
        }
        if(min > prices[i]){
            min = prices[i];
        }
    }
    return maxProfit;
    
}

int main()
{
    vector<int> arr{7,6,4,3,1};
    cout << maxProfit(arr) << '\n';
}