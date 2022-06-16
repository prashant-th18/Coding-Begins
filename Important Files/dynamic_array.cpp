// Implementation of dynamic_array(something like vector)
#include<iostream>
using namespace std;
class dynamic_array
{
private:
    int* data = nullptr;
    int nextIndex;
    int capacity;

public:
    dynamic_array()
    {
        data = new int[5];
        nextIndex = 0, capacity = 5;
    }
    dynamic_array(const dynamic_array& a)
    {
        if (data == nullptr)
        {
            int size = a.cap();
            data = new int[size];
            nextIndex = a.index();
            capacity = a.cap();
            for (int i = 0; i < nextIndex; ++i)
            {
                data[i] = a.get(i);
            }
        }
    }
    dynamic_array operator=(const dynamic_array& a)
    {
        capacity = a.cap();
        data = new int[a.capacity];
        nextIndex = a.index();
        for (int i = 0; i < nextIndex; ++i)
        {
            data[i] = a.get(i);
        }
    }
    void pb(int num)
    {
        if (nextIndex != capacity)
        {
            data[nextIndex++] = num;
            return;
        }
        else
        {
            capacity *= 2;
            int* newdata = new int[capacity];
            for (int i = 0; i < capacity / 2; ++i)
            {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            data[nextIndex++] = num;
        }
    }
    const int get(int i) const
    {
        if (i < nextIndex)
        {
            return data[i];
        }
        else
        {
            return -1;
        }
    }
    void change_element(int i, int num)
    {
        if (i < nextIndex)
        {
            data[i] = num;
        }
        else if (i == nextIndex)
        {
            pb(num);
        }
        else
        {
            return;
        }
    }
    void print()
    {
        for (int i = 0; i < nextIndex; ++i)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    // getters and setters
    int index() const
    {
        return nextIndex;
    }
    int cap() const
    {
        return capacity;
    }
    const int* const pointer() const
    {
        return data;
    }

};
int main()
{
    dynamic_array d1;
    d1.pb(1), d1.pb(2), d1.pb(1), d1.pb(4), d1.pb(1), d1.pb(5), d1.pb(1), d1.pb(1), d1.pb(7);
    // d1.print();
    dynamic_array d2;
    d2 = d1;
    // cout << "\n" << d1.get(2);
    d2.pb(123);
    d2.print();
    d1.print();
    return 0;
}