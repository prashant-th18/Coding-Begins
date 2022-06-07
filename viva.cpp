#include <bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node* next;
    node(int d = 0) {
        data = d;
    }
};
node* takeInput() {
    node* head = nullptr, *tail = nullptr;
    while(1) {
        cout << "Enter \n1. For entering element\n2. For exiting the loop\n";
        int c; cin >> c;
        if(c == 1) {
            cout << "Enter element to be inserted\n";
            int elem; cin >> elem;
            node* temp = new node(elem);
            if(head == nullptr) {
                head = tail = temp;
            }
            else {
                tail -> next = temp;
                tail = tail -> next;
            }
        }
        else break;
    }
    return head;
}
node* merge(node* f, node* s) {
    node* head = nullptr, *tail = nullptr;
    while(f != nullptr || s != nullptr) {
        if(f != nullptr && s != nullptr) {
            if(f -> data < s -> data) {
                if(!head) {
                    head = tail = f;
                }
                else {
                    tail -> next = f;
                    tail = tail -> next;
                }
                f = f -> next;
            }
            else {
                if(!head) {
                    head = tail = s;
                }
                else {
                    tail -> next = s;
                    tail = tail -> next;
                }
                s = s -> next;
            }
        }
        else if(f != nullptr) {
            if(head == nullptr) {
                head = tail = f;
            }
            else {
                tail -> next = f;
                tail = tail -> next;
            }
            f = f -> next;
        }
        else {
            if(head == nullptr) {
                head = tail = s;
            }
            else {
                tail -> next = s;
                tail = tail -> next;
            }
            s = s -> next;
        }
    }
    if(tail != nullptr) tail -> next = nullptr;
    return head;
}
void print(node* t) {
    cout << "Elements of the LinkedList : ";
    while(t != nullptr) {
        cout << (t -> data) << ' ';
        t = t -> next;
    }
}
int main() {
    node* f, *s;
    f = s = nullptr;
    cout << "For First LinkedList\n";
    f = takeInput();
    cout << "For Second LinkedList\n";
    s = takeInput();
    node* sorted = merge(f, s);
    print(sorted);
    return 0;
}