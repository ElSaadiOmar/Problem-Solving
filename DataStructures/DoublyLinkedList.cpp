// Problem: Implement a doubly linked list from scratch.
// Each node tracks both Next and Prev pointers for two-way traversal.

#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *Next;
    Node *Prev;
};
Node *Find(Node *head, int value)
{
    while (head != nullptr)
    {
        if (head->value == value)
        {
            return head;
        }
        head = head->Next;
    }
    return nullptr;
}

void InsertAtBegining(Node *&head, int value)
{
    Node *new_node = new Node();
    new_node->value = value;
    new_node->Prev = nullptr;

    if (head != nullptr)
    {
        new_node->Next = head;
        head->Prev = new_node;
    }
    head = new_node;
}
void InsertAfter(Node *current, int value)
{
    Node *New_node = new Node();
    New_node->value = value;
    New_node->Prev = current;
    New_node->Next = current->Next;
    if (current->Next != nullptr)
    {
        current->Next->Prev = New_node;
    }
    current->Next = New_node;
}
void InsertAtEnd(Node *&Head, int Value)
{
    Node *New_Node = new Node();
    New_Node->value = Value;
    New_Node->Next = nullptr;
    if (Head == nullptr)
    {
        New_Node->Prev = nullptr;
        Head = New_Node;
        return;
    }
    Node *current = Head;
    while (current->Next != nullptr)
    {
        current = current->Next;
    }
    current->Next = New_Node;
    New_Node->Prev = current;
}
void DeleteNode(Node *&Head, int value)
{
    Node *NodeToDelete = Find(Head, value);
    if (NodeToDelete == nullptr)
    {
        return;
    }

    if (Head == NodeToDelete)
    {
        Head = NodeToDelete->Next;
    }
    if (NodeToDelete->Prev != nullptr)
        NodeToDelete->Prev->Next = NodeToDelete->Next;
    if (NodeToDelete->Next != nullptr)
        NodeToDelete->Next->Prev = NodeToDelete->Prev;
    delete NodeToDelete;
}
void DeleteNode2(Node *&Head, Node *&NodeToDelete)
{
    if (Head == nullptr || NodeToDelete == nullptr)
    {
        return;
    }
    if (Head == NodeToDelete)
    {
        Head = NodeToDelete->Next;
    }
    if (NodeToDelete->Prev != nullptr)
        NodeToDelete->Prev->Next = NodeToDelete->Next;
    if (NodeToDelete->Next != nullptr)
        NodeToDelete->Next->Prev = NodeToDelete->Prev;
    delete NodeToDelete;
}
void DeleteFirstNode(Node *&Head)
{
    if (Head == nullptr)
    {
        return;
    }
    // if (Head->Next == nullptr)
    // {
    //     Head = nullptr;
    //     return;
    // }
    Node *Current = Head;
    while (Current->Prev != nullptr)
    {
        Current = Current->Prev;
    }
    Node *temp = Current;
    Current = Current->Next;
    if (Current != nullptr)
    {
        Current->Prev = nullptr;
    }
    delete temp;
}

