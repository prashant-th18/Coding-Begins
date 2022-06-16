/*
    Author : prashant_th18
                            :)
*/
// Application of Pigeonhole principle
// Given a array, you have to find number of sub-arrays(GOOD SUB_ARRAY) such that sum of this sub-array
// is divisible by origial length of the array.
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
#define ld long double
#define pi pair<int, int>
#define pl pair<ll, ll>
#define m_p make_pair
#define vl vector<ll>
#define vi vector<int>
#define vpi vector<pi>
#define vpl vector<pl>
#define vd vector<double>
#define pb push_back
#define mll map<ll, ll>
#define be(v) begin(v), end(v)
#define fl(i, si, ei) for(ll i = si; i < ei; ++i)
#define nline "\n"
#define space " "
void debug(int x){
#ifndef ONLINE_JUDGE 
    cout << "The value is : " << x << nline; 
#endif
}
template <typename A>
A MIN(A a, A b)
{   
    if (a < b) return a;
    return b;
}
template <typename A>
A gcd(A a, A b)
{
    while (b) a%=b, swap(a, b);
    return a;
}
// Time Complexity - O(n)
// Space Complexity - O(n)
void solve()
{
    int n;
    cin >> n;
    vector<ll> sum(n + 1); // this acts as prefix-sum (1-based prefix sum)
    fl(i, 1 ,n + 1)
    {
        ll tt;
        cin >> tt;
        sum[i] += (sum[i - 1] + tt);
    }
    map<ll, ll>mp;
    // Since we have our prefix sum, now we calculate "sum[i] % n" for each element of 
    // this prefix sum, and by PIGEONHOLE principle, we get to know that since we have 
    // n + 1 elements in prefix sum, and we taking modulo of all elements by "n"
    // this means there will be at least 2 elements of "sum vector" for which 
    // this modulo will be equal, and therefore there will be at least one GOOD SUB_ARRAY.
    fl(i, 0, n + 1)
    {
        // why are we counting this is because we want to know for how many elements,
        // a % n == b % n, where a & b are the elements of the prefix sum.
        // just try with a example that when you'll get "a % n == b % n", there 
        // will be a good sub_array.
        ++mp[(sum[i] + n) % n]; // as sum[i] can be negative too.
    }
    ll cnt = 0;
    for(auto val : mp)
    {
        if (val.second >= 2)
        {
            cnt += (val.second * (val.second - 1) / 2);
        }
    }
    cout << cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
        cout << nline;
    }
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}