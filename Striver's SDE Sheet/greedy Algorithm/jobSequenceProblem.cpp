/*
https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
https://takeuforward.org/data-structure/job-sequencing-problem/
*/
#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool comparator(Job &a, Job &b)
{
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comparator);
    int maxTime = 0;
    for (int i = 0; i < n; i++)
        maxTime = max(maxTime, arr[i].dead);
    int time[maxTime + 1] = {};
    int jobsDone = 0;
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (time[j] == 0)
            {
                time[j] = 1;
                jobsDone++;
                profit += arr[i].profit;
                break;
            }
        }
    }
    return vector<int>{jobsDone, profit};
}

int main()
{
}