/*
https://leetcode.com/problems/palindrome-linked-list/
https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
bool isPalindrome(ListNode *head)
{
    ListNode *ptr = head;
    int n = 0;
    while (ptr)
    {
        ptr = ptr->next;
        n++;
    }
    int k = n / 2;
    ptr = head;
    ListNode *prev = nullptr;
    while (k > 0)
    {
        ListNode *next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
        k--;
    }
    if (n % 2 != 0)
        ptr = ptr->next;
    while (prev && ptr)
    {
        if (prev->val != ptr->val)
            return false;
        prev = prev->next;
        ptr = ptr->next;
    }
    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    ListNode *head = nullptr;
    for (int i = n - 1; i >= 0; i--)
        head = new ListNode(arr[i], head);
    cout << isPalindrome(head);
}