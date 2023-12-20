/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
https://takeuforward.org/data-structure/length-of-longest-substring-without-any-repeating-character/
*/
#include <bits/stdc++.h>
using namespace std;

int longestSubString(string &s)
{
    int n = s.size();
    if (n <= 1)
        return n;
    unordered_map<char, int> m;
    int maxCount = 1;
    int subStartIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (m.find(s[i]) != m.end() && m[s[i]] >= subStartIndex)
        {
            maxCount = max(maxCount, i - subStartIndex);
            subStartIndex = m[s[i]] + 1;
        }
        else
            maxCount = max(maxCount, i - subStartIndex + 1);
        m[s[i]] = i;
    }
    return maxCount;
}

int main()
{
    string s = "dvdf";
    cout << longestSubString(s);
}