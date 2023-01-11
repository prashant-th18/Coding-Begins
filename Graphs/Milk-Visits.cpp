#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n, m;
string s; // s = '#' + s
vector<vector<int>> v;
vector<array<int, 2>> value; // value[i][0] -> no. of 'G' from root(1) to this node .....
vector<vector<int>> lca;
vector<int> level;


void dfs(int node, int g, int h, int par, int lvl) {
	level[node] = lvl;
	lca[node][0] = par;
	g += (s[node] == 'G');
	h += (s[node] == 'H');
	value[node] = {g, h};
	for(int & val : v[node]) {
		if(val == par) continue;
		dfs(val, g, h, node, lvl + 1);
	}
}
void init() {
	dfs(0, 0, 0, -1, 0);
	for(int j = 1; j < 30; ++j) {
		for(int i = 1; i <= n; ++i) {
			int par = lca[i][j - 1];
			if(par != -1) lca[i][j] = lca[par][j - 1];
		}
	}
}
int leastCommonAncestor(int x, int y) {
	if(level[x] > level[y]) swap(x, y);

	int dif = level[y] - level[x];
	while(dif > 0) {
		int p = log2(dif);
		y = lca[y][p];
		dif -= (1 << p);
	}

	if(x == y) return x;

	for(int i = 29; i >= 0; --i) {
		if((lca[x][i] != lca[y][i]) && lca[x][i] != -1) {
			x = lca[x][i], y = lca[y][i];
		}
	}
	return lca[x][0];
}

pair<int, int> color(int x, int y) {
	int l = leastCommonAncestor(x, y);
	int g = value[x][0] + value[y][0] - 2 * value[l][0] + (s[l] == 'G');
	int h = value[x][1] + value[y][1] - 2 * value[l][1] + (s[l] == 'H');
	return {g, h};
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = '#' + s;
	v.assign(n + 1, vector<int>());
	value.assign(n + 1, {0, 0});
	lca.assign(n + 1, vector<int>(30, -1));
	level.assign(n + 1, 0);
	v[0].push_back(1);
	v[1].push_back(0);
	for(int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	init();
	string ans = "";
	while(m--) {
		int x, y; cin >> x >> y;
		char ch; cin >> ch;
		pair<int, int> p = color(x, y);
		if(ch == 'G') {
			if(p.ff != 0) ans += "1";
			else ans += "0";
		}
		else {
			if(p.ss != 0) ans += "1";
			else ans += "0";
		}
	}
	cout << ans;
	return 0;
}
