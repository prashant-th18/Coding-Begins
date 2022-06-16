#include<bits/stdc++.h>
using namespace std;
template <typename T>
class queueUsingArray
{
private:
    T *data;
    int nextIndex, mysize, size, frontIndex;

public:
    queueUsingArray() {
        mysize = 5;
        data = new T[mysize];
        size = 0;
        nextIndex = 0;
        frontIndex = -1;
    }
    void enqueue(T temp)
    {
        if (size == mysize)
        {
            T* newData = new T[mysize * 2];
            int j = 0;
            for (int i = frontIndex; i < mysize; ++i)
            {
                newData[j++] = data[i];
            }
            for (int i = 0; i < frontIndex; ++i)
            {
                newData[j++] = data[i];
            }
            delete[] data;
            data = newData;
            nextIndex = mysize;
            mysize *= 2;
            frontIndex = 0;
        }
        if (frontIndex == -1)
        {
            frontIndex = 0;
        }
        ++size;
        data[nextIndex] = temp;
        nextIndex = (nextIndex + 1) % mysize;
    }
    T front() const
    {
        if (size == 0)
        {
            cout << "Queue is Empty!" << endl;
            return 0;
        }
        return data[frontIndex];
    }
    T dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is Empty!" << endl;
            return 0;
        }
        T temp = data[frontIndex];
        frontIndex = (frontIndex + 1) % mysize;
        --size;
        if (size == 0)
        {
            frontIndex = -1;
            nextIndex = 0;
        }
        return temp;
    }
    bool isEmpty() const
    {
        return size == 0;
    }
    int size_fun() const
    {
        return size;
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
class QueueLL
{
private:
    Node<T> *head, *tail;
    int size;

public:
    QueueLL()
    {
        head = tail = nullptr;
        size = 0;
    }
    void enqueue(T data)
    {
        Node<T> *temp = new Node<T>(data);
        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            tail -> next = temp;
            tail = tail -> next;
        }
        ++size;
    }
    T front() const
    {
        if (size == 0)
        {
            cout << "Queue is Empty!";
            return 0;
        }
        return head -> data;
    }
    T dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is Empty!";
            return 0;
        }
        --size;
        T temp = head -> data;
        Node<T>* temp_next = head -> next;
        delete head;
        head = temp_next;
        return temp;
    }
    bool isEmpty() const
    {
        return size == 0;
    }
    int getSize() const
    {
        return size;
    }
};
int main()
{
    QueueLL<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.enqueue(50);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.front() << endl;
    cout << q.getSize() << endl;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    cout << q.getSize() << endl;
    cout << q.front() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q.front() << endl;
    return 0;
}