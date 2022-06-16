// Insert Node and Delete Node
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
int main()
{
    Node* head = takeInput();
    int i;
    cin >> i;
    head = deleteNode(head, i);
    print(head);
    return 0;
}