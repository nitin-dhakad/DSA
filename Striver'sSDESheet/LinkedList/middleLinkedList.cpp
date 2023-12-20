/*
https://leetcode.com/problems/middle-of-the-linked-list/
https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/
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
ListNode *middleNode(ListNode *head)
{
    int n = 0;
    ListNode *node = head;
    while (node != nullptr)
    {
        n++;
        node = node->next;
    }
    n = ceil(n / 2);
    node = head;
    while (n != 0)
    {
        node = node->next;
        n--;
    }
    return node;
}
ListNode *middleNode(ListNode *head) //Two Pointer Approach -> slow and fast
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
        slow = slow->next, fast = fast->next->next;
    return slow;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    ListNode *head = nullptr;
    for (int i = n - 1; i >= 0; i--)
        head = new ListNode(arr[i], head);
    ListNode *res = middleNode(head);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
}