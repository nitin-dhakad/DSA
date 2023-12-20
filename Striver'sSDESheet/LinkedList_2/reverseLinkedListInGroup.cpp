/*
https://leetcode.com/problems/reverse-nodes-in-k-group/
https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/
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

ListNode *reverseGroup(ListNode *head, int k)
{
    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *currHead = head;
    ListNode *res = head;
    bool first = true;
    while (curr)
    {

        int n = k;
        ListNode *temp = curr;
        while (temp && n > 0)
        {
            temp = temp->next;
            n--;
        }
        if (n > 0)
        {
            currHead->next = curr;
            break;
        }
        n = k;
        prev = nullptr;
        ListNode *prevHead = currHead;
        currHead = curr;
        while (n > 0 && curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            n--;
        }
        if (first)
        {
            res = prev;
            first = false;
        }
        else
            prevHead->next = prev;

    }
    return res;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    ListNode *head = nullptr;
    for (int i = n - 1; i >= 0; i--)
        head = new ListNode(arr[i], head);
    ListNode *res = reverseGroup(head, 2);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
}