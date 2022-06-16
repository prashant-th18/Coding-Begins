#include<iostream>
using namespace std;
// Time Complexity - O(n)
// Space Complexity - O(n)
double array_avg(int arr[], int len)
{
    // static int t = 0;
    if (len == 1)
    {
        return arr[len - 1] / 1.0;
    }
    else
    {
        return (arr[len - 1] + (len - 1) * array_avg(arr, len - 1)) / len; //   1 2 4 4 7     17.8
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << array_avg(arr, n);
    return 0;
}