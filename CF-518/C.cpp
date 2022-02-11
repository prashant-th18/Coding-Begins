#include<bits/stdc++.h>
using namespace std;
#define sz(s) (int)s.size()
int main()
{
	int n, m; cin >> n >> m;
	vector<int> color(n + 1, 0);
	vector<vector<int>> v(n + 1);
	for(int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		if(a > b) swap(a, b);
		v[a].push_back(b);
		color[a]++; color[b]++;
	}
	int cnt = 1;
	vector<vector<pair<int, int>>> ind(n + 1);
	for(int i = 1; i <= n; ++i)
	{
		if(color[i] == 0)
		{
			ind[i].push_back(pair(cnt++, i));
		}
		else
		{
			for(int j = 0; j < sz(v[i]); ++j)
			{
				ind[i].push_back(pair(cnt, i));
				ind[v[i][j]].push_back(pair(cnt, v[i][j]));
				++cnt;
			}
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		cout << sz(ind[i]) << '\n';
		for(auto [x, y] : ind[i])
		{
			cout << x << ' ' << y << '\n';
		}
	}
	return 0;
}