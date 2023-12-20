/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/
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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    int size = 0;
    ListNode *node = head;
    while (node != nullptr)
    {
        size++;
        node = node->next;
    }
    size = size - n;
    node = head;
    if (!size)
        return head->next;
    while (size > 1)
    {
        node = node->next;
        size--;
    }
    node->next = node->next->next;
    return head;
}
int main()
{
    int arr[] = {1};
    int n = sizeof(arr) / sizeof(int);
    ListNode *head = nullptr;
    for (int i = n - 1; i >= 0; i--)
        head = new ListNode(arr[i], head);
    ListNode *res = removeNthFromEnd(head, 1);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
}