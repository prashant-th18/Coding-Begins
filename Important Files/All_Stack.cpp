#include<iostream>
using namespace std;
template <typename T>
class stackUsingArray
{
private:
    T* data = nullptr; // dynamically allocated array
    int nextIndex;
    int capacity;

public:
    stackUsingArray()
    {
        capacity = 4;
        data = new T[capacity];
        nextIndex = 0;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    int size()
    {
        return nextIndex;
    }

    void push(T elem)
    {
        if (nextIndex == capacity)
        {
            T *newdata = new T[capacity * 2];
            for (int i = 0; i < capacity; ++i)
            {
                newdata[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newdata;
        }
        data[nextIndex++] = elem;
    }
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return 0;
        }
        return data[--nextIndex];
    }
};
template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node(T data)
    {
        this -> data = data;
        next = nullptr;
    }
};
template <typename T>
class stack
{
private:
    Node<T>* head;
    int mysize;

public:
    stack()
    {
        head = nullptr;
        mysize = 0;
    }
    void push(T data)
    {
        Node<T> *temp = new Node(data);
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            temp -> next = head;
            head = temp;
        }
        ++mysize;
    }
    T top() const
    {
        if (head != nullptr)
        {
            return head -> data;
        }
        return 0;
    }
    T pop()
    {
        if (head == nullptr)
        {
            return 0;
        }
        Node<T>* temp = head -> next;
        T data = head -> data;
        delete head;
        head = temp;
        --mysize;
        return data;
    }
    bool isEmpty() const
    {
        return head == nullptr;
    }
    int size() const
    {
        return mysize;
    }
};
int main()
{
    stack<int> st;
    st.push(13);
    st.push(47);
    cout << st.size() << endl << st.isEmpty() << endl << st.pop() << endl << st.top() << endl;
    return 0;
}