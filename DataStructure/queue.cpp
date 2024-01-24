#include <iostream>
using namespace std;

struct Node
{
    int Value;
    Node *Next = NULL;
};

class Queue
{
private:
    Node *_Head = NULL;
    Node *_Tail = NULL;

public:
    // Constructor
    Queue() {}
    Queue(int value)
    {
        Enqueue(value);
    }
    Queue(int values[], int n)
    {
        Enqueue(values, n);
    }

    // To add values to Queue
    void Enqueue(int value)
    {
        if (_Head == NULL)
        {
            _Head = new Node();
            _Head->Value = value;
            _Tail = _Head;
        }
        else
        {
            Node *Temp = _Tail;
            _Tail = new Node();
            Temp->Next = _Tail;
            _Tail->Value = value;
        }
    }
    void Enqueue(int values[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            Enqueue(values[i]);
        }
    }

    // to get and remove value from the Queue
    int Dequeue()
    {
        int temp = _Head->Value;
        if (_Head->Next != NULL)
            _Head = _Head->Next;
        else
        {

            _Head = NULL;
            _Tail = NULL;
        }
        return temp;
    }

    // To print all values inside the Queue
    void Print()
    {
        Node *Temp = _Head;
        while (Temp != NULL)
        {
            cout << Temp->Value << " ";
            Temp = Temp->Next;
        }
        if (_Head == NULL)
        {
            cout << "Queue is empty!!";
        }
        cout << "\n";
    }
    void clearMem()
    {
        deleteRecursively(_Head);
    }
    void deleteRecursively(Node *node)
    {
        if (node->Next != NULL)
        {
            deleteRecursively(node->Next);
        }
        cout << "value - " << node->Value << " is Being Deleted.\n";
        free(node);
    }
};

int main()
{
    int arr[] = {
        1,
        2,
        6,
        43,
        2,
        45,
        2};
    Queue Q1(arr, 7);
    Q1.Print();
    int add[] = {9, 8, 7};
    Q1.Enqueue(add, 3);
    Q1.Print();
    Q1.Enqueue(67);
    Q1.Print();
    Q1.clearMem();
    cout << sizeof(arr) / sizeof(arr[0]) << "\n"; // get length of arr
    cout << end(arr) - begin(arr);                // get length of arr
    return 0;
}