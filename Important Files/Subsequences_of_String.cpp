/*
    Author : prashant_th18
                            :)
*/
// All subsequences of a string in a string array
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pb push_back
#define nline "\n"
#define space " "
int subsequences(string input, string output[])
{
    if (input == "")
    {
        output[0] = "";
        return 1;
    }
    int x = subsequences(input.substr(1), output);
    for (int i = 0; i < x; ++i)
    {
        output[x + i] = input[0] + output[i];
    }
    return 2 * x;
}
void solve()
{
    string input;
    cin >> input;
    int n = static_cast<int>(pow(2, (int)input.size()));
    string output[n];
    subsequences(input, output);
    for (int i = 0; i < n; ++i)
    {
        cout << output[i] << nline;
    }
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