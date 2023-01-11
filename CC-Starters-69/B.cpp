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

bool ok(vector<int>& a, vector<int>& b) {
	bool yes = true;
	for(int i = 0; i < 31; ++i) {
		bool a1 = a[i] > 0;
		bool a2 = b[i] > 0;
		if(a1 == a2) {}
		else yes = false;
		// yes &= ((a[i] > 0) & (b[i] > 0));
	}
	return yes;
}
// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    	
    int maxx = -1;
	vector<int> in(31, 0), out(31, 0);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 31; ++j) {
			if((v[i] >> j) & 1) out[j]++;
		}
	}
	int indis = 0, outdis = 0;
	for(int i = 0; i < 31; ++i) outdis += (out[i] > 0);
		
	int i = 0, j = 0;
	while(j < n && indis <= outdis) {
		for(int k = 0; k < 31; ++k) {
			if((v[j] >> k) & 1) {
				if(in[k] == 0) ++indis;
				
				in[k]++;
				
				if(out[k] == 1) --outdis;
				out[k]--;
				
			}
		}
		
		if(indis > outdis) {
			for(int k = 0; k < 31; ++k) {
				if((v[j] >> k) & 1) {
					if(in[k] == 1) --indis;
					
					in[k]--;
					
					if(out[k] == 0) ++outdis;
					out[k]++;
					
				}
			}
			break;
		}
		++j;
	}
	
	if(indis == outdis && ok(in, out)) maxx = max(maxx, j - i);
	
	while(j < n) {
		for(int k = 0; k < 31; ++k) {
			if((v[j] >> k) & 1) {
				if(in[k] == 0) ++indis;
				
				in[k]++;
				
				if(out[k] == 1) --outdis;
				out[k]--;
				
			}
		}
		
		while(indis > outdis) {
			for(int k = 0; k < 31; ++k) {
				if((v[i] >> k) & 1) {
					if(in[k] == 1) --indis;
					
					in[k]--;
					
					if(out[k] == 0) ++outdis;
					out[k]++;
					
				}
			}
			++i;
		}
		++j;
		if(indis == outdis && ok(in, out)) maxx = max(maxx, j - i);
	}
	cout << maxx;
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
