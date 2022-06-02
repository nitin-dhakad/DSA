/*
https://leetcode.com/problems/linked-list-cycle/
https://takeuforward.org/data-structure/detect-a-cycle-in-a-linked-list/
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head)
{
    if (!head || head->next == NULL)
        return false;
    ListNode *slow = head;
    ListNode *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast && slow && fast && fast->next);
    return slow == fast;
}
int main()
{
}