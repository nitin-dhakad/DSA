#include <iostream>
using namespace std;

struct Node
{
    int Value;
    Node *Next = NULL;
};

class Queue
{
public:
    Node *Head = NULL;
    Node *Tail = NULL;

    // Constructor
    Queue() {}
    Queue(int value)
    {
        Head = new Node();
        Head->Value = value;
        Tail = Head;
    }
    Queue(int values[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            Enqueue(values[i]);
        }
    }

    //To add values to Queue
    void Enqueue(int value)
    {
        if (Head == NULL)
        {
            Head = new Node();
            Head->Value = value;
            Tail = Head;
        }
        else
        {
            Node *Temp = Tail;
            Tail = new Node();
            Temp->Next = Tail;
            Tail->Value = value;
        }
    }
    void Enqueue(int values[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            Enqueue(values[i]);
        }
    }

    //to get and remove value from the Queue
    int Dequeue()
    {
        int temp = Head->Value;
        if (Head->Next != NULL)
            Head = Head->Next;
        else
        {

            Head = NULL;
            Tail = NULL;
        }
        return temp;
    }

    //To print all values inside the Queue
    void Print()
    {
        Node *Temp = Head;
        while (Temp != NULL)
        {
            cout << Temp->Value << " ";
            Temp = Temp->Next;
        }
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
    Q1.Enqueue(arr, 7);
    Q1.Print();
    return 0;
}