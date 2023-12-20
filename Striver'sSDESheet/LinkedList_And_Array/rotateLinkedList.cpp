/*
https://leetcode.com/problems/rotate-list/description/
https://takeuforward.org/data-structure/rotate-a-linked-list/
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(next) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (k == 0 || head == NULL || head->next == NULL)
        return head;
    int n = 0;
    ListNode *ptr = head;
    while (ptr)
    {
        n++;
        ptr = ptr->next;
    }
    k = n - k % n;
    if (k == n)
        return head;
    ptr = head;
    while (k > 1)
    {
        ptr = ptr->next;
        k--;
    }
    ListNode *next = ptr->next;
    ptr->next = nullptr;
    ptr = next;
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = head;
    return next;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    ListNode *head = nullptr;
    for (int i = n - 1; i >= 0; i--)
        head = new ListNode(arr[i], head);
    ListNode *res = rotateRight(head, 2);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
}
