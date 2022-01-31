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
void solve()
{
	ll n;
	cin >> n;
	map<ll, ll> mp;
	ll cnt = 0; // cnt is original
	for (auto val : {2, 3, 5})
	{
		while (n % val == 0)
		{
			++mp[val];
			n /= val;
		}
	}
	static array<ll, 8> inc{4, 2, 4, 2, 4, 6, 2, 6};
	int k = 0;
	for (ll i = 7; i * i <= n; i += inc[k++])
	{
		if (k == 8)
		{
			k = 0;
		}
		while (n % i == 0)
		{
			++mp[i];
			n /= i;
		}
	}
	if (n > 1)
	{
		++mp[n];
	}
	ll maxx = LLONG_MIN;
	ll mynum = 1;
	for (auto val : mp)
	{
		mynum *= val.ff;
		maxx = MAX(maxx, val.ss);
	}
	ll my_i = 0;
	fl(i, 0, 62)
	{
		if ((1LL << i) >= maxx)
		{
			my_i = i;
			break;
		}
	}
	for (auto val : mp)
	{
		if ((1 << my_i) - val.ss > 0)
		{
			++cnt;
			break;
		}
	}
	cnt += my_i;
	cout << mynum << space << cnt;
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