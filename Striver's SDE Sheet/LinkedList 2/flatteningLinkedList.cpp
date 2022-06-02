/*
https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
https://takeuforward.org/data-structure/flattening-a-linked-list/
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *flatten(Node *root)
{
    while (root && root->next)
    {
        Node *list1 = root;
        Node *list2 = root->next;
        root->next = list2->next;
        Node *head = new Node(0);
        Node *ptr = head;
        while (list1 && list2)
        {
            if (list1->data < list2->data)
            {
                ptr->bottom = list1;
                list1 = list1->bottom;
            }
            else
            {
                ptr->bottom = list2;
                list2 = list2->bottom;
            }
            ptr = ptr->bottom;
        }
        ptr->bottom = list1 ? list1 : list2;
        root = head->bottom;
    }
    return root;
}
int main()
{
}