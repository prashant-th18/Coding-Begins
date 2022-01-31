/*
    Author : prashant_th18
                            :)
*/
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
template <typename A>
A MIN(A a, A b)
{
    if (a < b) return a;
    return b;
}
template <typename A>
A gcd(A a, A b)
{
    while (b) a %= b, swap(a, b);
    return a;
}
// 296 - C
void solve()
{
    ll n, k, m;
    cin >> n >> m >> k;
    vl v(n);
    fl(i, 0, n)
    cin >> v[i];

    vector<pair<pair<ll, ll>, ll>> operations(m); // l r di
    fl(i, 0, m)
    {
        cin >> operations[i].first.first >> operations[i].first.second >> operations[i].second;
    }
    // Maps for queries
    map<ll, ll> mp1, mp2;
    fl(i, 0, k)
    {
        ll t1, t2;
        cin >> t1 >> t2;
        ++mp1[t1], ++mp2[t2];
    }

    map<ll, ll> operation_intermediate;
    ll temp = 0;
    // 1 based indexing
    fl(i, 1, m + 1)
    {
        temp += mp1[i];
        operation_intermediate[i] = temp;
        if (mp2.count(i))
        {
            temp -= mp2[i];
        }
    }

    map<ll, ll> mp_operation1, mp_operation2;
    for (auto val : operation_intermediate)
    {
        ll index = val.first - 1;
        if (val.second != 0)
        {
            // debug(index);
            ll first_index = operations[index].first.first;
            ll second_index = operations[index].first.second;
            ll dd = operations[index].second;
            mp_operation1[first_index - 1] += (dd * val.second);
            mp_operation2[second_index - 1] += (dd * val.second);
        }
    }
    // reuse temp
    temp = 0;
    map<ll, ll> original;
    fl(i, 0, n)
    {
        temp += mp_operation1[i];
        original[i] += temp;
        if (mp_operation2.count(i))
        {
            temp -= mp_operation2[i];
        }
    }
    fl(i, 0, n)
    {
        cout << (v[i] + original[i]) << space;
    }
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