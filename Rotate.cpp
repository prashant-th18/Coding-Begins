#include <bits/stdc++.h>
using namespace std;
// Rotate Function to rotate vector / array
vector<int> rotate_vector(vector<int> v)
{
    vector<int> rotated(v.size());
    int n = v.size();
    for (int i = 0; i < n; ++i)
    {
        rotated[i] = v[(n - 1 + i) % n];
        // n - 1 
        // n % n
    }
    return rotated;
}
int main()
{
    vector<int> v {1, 2, 3, 4};
    vector<int> rotated = rotate_vector(v);
    int n = v.size();
    for (int i = 0; i < n; ++i)
    {
        cout << rotated[i] << " ";
    }
    cout << endl;
    // Taking Use of STL
    rotate(v.begin(), v.begin() + n - 1, v.end());
    for (int i = 0; i < n; ++i)
    {
        cout << v[i] << ' ';
    }
    return 0;
}