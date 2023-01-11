#ifdef LOCAL
	#define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
	int dest = 0;
    vector<int> v(9);
	iota(all(v), 1);
	
	vector<int> p9(9);
	p9[0] = 1;
	for(int i = 1; i < 9; ++i) p9[i] = 9 * p9[i - 1];
		
	vector<bool> vis;
	queue<pair<int, int>> q;
	{
		int num = 0;
		for(int i = 0; i < 9; ++i) num += i * p9[i];
			
		vis.assign(num + 1, false);
		vis[num] = true;
		q.push({num, 0});
	
		num = 0;
		for(int i = 0; i < 9; ++i) cin >> v[i];
		
		for(int i = 0; i < 9; ++i) num += (v[i] - 1) * p9[i];
			
		dest = num;
	}
	
	// cout << dest << endl;
	
	// vector<int> p10(9, 0);
	// p10[0] = 1;
	// for(int i = 1; i < 9; ++i) p10[i] = 10 * p10[i - 1];
	
	auto swaps = [&](int curr, int i, int j) -> int {
		int t1 = (curr / p9[i]) % 9;
		int t2 = (curr / p9[j]) % 9;
		
		curr -= t1 * p9[i];
		curr -= t2 * p9[j];
		
		curr += t2 * p9[i];
		curr += t1 * p9[j];
		// cout << curr << endl;
		return curr;
	};
	
	while(!q.empty()) {
		pair<int, int> p = q.front(); q.pop();
		int curr = p.first, steps = p.second;
		
		if(curr == dest) {
			cout << steps; return 0;
		}
		
		for(int i = 0; i < 9; ++i) {
			if(i % 3 == 2) continue;
			
			// (i, i + 1)
			// So, ek baari i vaali contri htao
			// Ek baari (i + 1) vaali contri htao
			// Fir i ko (i + 1) se replace krdo
			// Aur (i + 1) ko i se replace
			
			int newNum = swaps(curr, i, (i + 1));
			if(!vis[newNum]) {
				vis[newNum] = true;
				q.push({newNum, steps + 1});
			}
		}
		
		for(int i = 0; i < 6; ++i) {
			int newNum = swaps(curr, i, i + 3);
			if(!vis[newNum]) {
				vis[newNum] = true;
				q.push({newNum, steps + 1});
			}
		}
	}
	
	// cout << "Reached";
	
	// Consider the given vector into 1-D vector of size 9
	// Since it's only of size 9, hm kuch 9-base representation mai store krke vector ko bta skte hai
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
	int TET = 1;
    if(test) cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
		#ifdef LOCAL
        	cout << "##################" << '\n';
		#endif

        if (solve()) {
            break;
        }
        cout << '\n';
    }
	#ifdef LOCAL
    	cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
	#endif
	return 0;
}
// -> Keep It Simple Stupid!
