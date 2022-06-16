#include<bits/stdc++.h>
using namespace std;
#define ll long long
int binarySearchRecursively(int *a, int s, int e, int key)
{
    if (s > e)
    {
        return -1;
    }
    int mid = (s + e) / 2;
    if(a[mid] == key)
    {
        return mid;
    }
    else if (a[mid] > key)
    {
        return binarySearchRecursively(a, s, mid - 1, key);
    }
    else
    {
        return binarySearchRecursively(a, mid + 1, e, key);
    }
}
int main()
{
    int a[] {1, 2, 3, 4, 5, 10};
    cout << binarySearchRecursively(a, 0, 5, 10);
    return 0;
}