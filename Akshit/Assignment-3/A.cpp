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
int length_linked_list(Node* head, int cnt)
{
    if (head == nullptr)
    {
        return cnt;
    }
    return length_linked_list(head -> next, cnt + 1);
}
Node* takeInput()
{
    int data;
    cin >> data;
    Node* head = nullptr;
    Node* tail = nullptr;
    // If -1 is given we will stop taking the input of linked list
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
void reverse_List(Node* head)
{
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
}
void sortList(Node* head) {
        Node *current = head, *index = NULL;
        int temp;

        if(head == NULL) {
            return;
        }
        else {
            while(current != NULL) {
                //Node index will point to node next to current
                index = current->next;

                while(index != NULL) {
                    if(current->data > index->data) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
        }
    }
}
int main()
{
    Node* mylist = takeInput();
    print(mylist); // Printing
    insertNodeRecursively(mylist, mylist, 0, 0, 111); /// 111 is inserted first
    print(mylist);
    int mlength = length_linked_list(mylist, 0);
    insertNodeRecursively(mylist, mylist, 0, mlength / 2, 222); /// 222 is inserted middle
    print(mylist);
    mlength++;
    insertNodeRecursively(mylist, mylist, 0, mlength - 1, 333); /// 333 is inserted last
    print(mylist);

    return 0;
}
