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
// Printing Subsequences of a string using bitmasking
void printSubsequences(const string &s)
{
    int size = (int)s.size();
    for(int i = 0; i < (1 << size); ++i)
    {
        string temp = "";
        int tt = i, cnt = 0;
        while(tt != 0)
        {
            if (tt & 1)
            {
                temp = s[size - 1 - cnt] + temp;
            }
            ++cnt;
            tt >>= 1;
        }
        cout << temp << nline;
    }
}
void solve()
{
    string s;
    cin >> s;
    printSubsequences(s);
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