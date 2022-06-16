#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Meta Binary Search is a form of Binary Search in which the index of the element 
    // which we want to find is constructed bit-by-bit
    int n; cin >> n; // Size of the vector
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int elem; cin >> elem; // Element we want to find
    // Now we want to know the number of bits included in maximum index of the array
    int index = (log2(n));
    // Now we use the for loop for contructing the index
    int ans = -1;
    for(int i = index; i >= 0; --i)
    {
        // Now we want to know that at the ith position from the left, should the bit be '1' or '0' ?
        int tt = ans + (1LL << i); // tt will give a index in the array
        // Cases -> 
        // 1) Index if >= size of the array
        if(tt >= n) continue;
        else
        {
            // Now we Consider the element at index tt
            // 1) We found the elem
            if(v[tt] == elem)
            {
                ans = tt;
                break;
            }
            // Element at index tt is greater than what we want to find
            if(v[tt] > elem)
            {
                continue;
            }
            else
            {
                if(ans == -1) ans = 0;
                ans += (1LL << i);
            }
        }
    }
    cout << ans;
    return 0;
}
