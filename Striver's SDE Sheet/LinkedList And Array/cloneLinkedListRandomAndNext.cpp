/*
https://leetcode.com/problems/copy-list-with-random-pointer/
*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    unordered_map<Node *, int> m;
    unordered_map<int, Node *> m2;
    int n = 0;
    Node *ptr = head;
    Node *head2 = new Node(0);
    Node *ptr2 = head2;
    while (ptr)
    {
        m[ptr] = n;
        ptr2->next = new Node(ptr->val);
        m2[n] = ptr2->next;
        ptr2 = ptr2->next;
        ptr = ptr->next;
        n++;
    }
    ptr = head;
    ptr2 = head2->next;
    while (ptr)
    {
        ptr2->random = ptr->random == nullptr ? nullptr : m2[m[ptr->random]];
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }
    return head2->next;
}

Node *copyRandomList2(Node *head) // with one hastTable
{
    unordered_map<Node *, Node *> m;
    Node *ptr = head;
    while (ptr)
    {
        m[ptr] =  new Node(ptr->val);
        ptr = ptr->next;
    }
    ptr = head;
    while (ptr)
    {
        m[ptr]->next = m[ptr->next];
        m[ptr]->random = m[ptr->random];
        ptr = ptr->next;
    }
    return m[head];
}

int main()
{
    Node *l = new Node(5);
    Node *head = l;
    l = l->next = new Node(6);
    l = l->next = new Node(7);
    l = l->next = new Node(8);
    Node *res = copyRandomList(head);
    while (res)
    {
        cout << res->val;
        res = res->next;
    }
}
