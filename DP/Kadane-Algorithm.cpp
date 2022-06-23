/*

Given a array of positive and negative numbers, you need to find the maximum subarray sum.
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n; // Number of elements
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int maxx = INT_MIN; // Maximum sub-array sum we got till now
    int curr = 0; // Current tells the sum of the current sub-array which we are keeping with us.
    for(int i = 0; i < n; ++i) {
        curr += v[i]; // Assuming that this element should also be present in the subarray which is ending at
                      // "i - 1"
        if(curr > maxx) {
            maxx = curr;
            // Updating the maximum since "curr" > "maxx"
        }
        if(curr < 0) {
            curr = 0;
            // Since current is less than 0, so you can think now that any subarray ahead of this index,
            // current will only reduce it's value, but will never increase.
            // [-2, 1, 2, 3]
            // So, at first my current will become "-2".
            // So, now if I just keep this curr with me, then it will decrease the value
            // because [-2, 1, 2, 3] -> 4
            // But, [1, 2, 3] -> 6 (Higher value)
        }
    }
    cout << maxx;
    return 0;
}
