#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;

    Node(int data) : data(data) {next = nullptr;}
};
void print(Node* head)
{
    while (head != nullptr)
    {
        cout << head -> data << " " ;
        head = head -> next;
    }
}
Node* takeInput()
{
    int data;
    cin >> data;
    Node* head = nullptr;
    Node* tail = nullptr;
    while (data != -1)
    {
        Node* n = new Node(data);
        if (head == nullptr)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail -> next = n;
            tail = n;
        }
        cin >> data;
    }
    return head;
}
int return_index(Node* head, int t)
{
    int cnt {};
    while (cnt != t && (head != nullptr))
    {
        head = head -> next;
        ++cnt;
    }
    if (head == nullptr)
    {
        return -1;
    }
    return head -> data;
}
Node* insertNode(Node* head, int i, int data)
{
    Node* newNode = new Node(data);
    if (i == 0)
    {
        newNode -> next = head;
        return newNode;
    }
    else
    {
        i = i - 1;
        int cnt {};
        Node* temp = head;
        while (cnt != i && temp != nullptr)
        {
            temp = temp -> next;
            ++cnt;
        }
        if (temp != nullptr)
        {
            newNode -> next = temp -> next;
            temp -> next = newNode;
        }
        return head;
    }
}
Node* deleteNode(Node* head, int i)
{
    Node* temp = head;
    if (i == 0)
    {
        Node* a = temp -> next;
        delete head;
        return a;
    }
    else
    {
        int cnt{};
        while (cnt != i - 1 && temp -> next != nullptr)
        {
            temp = temp -> next;
            ++cnt;
        }
        if (temp -> next != nullptr)
        {
            Node* a = temp -> next;
            temp -> next = temp -> next -> next;
            delete a;
        }
        return head;
    }
}
int length_linked_list(Node* head, int cnt)
{
    if (head == nullptr)
    {
        return cnt;
    }
    return length_linked_list(head -> next, cnt + 1);
}
Node* insertNodeRecursively(Node* head, Node* temp, int cnt, int i, int data)
{
    if(i == 0)
    {
        Node* newNode = new Node(data);
        newNode -> next = head;
        return newNode;
    }
    if (temp == nullptr)
    {
        return head;
    }
    if (cnt == i - 1)
    {
        Node* newNode = new Node(data);
        newNode -> next = temp -> next;
        temp -> next = newNode;
        return head;
    }
    return insertNodeRecursively(head, temp -> next, cnt + 1, i, data);
    
}
Node* deleteNodeRecursively(Node* head, Node* temp, int cnt, int i)
{
    if (i == 0)
    {
        Node* a = head -> next;
        delete head;
        return a;
    }
    if (temp -> next == nullptr)
    {
        return head;
    }
    if (cnt == i - 1)
    {
        Node* a = temp -> next;
        temp -> next = temp -> next -> next;
        delete a;
        return head;
    }
    return deleteNodeRecursively(head, temp -> next, cnt + 1, i);
}
int main()
{
    Node* head = takeInput();
    int i, cnt{};
    cin >> i;
    head = deleteNodeRecursively(head, head, 0, i);
    // head = deleteNode(head, i);
    print(head);
    // cout << "\n";
    // cout << "Length of the linked list is : "  << length_linked_list(head, cnt);
    return 0;
}