void DeleteFirstNode(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    head = head->Next;
    if (head != NULL)
    {
        head->Prev = NULL;
    }
    delete temp;
}
void DeleteLastNode(Node *&Head)
{
    if (Head == nullptr)
    {
        return;
    }
    if (Head->Next == nullptr)
    {
        delete Head;
        Head = nullptr;
        return;
    }

    Node *Current = Head;
    while (Current->Next->Next != nullptr)
    {
        Current = Current->Next;
    }
    Node *temp = Current->Next;
    Current->Next = nullptr;
    delete temp;
}
int main()
{
    Node *head = nullptr;
    Node *leg;
    /*
        // Node *Node1 = nullptr;
        // Node *Node2 = nullptr;
        // Node *Node3 = nullptr;

        // Node1 = new Node();
        // Node2 = new Node();
        // Node3 = new Node();

        // Node1->value = 1;
        // Node2->value = 2;
        // Node3->value = 3;

        // Node1->Next = Node2;
        // Node1->Prev = nullptr;

        // Node2->Next = Node3;
        // Node2->Prev = Node1;

        // Node3->Next = nullptr;
        // Node3->Prev = Node2;

    // leg = Node3;*/

    InsertAtBegining(head, 5);
    InsertAtBegining(head, 4);
    InsertAtBegining(head, 2);
    InsertAtBegining(head, 1);
    InsertAtBegining(head, 0);
    Node *N1 = Find(head, 2);
    InsertAfter(N1, 3);
    DeleteFirstNode(head);
    while (head != nullptr)
    {
        cout << head->value << endl;
        head = head->Next;
    }
}
/*#include <iostream>
using namespace std;

template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~DoublyLinkedList() {
        clear();
    }

    // 1. Check if list is empty
    bool isEmpty() const {
        return head == nullptr;
    }

    // 2. Get size
    int getSize() const {
        return size;
    }

    // 3. Add to front (O(1))
    void push_front(const T& value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // 4. Add to back (O(1))
    void push_back(const T& value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // 5. Remove from front (O(1))
    void pop_front() {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        if (head == tail) {  // Only one node
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        size--;
    }

    // 6. Remove from back (O(1) with tail!)
    void pop_back() {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = tail;

        if (head == tail) {  // Only one node
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
        size--;
    }

    // 7. Insert at position (0-based index)
    void insert(int position, const T& value) {
        if (position < 0 || position > size) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 0) {
            push_front(value);
        }
        else if (position == size) {
            push_back(value);
        }
        else {
            Node* newNode = new Node(value);

            // Optimize: start from head or tail based on position
            Node* current;
            if (position < size / 2) {
                // Start from head
                current = head;
                for (int i = 0; i < position; i++) {
                    current = current->next;
                }
            }
            else {
                // Start from tail
                current = tail;
                for (int i = size - 1; i > position; i--) {
                    current = current->prev;
                }
            }

            // Insert newNode before current
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;

            size++;
        }
    }

    // 8. Remove at position
    void remove(int position) {
        if (position < 0 || position >= size) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 0) {
            pop_front();
        }
        else if (position == size - 1) {
            pop_back();
        }
        else {
            Node* current;

            // Optimize traversal
            if (position < size / 2) {
                current = head;
                for (int i = 0; i < position; i++) {
                    current = current->next;
                }
            }
            else {
                current = tail;
                for (int i = size - 1; i > position; i--) {
                    current = current->prev;
                }
            }

            // Remove current node
            current->prev->next = current->next;
            current->next->prev = current->prev;

            delete current;
            size--;
        }
    }

    // 9. Get value at position
    T get(int position) const {
        if (position < 0 || position >= size) {
            throw out_of_range("Index out of bounds");
        }

        Node* current;
        if (position < size / 2) {
            current = head;
            for (int i = 0; i < position; i++) {
                current = current->next;
            }
        }
        else {
            current = tail;
            for (int i = size - 1; i > position; i--) {
                current = current->prev;
            }
        }

        return current->data;
    }

    // 10. Update value at position
    void set(int position, const T& value) {
        if (position < 0 || position >= size) {
            cout << "Index out of bounds\n";
        }

        Node* current;
        if (position < size / 2) {
            current = head;
            for (int i = 0; i < position; i++) {
                current = current->next;
            }
        }
        else {
            current = tail;
            for (int i = size - 1; i > position; i--) {
                current = current->prev;
            }
        }

        current->data = value;
    }

    // 11. Search for value (returns first position or -1)
    int search(const T& value) const {
        Node* current = head;
        int position = 0;

        while (current != nullptr) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }

        return -1;
    }

    // 12. Reverse the list
    void reverse() {
        if (isEmpty() || head == tail) return;

        Node* current = head;
        Node* temp = nullptr;

        // Swap head and tail
        temp = head;
        head = tail;
        tail = temp;

        // Reverse all nodes
        current = head;  // Start from new head (old tail)
        while (current != nullptr) {
            // Swap prev and next pointers
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;

            // Move to next node (which is actually previous)
            current = current->next;
        }
    }

    // 13. Clear all nodes
    void clear() {
        while (!isEmpty()) {
            pop_front();
        }
    }

    // 14. Get front value
    T front() const {
        if (isEmpty()) {
            throw runtime_error("List is empty");
        }
        return head->data;
    }

    // 15. Get back value
    T back() const {
        if (isEmpty()) {
            throw runtime_error("List is empty");
        }
        return tail->data;
    }

    // 16. Display forward
    void displayForward() const {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* current = head;
        cout << "Forward (" << size << " nodes): NULL <-> ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout << " <-> NULL" << endl;
    }

    // 17. Display backward
    void displayBackward() const {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* current = tail;
        cout << "Backward (" << size << " nodes): NULL <-> ";
        while (current != nullptr) {
            cout << current->data;
            if (current->prev != nullptr) {
                cout << " <-> ";
            }
            current = current->prev;
        }
        cout << " <-> NULL" << endl;
    }

    // 18. Check if value exists
    bool contains(const T& value) const {
        return search(value) != -1;
    }

    // 19. Remove specific value (first occurrence)
    bool removeValue(const T& value) {
        int position = search(value);
        if (position != -1) {
            remove(position);
            return true;
        }
        return false;
    }

    // 20. Insert after a value (first occurrence)
    bool insertAfter(const T& target, const T& value) {
        int position = search(target);
        if (position != -1) {
            insert(position + 1, value);
            return true;
        }
        return false;
    }

    // 21. Insert before a value (first occurrence)
    bool insertBefore(const T& target, const T& value) {
        int position = search(target);
        if (position != -1) {
            insert(position, value);
            return true;
        }
        return false;
    }

};*/