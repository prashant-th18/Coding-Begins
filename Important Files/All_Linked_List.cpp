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
    if (i == 0)
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
int returnIndex(Node* head, int data1)
{
    int cnt{};
    while (head != nullptr)
    {
        if (head -> data == data1)
        {
            return cnt;
        }
        head = head -> next;
        ++cnt;
    }
    return -1;
}
Node* appendLastToFirst(Node* head, int i)
{
    if (i == 0)
    {
        return head;
    }
    int length {};
    Node* temp = head;
    while (temp != nullptr)
    {
        ++length;
        temp = temp -> next;
    }
    int cnt = length - i - 1;
    int cnt1 {};
    temp = head;
    while (cnt1 != cnt)
    {
        ++cnt1;
        temp = temp -> next;
    }
    Node* newHead = temp -> next;
    temp -> next = nullptr;
    Node* tail = newHead;
    while (tail -> next != nullptr)
    {
        tail = tail -> next;
    }
    tail -> next = head;
    return newHead;
}
Node* removeDuplicates(Node* head)
{
    Node* tail = head;
    Node* newHead = head;
    while (newHead != nullptr)
    {
        int d = newHead -> data;
        int cnt { -1};
        while (tail -> next != nullptr && tail -> next -> data == d)
        {
            ++cnt;
            Node* a = tail -> next;
            // delete tail;
            if (cnt > 0)
            {
                delete tail;
                tail = nullptr;
            }
            tail = a;
        }
        Node* a = tail -> next;
        if (cnt >= 0)
        {
            delete tail;
            tail = nullptr;
        }
        newHead -> next = a;
        newHead = newHead -> next;
        tail = newHead;
    }
    return head;
}
void print_reversed(Node* head)
{
    int length = length_linked_list(head, 0);
    for (int i = length; i >= 1; --i)
    {
        Node* temp = head;
        int cnt = i;
        --cnt;
        while (cnt--)
        {
            temp = temp -> next;
        }
        cout << temp -> data << " ";
    }
}
bool palindrome_Linked_List(Node* head)
{
    int length = length_linked_list(head, 0);
    for (int i = 0; i < length / 2; ++i)
    {
        int data1 = 0, data2 = 0;
        int cnt = length - i;
        --cnt;
        Node* temp = head;
        for (int j = 0; j < cnt; ++j)
        {
            if (j == i) data1  = temp -> data;
            temp = temp -> next;
        }
        data2 = temp -> data;
        if (data1 != data2) return false;
    }
    return true;
}
void mid_point_LL(Node* head)
{
    if (head == nullptr) return;
    int length = length_linked_list(head, 0);
    int i = ceil((double)length / 2);
    --i;
    int cnt {};
    Node* temp = head;
    while (cnt != i)
    {
        ++cnt;
        temp = temp -> next;
    }
    cout << temp -> data;
}
void fast_mid_point_LL(Node* head)
{
    if (head == nullptr)
    {
        return;
    }
    Node* slow = head;
    Node* fast = head -> next;
    while (fast != nullptr && fast -> next != nullptr)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    cout << slow -> data;
}
Node* merge_two_sorted(Node* head1, Node* head2)
{
    Node* newNode = nullptr;
    Node* temp = newNode;
    while (head1 != nullptr || head2 != nullptr)
    {
        if (head1 != nullptr && head2 != nullptr)
        {
            if (head1 -> data <= head2 -> data)
            {
                if (newNode == nullptr)
                {
                    newNode = head1;
                    temp = newNode;
                }
                else
                {
                    temp -> next = head1;
                    temp = temp -> next;
                }
                head1 = head1 -> next;
            }
            else
            {
                if (newNode == nullptr)
                {
                    newNode = head2;
                    temp = newNode;
                }
                else
                {
                    temp -> next = head2;
                    temp = temp -> next;
                }
                head2 = head2 -> next;
            }
        }
        else if (head1 != nullptr)
        {
            if (newNode == nullptr)
            {
                newNode = head1;
                temp = head1;
            }
            else
            {
                temp -> next = head1;
                temp = temp -> next;
            }
            head1 = head1 -> next;
        }
        else
        {
            if (newNode == nullptr)
            {
                newNode = head2;
                temp = head2;
            }
            else
            {
                temp -> next = head2;
                temp = temp -> next;
            }
            head2 = head2 -> next;
        }
    }
    return newNode;
}
Node* reverse_LL(Node* head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Node* temp = reverse_LL(head -> next);
    if (temp == nullptr)
    {
        temp = head;
    }
    else
    {
        Node* a = temp;
        while (a -> next != nullptr)
        {
            a = a -> next;
        }
        a -> next = head;
        a = a -> next;
        a -> next = nullptr;
    }
    return temp;
}
// Fast reverse Linked List
class mypair
{
public:
    Node* head1;
    Node* tail1;
    mypair(Node* head, Node* tail)
    {
        this -> head1 = head;
        this -> tail1 = tail;
    }
};
mypair reverse_LL_fast(Node* head)
{
    if (head == nullptr || head -> next == nullptr)
    {
        return mypair(head, head);
    }
    mypair temp = reverse_LL_fast(head -> next);
    temp.tail1 -> next = head;
    head -> next = nullptr;
    temp.tail1 = temp.tail1 -> next;
    return temp;
}
Node* reverse_LL_fast_real(Node* head)
{
    return reverse_LL_fast(head).head1;
}
//
// best possible way to reverse linked list using recursion
Node* reverse_LL_fast_2(Node* head)
{
    if (head == nullptr || head -> next == nullptr)
    {
        return head;
    }
    Node* temp = reverse_LL_fast_2(head -> next);
    Node* tail = head -> next;
    tail -> next = head;
    head -> next = nullptr;
    return temp;
}
Node* reverse_Iterative(Node* head) // Time Complexity - O(n)
{
    Node* pre = nullptr;
    Node* cur = head;
    Node* next = nullptr;
    while (cur != nullptr)
    {
        next = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
int return_index_recursive(Node* head, int i, int mydata)
{
    if (head == nullptr)
    {
        return -1;
    }
    if (head -> data == mydata)
    {
        return i;
    }
    return return_index_recursive(head -> next, i + 1, mydata);
}
Node* even_After_Odd(Node* head)
{
    Node* head1 = nullptr, *tail1 = nullptr, *head2 = nullptr, *tail2 = nullptr;
    while (head != nullptr)
    {
        Node* a = new Node(head -> data);
        if ((head -> data) & 1)
        {
            if (head1 == nullptr)
            {
                head1 = a;
                tail1 = a;
            }
            else
            {
                tail1 -> next = a;
                tail1 = tail1 -> next;
            }
        }
        else
        {
            if (head2 == nullptr)
            {
                head2 = a;
                tail2 = a;
            }
            else
            {
                tail2 -> next = a;
                tail2 = tail2 -> next;
            }
        }
        head = head -> next;
    }
    if (tail1 != nullptr)
    {
        tail1 -> next = head2;
        return head1;
    }
    return head2;
}
Node* del_Every_N(Node* head, int m, int n)
{
    if (m == 0)
    {
        return nullptr;
    }
    Node* myhead = nullptr, *mytail = nullptr;
    int cnt{};
    while (head != nullptr)
    {
        if (cnt == m)
        {
            int mycnt {};
            Node *a = head;
            while (head != nullptr && mycnt != n && head -> next != nullptr)
            {
                a = head -> next;
                if (mycnt >= 0)
                {
                    delete head;
                    head = a;
                }
                ++mycnt;
            }
            if (mycnt != n && head != nullptr)
            {
                delete head;
                head = nullptr;
            }
            if (head == nullptr)
            {
                mytail -> next = head;
                return myhead;
            }
            cnt = 0;
            continue;
        }
        else
        {
            if (mytail == nullptr)myhead = head, mytail = head;
            else
            {
                mytail -> next = head;
                mytail = mytail -> next;
            }
            head = head -> next;
        }
        ++cnt;
    }
    return myhead;
}
int main()
{
    Node* head = takeInput();
    int n, m;
    cin >> m >> n;
    head = del_Every_N(head, m, n);
    print(head);
    return 0;
}
