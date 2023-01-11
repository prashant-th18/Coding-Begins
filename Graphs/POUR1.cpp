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
    int a, b, c; cin >> a >> b >> c;
    if(c > max(a, b) || (c % __gcd(a, b) != 0)) {
    	cout << -1; return 0;
    }
    set<pair<int, int>> st;
    queue<array<int, 3>> q;
    q.push({a, 0, 1});
    q.push({0, b, 1});
    st.insert({a, 0}); st.insert({0, b});
    while(!q.empty()) {
    	array<int, 3> t = q.front(); q.pop();
    	int f = t[0], s = t[1], steps = t[2];
    	
    	if(f == c || s == c) {
    		cout << steps; return 0;
    	}
    	
    	// Empty first
    	if(!st.count({0, s})) {
    		st.insert({0, s});
    		q.push({0, s, steps + 1});
    	}
    	
    	// Empty second
    	if(!st.count({f, 0})) {
    		st.insert({f, 0});
    		q.push({f, 0, steps + 1});
    	}
        
        // Fill first
        if(!st.count({a, s})) {
            st.insert({a, s});
            q.push({a, s, steps + 1});
        }
        
        // Fill second
        if(!st.count({f, b})) {
            st.insert({f, b});
            q.push({f, b, steps + 1});
        }
    	
    	// Pour first to second
    	{
    		int rem = b - s;
            rem = min(rem, f);
            
            int na = f - rem, nb = s + rem;
            if(!st.count({na, nb})) {
                st.insert({na, nb});
                q.push({na, nb, steps + 1});
            }
    	}
        
        // Pour second to first
        {
            int rem = a - f;
            rem = min(rem, s);
            
            int na = f + rem, nb = s - rem;
            if(!st.count({na, nb})) {
                st.insert({na, nb});
                q.push({na, nb, steps + 1});
            }
        }
    }
	return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = true;
	int TET = 1;
    if(test) cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        cout << '\n';
    }
	return 0;
}
// -> Keep It Simple Stupid!