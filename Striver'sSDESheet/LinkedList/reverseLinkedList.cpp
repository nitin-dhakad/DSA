/*
https://leetcode.com/problems/reverse-linked-list/
https://takeuforward.org/data-structure/reverse-a-linked-list/
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

ListNode *reverseList(ListNode *head)
{
    ListNode *res = nullptr;
    while (head != nullptr)
    {
        res = new ListNode(head->val, res);
        head = head->next;
    }
    return res;
}
ListNode *reverseList2(ListNode *head)
{
    ListNode *newHead = NULL;
    while (head != NULL)
    {
        ListNode *next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    ListNode *head = nullptr;
    for (int i = n - 1; i >= 0; i--)
        head = new ListNode(arr[i], head);
    ListNode *res = reverseList(head);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
}