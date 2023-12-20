/*
https://leetcode.com/problems/linked-list-cycle-ii/
https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/
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

ListNode *hasCycle(ListNode *head)
{
    if (!head || head->next == NULL)
        return nullptr;
    ListNode *slow = head;
    ListNode *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast && slow && fast && fast->next);
    if (slow == fast)
    {
        fast = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return nullptr;
}
int main()
{
}