#include<bits/stdc++.h>
using namespace std;
#define sz(s) (int)s.size()
vector<vector<int>> v;
vector<bool> vis;
vector<int> ssize;
int subtree(int node)
{
	int cur_size = 0;
	vis[node] = true;
	for(const auto& val : v[node])
	{
		if(!vis[val])
		{
			cur_size += subtree(val);
		}
	}
	ssize[node] = cur_size;
	return 1 + cur_size;
}
int main()
{
	int n; cin >> n;
	v = vector<vector<int>>(n + 1);
	vis.assign(n + 1, false);
	ssize.assign(n + 1, 0);
	for(int i = 0; i < n - 1; ++i)
	{
		int a; cin >> a;
		v[a].push_back(i + 2);
		v[i + 2].push_back(a);
	}
	subtree(1);
	for(int i = 1; i <= n; ++i)
	{
		cout << ssize[i] << ' ';
	}
    return 0;
}

