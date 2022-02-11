#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*
vector<vector<int>> v;
vector<bool> vis;
vector<int> dp;
vector<int> topo; // topological Sort
vector<int> in;
void topo_sort(int n)
{
	queue<int> q;
	for(int i = 1; i <= n; ++i)
	{
		if(in[i] == 0) q.push(i);
	}
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		topo.push_back(f);
		for(const auto& val : v[f])
		{
			--in[val];
			if(in[val] == 0) q.push(val);
		}
	}
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
		int n, m; cin >> n >> m;
		v = vector<vector<int>>(n + 1);
		vis.assign(n + 1, false);
		in.assign(n + 1, 0);
		dp.assign(n + 1, 0);
		for(int i = 0; i < m; ++i)
		{
			int a, b; cin >> a >> b;
			v[a].push_back(b);
			++in[b];
		}
		topo_sort(n);
		int index = -1;
		for(int i = sz(topo) - 1; i >= 0; --i)
		{
			if(topo[i] == n)
			{
				dp[n] = 1;
				index = i; 
				break;
			}
			else dp[topo[i]] = 0;
		}
		for(int i = index - 1; i >= 0; --i)
		{
			for(const auto& val : v[topo[i]])
			{
				dp[topo[i]] = (dp[topo[i]] + dp[val]) % MOD;
			}
		}
		cout << dp[1];
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!

