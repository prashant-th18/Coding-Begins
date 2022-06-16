/*
    Author : prashant_th18
                            :)
*/
// Print all Subsequences of a string without extra array
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pb push_back
#define nline "\n"
#define space " "
void printsubsequences(string s, string help)
{
    if (s == "")
    {
        cout << help << nline;
        return;
    }
    printsubsequences(s.substr(1), help +  "");
    printsubsequences(s.substr(1), help + s[0]);
}
void solve()
{
    string s;
    cin >> s;
    printsubsequences(s, "");
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
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