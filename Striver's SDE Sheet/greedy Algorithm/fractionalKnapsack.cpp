/*https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
https://takeuforward.org/data-structure/fractional-knapsack-problem-greedy-approach/
*/
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, [](Item &a, Item &b)
         { return (a.value /(double) a.weight > b.value /(double) b.weight); });
    double value = 0;
    for (int i = 0; i < n; i++)
    {
        if (W > arr[i].weight)
        {
            W -= arr[i].weight;
            value += arr[i].value;
        }
        else if (W == arr[i].weight)
        {
            value += arr[i].value;
            break;
        }
        else{
            value += (arr[i].value/(double)arr[i].weight)*W;
            break;
        }
    }
    return value;
}

int main()
{
}