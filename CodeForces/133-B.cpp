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
void debug(int x){
#ifndef ONLINE_JUDGE 
    cout << "The value is : " << x << nline; 
#endif
}
void solve()
{
    map<char, string> mp;
    mp['<'] = "1001";
    mp['>'] = "1000";
    mp['+'] = "1010";
    mp['-'] = "1011";
    mp['.'] = "1100";
    mp[','] = "1101";
    mp['['] = "1110";
    mp[']'] = "1111";
    string s;
    cin >> s;
    string output = "";
    fl(i, 0, (int)s.size())
    {
        output += mp[s[i]];
    }
    int modulo = 1000003;
    ll result = 0, a = 1;
    for(int i = (int)output.size() - 1; i >= 0; --i)
    {
        if (output[i] - '0' == 1)
        {
            result =  ((result % modulo) + (a % modulo)) % modulo;
        }
        a = 2 * a % modulo;
    }
    cout << result;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
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