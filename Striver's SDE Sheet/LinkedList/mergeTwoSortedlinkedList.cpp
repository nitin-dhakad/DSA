/*
https://leetcode.com/problems/merge-two-sorted-lists/
https://takeuforward.org/data-structure/merge-two-sorted-linked-lists/
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

ListNode *mergeTwoList(ListNode *list1, ListNode *list2)
{
    ListNode *head = new ListNode();
    ListNode *ptr = head;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            ptr->next = list1;
            list1 = list1->next;
        }
        else
        {
            ptr->next = list2;
            list2 = list2->next;
        }
        ptr = ptr->next;
    }
    ptr->next = list1 ? list1 : list2;
    return head->next;
}

int main()
{
    int arr1[] = {1, 3, 4, 5, 7, 9};
    int n = sizeof(arr1) / sizeof(int);
    ListNode *list1 = nullptr;
    for (int i = n - 1; i >= 0; i--)
        list1 = new ListNode(arr1[i], list1);
    int arr2[] = {0, 2, 3, 6, 10};
    n = sizeof(arr2) / sizeof(int);
    ListNode *list2 = nullptr;
    for (int i = n - 1; i >= 0; i--)
        list2 = new ListNode(arr2[i], list2);
    ListNode *res = mergeTwoList(list1, list2);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
}
