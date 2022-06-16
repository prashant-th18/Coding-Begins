#include <iostream>
using namespace std;
/* What i need to make in this class
1) integer A, to make a array of this size storing coefficient of powers
2) Default constructor
3) Copy constructor
4) setCoefficient -> changes coefficient, if exceeds capacity, we increase array size
5) operator +
6) operator -
7) operator *
8) print()
9) operator =
*/
class Polynomial
{
private:
    int *data = nullptr;
    int capacity;

public:
    Polynomial()
    {
        capacity = 10;
        data = new int[capacity];
        for (int i = 0; i < capacity; ++i)
            data[i] = 0;
    }
    Polynomial(const Polynomial& a)
    {
        // cout << "CALL\n";
        capacity = a.capacity;
        data = new int[capacity];
        for (int i = 0; i < capacity; ++i)
            data[i] = 0;
        for (int i = 0; i < capacity; ++i)
        {
            data[i] = a.data[i];
        }
    }
    Polynomial& operator=(const Polynomial& a)
    {
        capacity = a.capacity;
        data = new int[capacity];
        for (int i = 0; i < capacity; ++i)
            data[i] = 0;
        for (int i = 0; i < capacity; ++i)
        {
            data[i] = a.data[i];
        }
        return *this;
    }
    void setcoefficient(int degree, int coeff)
    {
        if (degree < capacity)
        {
            data[degree] = coeff;
        }
        else
        {
            int precapacity = capacity;
            while (degree >= capacity)
            {
                capacity *= 2;
            }
            int* newdata = new int[capacity]();
            for (int i = 0; i < precapacity; ++i)
            {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            data[degree] = coeff;
        }
    }
    Polynomial operator+(const Polynomial& a)
    {
        if (capacity > a.capacity)
        {
            Polynomial temp(a);
            temp.setcoefficient(capacity - 1, 0);
            for (int i = 0; i < capacity; ++i)
            {
                temp.data[i] += (data[i]);
            }
            return temp;
        }
        else if (a.capacity > capacity)
        {
            Polynomial temp(*this);
            temp.setcoefficient(a.capacity - 1, 0);
            for (int i = 0; i < capacity; ++i)
            {
                temp.data[i] += (a.data[i]);
            }
            return temp;
        }
        else
        {
            Polynomial temp(*this);
            for (int i = 0; i < capacity; ++i)
            {
                temp.data[i] += (a.data[i]);
            }
            return temp;
        }
    }
    // -ve is similiar so discarding it
    Polynomial operator*(const Polynomial& a)
    {
        Polynomial temp;
        temp.setcoefficient(capacity + (a.capacity), 0);
        for(int i = 0; i < capacity; ++i)
        {
            for(int j = 0; j < a.capacity; ++j)
            {
                temp.data[i + j] += data[i] * a.data[j];
            }
        }
        return temp;
    }
    void print()
    {
        for (int i = 0; i < capacity; ++i)
        {
            cout << data[i] << "x^" << i << " ";
        }
    }

};
int main()
{
    Polynomial p1, p2;
    p1.setcoefficient(1, 3);
    p2.setcoefficient(2, 1);
    p2.setcoefficient(1, 2), p2.setcoefficient(0, 3);
    Polynomial p3 = p1 * p2;
    p1 = p1 + p3;
    p1.print();
    // p1.print();
    return 0;
}