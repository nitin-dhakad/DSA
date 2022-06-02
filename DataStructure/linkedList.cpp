#include <iostream>
using namespace std;
#include <cstdlib>

struct Node
{
    int value;
    Node *Next;
};

int main()
{
    Node *Head = (Node *)malloc(sizeof(int)); // Traditional
    // Node *Head = new Node();  //New Approach
    (*Head).value = 5; // Traditional
    Head->Next = NULL; // New Approach
    cout << Head->value << endl;
    free(Head);
}