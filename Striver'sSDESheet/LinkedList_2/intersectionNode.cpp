/*
https://leetcode.com/problems/intersection-of-two-linked-lists/
https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) // n^2
{

    while (headA)
    {
        ListNode *temp = headB;
        while (temp)
        {
            if (headA == temp)
                return headA;
            temp = temp->next;
        }
        headA = headA->next;
    }
    return NULL;
}
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) // n + m
{
    ListNode *a = headA;
    ListNode *b = headB;
    while (a && b)
    {
        a = a->next;
        b = b->next;
    }
    if (a)
    {
        b = headA;
        while (a)
        {
            b = b->next;
            a = a->next;
        }
        a = headB;
    }
    else
    {
        a = headB;
        while (b)
        {
            b = b->next;
            a = a->next;
        }
        b = headA;
    }
    while (a && b)
    {
        if (a == b)
            return a;
        b = b->next;
        a = a->next;
    }
    return NULL;
}

int main()
{
    // cannot be tested locally
}