/*
https://leetcode.com/problems/add-two-numbers/
https://takeuforward.org/data-structure/add-two-numbers-represented-as-linked-lists/
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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    ListNode head(0);
    ListNode *ptr = &head;
    while (l1 || l2 || carry)
    {
        int sum = (l1 ? l1->val:0) + (l2 ? l2->val:0) + carry;
        if (sum > 9)
        {
            carry = 1;
            sum = sum % 10;
        }
        else
            carry = 0;
        ptr->next = new ListNode(sum);
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
        ptr = ptr->next;
    }
    if (l1 || l2)
    {
        ptr = l1 ? l1 : l2;
        ptr->val += carry;
    }
    return head.next;
}

int main()
{
    int arr1[] = {2, 4, 3};
    int n = sizeof(arr1) / sizeof(int);
    ListNode *list1 = nullptr;
    for (int i = n - 1; i >= 0; i--)
        list1 = new ListNode(arr1[i], list1);
    int arr2[] = {5, 6, 4};
    n = sizeof(arr2) / sizeof(int);
    ListNode *list2 = nullptr;
    for (int i = n - 1; i >= 0; i--)
        list2 = new ListNode(arr2[i], list2);
    ListNode *res = addTwoNumbers(list1, list2);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
}