#ifndef ONLINE_JUDGE
    #define LOCAL
        #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef long double ld;
#define all(v) begin(v), end(v)
#define ff first
#define ss second
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " : "; _print(x); cerr << nline;
#else
#define debug(x)
#endif

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
template <typename T> void _print(vector <T> v) { cerr << "[ "; for (auto myval : v) cerr << myval << " "; cerr << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cerr << "[ "; for (auto myval : v) cerr << myval.ff << ' ' << myval.ss << " "; cerr << "]"; }
template <typename T> void _print(set <T> v) { cerr << "[ "; for (auto myval : v) cerr << myval << " "; cerr << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cerr << "[ "; for (auto myval : v) cerr << myval.ff << ' ' << myval.ss << " "; cerr << "]"; }
void _print(int a) {cerr << a;}
void _print(ll a) {cerr << a;}
void _print(char a) {cerr << a;}
void _print(string a) {cerr << a;}
void _print(double a) {cerr << a;}
// **`KISS**
 
int solve() {
    int n; cin >> n;
    vector<string> v(n, string(n, '.'));
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		cin >> v[i][j];
    	}
    }
    int in = -1;
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		char ch; cin >> ch;
    		int tt = v[i][j] - '0';
    		tt ^= (ch - '0');
    		v[i][j] = tt + '0';
    		if(v[i][j] == '1') in = i;
    	}
    }
    cout << in << endl;
    // for(int i = 0; i < n; ++i) {
    // 	for(int j = 0; j < n; ++j) cout << v[i][j] << ' ';
    // 	cout << endl;
    // }
    if(in == -1) cout << "YES";
    else {
    	for(int j = 0; j < n; ++j) {
    		swap(v[0][j], v[in][j]);
    	}
	    for(int j = 0; j < n; ++j) {
	    	if(v[0][j] == '1') {
	    		for(int i = 0; i < n; ++i) {
	    			int tt = v[i][j] - '0';
	    			tt ^= 1;
	    			v[i][j] = tt + '0';
	    		}
	    	}
	    }
	    bool flag = true;
	    for(int i = 1; i < n; ++i) {
	    	int c = 0;
	    	for(int j = 0; j < n; ++j) {
	    		c += (v[i][j] == '0');
	    	}
	    	flag &= ((c == 0) || (c == n));
	    }
	    if(flag) cout << "YES";
	    else cout << "NO";
	}
	cout << '\n';
    return 0;
}
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef LOCAL
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef LOCAL
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}
// `Keep It Simple Stupid!
