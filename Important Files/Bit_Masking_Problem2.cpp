/*
    Author : prashant_th18
                            :)
*/
// You are given a vector in which all numbers are occuring three times except a single number
// Find that number.(Adobe, Amazon Interview Problem)
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
void debug(int x) {
#ifndef ONLINE_JUDGE
    cout << "The value is : " << x << nline;
#endif
}
void solve()
{
    int n;
    cin >> n;
    vi v(n);
    // We will store bit by bit in the "bits" array.
    vl bits(32);
    fl(i, 0, n)
    {
        cin >> v[i];
        int j = 0;
        while (v[i] != 0)
        {
            bits[j] += (v[i] & 1);
            ++j;
            v[i] >>= 1;
        }
    }
    ll res = 0;
    fl(i, 0, 32)
    {
        bits[i] %= 3; // If remainder is 1, it is only possible if that unique number has a set bit at this position.
        res += (bits[i] << i);
    }
    cout << res;
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