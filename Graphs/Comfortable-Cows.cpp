#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ff first
#define ss second
const int N = 2001;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	int n; cin >> n;
	vector<pii> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i].ff >> v[i].ss;
	for(int i = 0; i < n; ++i) v[i].ff += 1000, v[i].ss += 1000;
	// Shift all co-ordinates by (1000, 1000)
	queue<pii> q;
	int ans = 0;
	vector<vector<bool>> vis(N, vector<bool>(N, false));
	vector<vector<int>> c(N, vector<int>(N, 0));
	for(int i = 0; i < n; ++i) {
		if(vis[v[i].ff][v[i].ss]) {
			--ans;
		}
		else {
			vis[v[i].ff][v[i].ss] = true;
			if(c[v[i].ff][v[i].ss] == 3) {
				q.push({v[i].ff, v[i].ss});
			}
			for(int j = 0; j < 4; ++j) {
				int ni = v[i].ff + dx[j], nj = v[i].ss + dy[j];
				if(valid(ni, nj)) {
					++c[ni][nj];
					if(c[ni][nj] == 3 && vis[ni][nj]) q.push({ni, nj});
				}
			}
		}
		while(!q.empty()) {
			++ans;
			pii p = q.front(); q.pop();
			pii add;
			for(int i = 0; i < 4; ++i) {
				int ni = p.ff + dx[i], p.ss + dy[i];
				if(valid(ni, nj) && !vis[ni][nj]) {
					vis[ni][nj] = true;
					
				}
			}
		}
	}
	return 0;
}