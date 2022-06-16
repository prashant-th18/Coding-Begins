// Code for taking and printing input in a Linked List
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
int main()
{
    Node* head = takeInput();
    print(head);
    return 0;
}