// Link -> https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin >> n;
	int e; cin >> e;
	vector<vector<int>> v(n + 1);
	vector<bool> vis(n + 1, false);
	function<void(int s)> dfs = [&](int s) -> void
	{
		vis[s] = true;
		for(const auto& child : v[s])
		{
			if(!vis[child])
			{
				dfs(child);
			}
		}
	};
	for(int i = 0; i < e; ++i)
	{
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int c = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			++c;
			dfs(i);
		}
	}
	cout << c;
	return 0;
}
