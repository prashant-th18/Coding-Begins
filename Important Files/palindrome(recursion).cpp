/*
    Author : prashant_th18
                            :)
*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define nline "\n"
bool palindrome(char *a, int size)
{
	if (size == 0 || size == 1)
	{
		return true;
	}
	bool ans = palindrome(a + 1, size - 2);
	if (!ans)
	{
		return ans;
	}
	else
	{
		if (a[0] == a[size - 1])
		{
			return (ans);
		}
		else
		{
			return (!ans);
		}
	}
}
void solve()
{
    char s[1001];
    cin >> s;
    cout << boolalpha << palindrome(s, sizeof(s));
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