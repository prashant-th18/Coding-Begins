/*
    Author : prashant_th18
                            :)
*/
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
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
string return_my_string(string s, int it)
{
    string temp = "";
    fl(i, 0, sz(s))
    {
        if (i == it)
        {
            continue;
        }
        else
        {
            temp += s[i];
        }
    }
    return temp;
}
string return_my_string2(string s, int it, int it1)
{
    string temp = "";
    fl(i, 0, sz(s))
    {
        if (i == it || i == it1)
        {
            continue;
        }
        else
        {
            temp += s[i];
        }
    }
    return temp;
}
string that_substr_part(string temp)
{
    while (sz(temp) != 1 && temp[0] == '0')
    {
        temp = temp.substr(1);
    }
    return temp;
}
void solve()
{
    string s;
    cin >> s;
    map<int, set<int>> mp;
    vector<string> v;
    ll sum {};
    fl(i, 0, sz(s))
    {
        sum += (s[i] - '0');
        mp[s[i] - '0'].insert(i);
    }
    int rem = sum % 3;
    if (rem == 0)
    {
        cout << s;
        return;
    }
    else if (rem == 1)
    {
        if (sz(mp[1]) != 0)
        {
            auto it = *mp[1].rbegin();
            string temp1 = return_my_string(s, it);
            temp1 = that_substr_part(temp1);
            // cout << temp1 << nline;
            v.pb(temp1);
        }
        if (sz(mp[4]) != 0)
        {
            v.pb(that_substr_part(return_my_string(s, *mp[4].rbegin())));
        }
        if (sz(mp[2]) >= 2)
        {
            auto it = mp[2].rbegin();
            auto it1 = it++;
            v.pb(that_substr_part(return_my_string2(s, *it, *it1)));
        }
        if (sz(mp[7]) != 0)
        {
            v.pb(that_substr_part(return_my_string(s, *mp[7].rbegin())));
        }
        if (sz(mp[2]) && sz(mp[5]))
        {
            auto it = mp[2].rbegin();
            auto it1 = mp[5].rbegin();
            v.pb(that_substr_part(return_my_string2(s, *it, *it1)));
        }
        if (sz(mp[2]) && sz(mp[8]))
        {
            auto it = mp[2].rbegin();
            auto it1 = mp[8].rbegin();
            v.pb(that_substr_part(return_my_string2(s, *it, *it1)));
        }
        if (sz(mp[8]) && sz(mp[5]))
        {
            auto it = mp[8].rbegin();
            auto it1 = mp[5].rbegin();
            v.pb(that_substr_part(return_my_string2(s, *it, *it1)));
        }
        if (sz(mp[5]) >= 2)
        {
            auto it = mp[5].rbegin();
            auto it1 = it++;
            v.pb(that_substr_part(return_my_string2(s, *it, *it1)));
        }
        if (sz(mp[8]) >= 2)
        {
            auto it = mp[8].rbegin();
            auto it1 = it++;
            v.pb(that_substr_part(return_my_string2(s, *it, *it1)));
        }
    }
    else
    {
        if (sz(mp[2]) != 0)
        {
            v.pb(that_substr_part(return_my_string(s, *mp[2].rbegin())));
        }
        if (sz(mp[1]) >= 2)
        {
            auto it = mp[1].rbegin();
            auto it1 = it++;
            v.pb(that_substr_part(return_my_string2(s, *it, *it1)));
        }
        if (sz(mp[5]) != 0)
        {
            v.pb(that_substr_part(return_my_string(s, *mp[5].rbegin())));
        }
        if (sz(mp[1]) && sz(mp[4]))
        {
            auto it = mp[1].rbegin();
            auto it1 = mp[4].rbegin();
            v.pb(that_substr_part(return_my_string2(s, *it, *it1)));
        }
        if (sz(mp[8]) != 0)
        {
            v.pb(that_substr_part(return_my_string(s, *mp[8].rbegin())));
        }
        if (sz(mp[1]) && sz(mp[7]))
        {
            auto it = mp[1].rbegin();
            auto it1 = mp[7].rbegin();
            v.pb(that_substr_part(return_my_string2(s, *it, *it1)));
        }
        if (sz(mp[4]) >= 2)
        {
            auto it = mp[4].rbegin();
            auto it1 = it++;
            v.pb(that_substr_part(return_my_string2(s, *it, *it1)));
        }
        if (sz(mp[7]) >= 2)
        {
            auto it = mp[7].rbegin();
            auto it1 = it++;
            v.pb(that_substr_part(return_my_string2(s, *it, *it1)));
        }
        if (sz(mp[4]) && sz(mp[7]))
        {
            auto it = mp[4].rbegin();
            auto it1 = mp[7].rbegin();
            v.pb(that_substr_part(return_my_string2(s, *it, *it1)));
        }
    }
    ll mysize = INT_MIN;
    fl(i, 0, sz(v))
    {
        if (sz(v[i]))
            mysize = MAX(mysize, sz(v[i]));
        // cout << v[i] << nline;
    }
    if (mysize == INT_MIN)
    {
        cout << -1;
    }
    else
    {
        for (int i = 0; i < sz(v); ++i)
        {
            if (sz(v[i]) == mysize)
            {
                cout << v[i];
                return;
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    cout << fixed << setprecision(0);
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