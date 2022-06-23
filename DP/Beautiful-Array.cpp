/*

You are given an array a consisting of n integers. Beauty of array is the maximum sum of some consecutive subarray of this array (this subarray may be empty). For example, the beauty of the array [10, -5, 10, -4, 1] is 15, and the beauty of the array [-3, -5, -1] is 0.

You may choose at most one consecutive subarray of a and multiply all values contained in this subarray by x. You want to maximize the beauty of array after applying at most one such operation.

*/

/*
So, if your question is asking for a maximum subarray sum or some subsequence related thing, then it is highly 
possible that you need to use DP as this ->

dp(i, ..) : Maximum subarray sum such that the subarray ends at index "i"

In this question, you are told, that you can multiply any subarray with "x" at most once. So we need to keep a 
parameter to say that whether this multiplication operation is done in the past or not.
We do this using a "usable" variable which says ->
usable -> 0 => This operation is used earlier
usable -> 1 => This operation can be used now or it is(the multiplication operation) in use till index "i - 1"

So, you can see that in "usable -> 1", we have two ways ->
0. Either the operation is not in use yet.
1. The operation is currently in use.


DP State: 

dp(i, 0) : Maximum subarray sum till index "i", given that we have fully used the multiplication operation earlier

dp(i, 1, 0): Maximum subarray sum till index "i", given that we haven't used the multi.. operation yet.

dp(i, 1, 1): Maximum subarray sum til index "i", given that the multi.. operation is in use.


dp(i, 0): v[i] + max({0, dp(i - 1, 0), dp(i - 1, 1, 1)})
In this,
=> dp(i - 1, 0) : This tells that the operation was stopped way before in the array
=> dp(i - 1, 1, 1): This tells that the operation is stopped on index "i - 1"

dp(i, 1, 0) : max(v[i], v[i] + dp(i - 1, 1, 0))


dp(i, 1, 1) : Remember, now it is currently in use...
Max of all these :
1. x * v[i] // It is in use now

2. x * v[i] + max({0, dp(i - 1, 1, 0), dp(i - 1, 1, 1)})
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, x; cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(2, 0)));
    // dp[i][0][0] == dp(i, 0)
    // dp[i][1][0] == dp(i, 1, 0)
    // dp[i][1][1] == dp(i, 1, 1)
    
    // Base Case
    dp[0][1][0] = v[0];
    dp[0][1][1] = x * v[0];

    ll ans = max({0LL, v[0], v[0] * x});
    for (int i = 1; i < n; i++) {
        dp[i][0][0] = v[i] + max({0LL, dp[i - 1][0][0], dp[i - 1][1][1]});
        dp[i][1][0] = v[i] + max(0LL, dp[i - 1][1][0]);
        dp[i][1][1] = x * v[i] + max({0LL, dp[i - 1][1][0], dp[i - 1][1][1]});
        ans = max({ans, dp[i][0][0], dp[i][1][0], dp[i][1][1]});
    }
    cout << ans;
    return 0;
}
