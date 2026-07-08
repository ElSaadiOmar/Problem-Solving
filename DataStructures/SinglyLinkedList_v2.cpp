// Problem: A second implementation of a singly linked list.
// Adds explicit DeleteFirstNode() and DeleteLastNode() helpers.

#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
};
void InsertAtBegining(Node *&Head, int Value)
{
    Node *new_node = new Node();

    new_node->value = Value;
    new_node->Next = Head;
    Head = new_node;
}
void DeleteFirstNode(Node *&Head)
{
    if (Head == nullptr)
    {
        return;
    }
    Node *save = Head;
    Head = save->Next;
    delete save;
    return;
}
void DeleteLastNode(Node *&Head)
{
    Node *CurrentNode = Head;
    Node *Pervious = Head;
    if (Head == nullptr)
    {
        return;
    }
    if (CurrentNode->Next == nullptr)
    {
        Head = nullptr;
        delete CurrentNode;
        return;
    }
    while (CurrentNode->Next != nullptr)
    {
        Pervious = CurrentNode;
        CurrentNode = CurrentNode->Next;
    }
    Pervious->Next = nullptr;
    delete CurrentNode;
    return;
}
Node *Find(Node *Head, int value)
{
    while (Head != NULL)
    {
        if (Head->value == value)
        {
            return Head;
        }
        Head = Head->Next;
    }
    return NULL;
}
void InsertAfter(Node *FindNode, int value)
{

    if (FindNode != nullptr)
    {
        Node *new_node = new Node();
        new_node->value = value;
        new_node->Next = FindNode->Next;
        FindNode->Next = new_node;
    }
    else
    {
        cout << "the given previous cannot be NULL";
        return;
    }
}
void InsertAtEnd(Node *&Head, int Value)
{
    Node *New_node = new Node();
    New_node->value = Value;
    New_node->Next = nullptr;
    if (Head == nullptr)
    {
        Head = New_node;
        return;
    }
    Node *LastNode = Head;
    while (LastNode->Next != nullptr)
    {
        LastNode = LastNode->Next;
    }
    LastNode->Next = New_node;
    return;
}
void DeleteNode(Node *&Head, int value)
{
    Node *PreviousNode = Head;
    Node *CurrentNode = Head;
    if (Head == nullptr)
    {
        return;
    }
    if (CurrentNode->value == value)
    {
        Head = CurrentNode->Next;
        delete CurrentNode;
        return;
    }
    while (CurrentNode != NULL)
    {
        if (CurrentNode->value == value)
        {
            PreviousNode->Next = CurrentNode->Next;
            delete CurrentNode;
            return;
        }
        PreviousNode = CurrentNode;
        CurrentNode = CurrentNode->Next;
    }
}
void PrintList(Node *Head)
{
    while (Head != NULL)
    {
        cout << (Head->value) << endl;
        Head = (Head->Next);
    }
}
int main()
{

    Node *Head = nullptr;
    // Node *Node1 = NULL;
    // Node *Node2 = NULL;
    // Node *Node3 = NULL;

    // Node1 = new Node();
    // Node2 = new Node();
    // Node3 = new Node();

    // Node1->value = 1;
    // Node2->value = 2;
    // Node3->value = 3;

    // Node1->Next = Node2;
    // Node2->Next = Node3;
    // Node3->Next = NULL;

    InsertAtEnd(Head, 4);
    InsertAtEnd(Head, 5);
    InsertAtEnd(Head, 6);
    InsertAtEnd(Head, 7);
    // Node *NodeF = Find(Head, 4);

    // if (NodeF != NULL)
    //     cout << NodeF->value;
    // else
    //     cout << "NOT FOUND";
    // DeleteAtBegining(Head);
    // InsertAfter(NodeF, 3);
    PrintList(Head);
    cout << "After\n";
    DeleteLastNode(Head);
    PrintList(Head);
}