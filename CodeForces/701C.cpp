// Sliding Window Problem (According to me) 
// Question Link -> https://codeforces.com/contest/701/problem/C
/*
    Author : prashant_th18
                            :)
*/
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vl vector<ll>
#define vpl vector<pl>
#define mll map<ll, ll>
#define m_p make_pair
#define pb push_back
#define all(v) begin(v), end(v)
#define PI 3.1415926535897932384626
#define fl(i, si, ei) for(ll i = si; i < ei; ++i)
#define nline "\n"
#define space " "
#define ff first
#define ss second
#define sz(v) ((ll)(v).size())
#define set_bits __builtin_popcountll
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " : "; _print(x); cerr << nline;
#else
#define debug(x)
#endif
#define print(x) cout << x << space;
#define readv(v) fl(i, 0, size(v)) cin >> v[i]
#define readvp(v) fl(i, 0, size(v)) cin >> v[i].ff >> v[i].ss
// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
template <typename T> void _print(vector <T> v) { cerr << "[ "; for (auto myval : v) cerr << myval << " "; cerr << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cerr << "[ "; for (auto myval : v) cerr << myval.ff << space << myval.ss << " "; cerr << "]"; }
template <typename T> void _print(set <T> v) { cerr << "[ "; for (auto myval : v) cerr << myval << " "; cerr << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cerr << "[ "; for (auto myval : v) cerr << myval.ff << space << myval.ss << " "; cerr << "]"; }
void _print(int a) {cerr << a;}
void _print(ll a) {cerr << a;}
void _print(ull a) {cerr << a;}
void _print(char a) {cerr << a;}
void _print(string a) {cerr << a;}
void _print(double a) {cerr << a;}
void _print(ld a) {cerr << a;}
template <typename A> A MIN(A a, A b) { if (a < b) return a; return b; }
template <typename A> A MAX(A a, A b) { if (a > b) return a; return b; }
template <typename A> A gcd(A a, A b) { while (b) a %= b, swap(a, b); return a; }
template <typename T> T ABS(T a) { return (a < 0) ? (-a) : (a);}
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    set<char> help;
    for(int i = 0; i < sz(s); ++i) help.insert(s[i]);
    int diff = sz(help);
    ll k = 0; // this will be used to reduce the length of string
    int freq[255] {0};
    ll maxx = LONG_LONG_MAX;
    set<char> st;
    for(ll i = 0; i < n; ++i)
    {
        ++freq[s[i]];
        st.insert(s[i]);
        if (s[i] == s[k])
        {
            while(k < i)
            {
                if(freq[s[k]] > 1)
                {
                    --freq[s[k]];
                }
                else
                {
                    break;
                }
                ++k;
            }
        }
        if(sz(st) == diff)
        maxx = MIN(maxx, i - k + 1);
    }
    cout << maxx;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    cout << fixed << setprecision(0);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
        cout << nline;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}